//
//  Shop.cpp
//
//  Author: Lauren Coseo
//

#include "Shop.h"

/* -----------------------------------------------------------------------------
 * Shop constructor
 * description: Creates Shop object with inputted # of barbers & chairs
 * pre:  None
 * post: None
 -----------------------------------------------------------------------------*/
Shop::Shop(int num_barbers, int num_chairs) :
    nChairs_(num_chairs), nBarbers_(num_barbers), cust_drops_(0)
{
    init();
};

/* -----------------------------------------------------------------------------
 * Shop default constructor
 * description: Creates Shop object with default barbers & chairs
 * pre:  None
 * post: None
 -----------------------------------------------------------------------------*/
Shop::Shop() : nChairs_(kDefaultNumChairs), nBarbers_(kDefaultNumBarbers),
    cust_drops_(0)
{
    init();
};

/* -----------------------------------------------------------------------------
 * Shop Destructor
 * description: Destroys a Shop object
 * pre:  None
 * post: None
 -----------------------------------------------------------------------------*/
Shop::~Shop() {
    delete[] barbers_;
}

/* -----------------------------------------------------------------------------
 * init
 * description: initializes mutex locks and conditions
 * pre:  None
 * post: All locks and conditions are initialized
 -----------------------------------------------------------------------------*/
void Shop::init()
{
    barbers_ = new Barber[nBarbers_];
    
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init(&cond_customers_waiting_, NULL);
    
    for (int i = 0; i < nBarbers_; i++) {
        sleeping_barbers_.push(i);
        
        // initialize all condition arrays for barber
        pthread_cond_init(&barbers_[i].cond_customer_served_, NULL);
        pthread_cond_init(&barbers_[i].cond_barber_paid_, NULL);
        pthread_cond_init(&barbers_[i].cond_barber_sleeping_, NULL);
    }
}

/* -----------------------------------------------------------------------------
 * int2string
 * description: converts a long to a string
 * pre:  None
 * post: Returns a string
 -----------------------------------------------------------------------------*/
string Shop::int2string(long i)
{
    stringstream out;
    out << i;
    return out.str( );
}

/* -----------------------------------------------------------------------------
 * print
 * description: prints either a customer's or barber's id
 * pre:  None
 * post: Prints out id and a message
 -----------------------------------------------------------------------------*/
void Shop::print(int person, string message)
{
    cout << ((person > 0) ? "customer[" : "barber  [" ) << abs(person)
         << "]: " << message << endl;
}

/* -----------------------------------------------------------------------------
 * get_cust_drops
 * description: getter function for the private cust_drops_ variable
 * pre:  None
 * post: Returns an int
 -----------------------------------------------------------------------------*/
int Shop::get_cust_drops() const
{
    return cust_drops_;
}

/* -----------------------------------------------------------------------------
 * visitShop
 * description: function for customer thread when entering shop
 * pre:  None
 * post: Customer either leaves or receives service
 -----------------------------------------------------------------------------*/
int Shop::visitShop(int id)
{
    pthread_mutex_lock(&mutex_);
    
    // If all chairs are full, customer leaves shop
    if (waiting_chairs_.size() == nChairs_)
    {
        print(id,"leaves the shop because of no available waiting chairs.");
        ++cust_drops_;
        pthread_mutex_unlock(&mutex_);
        return -1;
    }
   
    // If there are no barbers available, but there are waiting chairs
    if (sleeping_barbers_.empty() || !waiting_chairs_.empty())
    {
        waiting_chairs_.push(id);
        print(id, "takes a waiting chair. # waiting seats available = " +
             int2string(nChairs_ - waiting_chairs_.size()));
        
        while (sleeping_barbers_.empty()) {
            pthread_cond_wait(&cond_customers_waiting_, &mutex_);
        }
        waiting_chairs_.pop();
    }
    
    int barber_id = sleeping_barbers_.front();
    sleeping_barbers_.pop();
    
    print(id, "moves to the service chair["
        + int2string(barber_id) + "]. # waiting seats available = "
        + int2string(nChairs_ - waiting_chairs_.size()));

    barbers_[barber_id].customer_in_chair_ = id;
    barbers_[barber_id].in_service_ = true;

    // wake up the barber just in case if he is sleeping
    pthread_cond_signal(&barbers_[barber_id].cond_barber_sleeping_);

    pthread_mutex_unlock(&mutex_);
    return barber_id;
}

/* -----------------------------------------------------------------------------
 * leaveShop
 * description: function for customer thread when done with service
 * pre:  None
 * post: Customer receives service and leaves
 -----------------------------------------------------------------------------*/
void Shop::leaveShop(int cust_id, int barber_id)
{
    pthread_mutex_lock( &mutex_ );

    // Wait for service to be completed
    print(cust_id, "wait for barber[" + int2string(barber_id)
          + "] to be done with hair-cut");
    while (barbers_[barber_id].in_service_ == true)
    {
        pthread_cond_wait(&barbers_[barber_id].cond_customer_served_, &mutex_);
    }
   
    // Pay the barber and signal barber appropriately
    barbers_[barber_id].money_paid_ = true;
    pthread_cond_signal(&barbers_[barber_id].cond_barber_paid_);
    print(cust_id, "says good-bye to barber["
          + int2string(barber_id) + "]");
    pthread_mutex_unlock(&mutex_);
}

/* -----------------------------------------------------------------------------
 * helloCustomer
 * description: function for barber thread when customer enters
 * pre:  None
 * post: Barber sleeps or serves a customer
 -----------------------------------------------------------------------------*/
void Shop::helloCustomer(int id)
{
    pthread_mutex_lock(&mutex_);
   
    // If no customers, barber can sleep
    if (waiting_chairs_.empty() && barbers_[id].customer_in_chair_ == 0 )
    {
        print(-id, "sleeps because of no customers.");
    }

    while (barbers_[id].customer_in_chair_ == 0)   // check if customer sat down
    {
        pthread_cond_wait(&barbers_[id].cond_barber_sleeping_, &mutex_);
    }
    
    print(-id, "starts a hair-cut service for customer["
          + int2string(barbers_[id].customer_in_chair_) + "]");
    pthread_mutex_unlock( &mutex_);
}

/* -----------------------------------------------------------------------------
 * byeCustomer
 * description: function for barber thread when service is done
 * pre:  None
 * post: Barber is paid and calls another customer
 -----------------------------------------------------------------------------*/
void Shop::byeCustomer(int id)
{
    pthread_mutex_lock(&mutex_);

    // Hair Cut-Service is done so signal customer and wait for payment
    print(-id, "says he's done with a hair-cut service for customer["
          + int2string(barbers_[id].customer_in_chair_) + "]");
    barbers_[id].money_paid_ = false;
    barbers_[id].in_service_ = false;
    pthread_cond_signal(&barbers_[id].cond_customer_served_);
    while (barbers_[id].money_paid_ == false)
    {
        pthread_cond_wait(&barbers_[id].cond_barber_paid_, &mutex_);
    }

    //Signal to customer to get next one
    barbers_[id].customer_in_chair_ = 0;
    sleeping_barbers_.push(id);
    print(-id, "calls in another customer");
    pthread_cond_signal(&cond_customers_waiting_);

    pthread_mutex_unlock( &mutex_);  // unlock
}
