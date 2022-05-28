//
//  Shop.h
//
//  Author: Lauren Coseo
//

#ifndef SHOP_H_
#define SHOP_H_
#include <pthread.h>        // the header file for the pthread library
#include <iostream>
#include <sstream>
#include <string>
#include <queue>            // the STL library: queue
#include <vector>           // the STL library: vector
using namespace std;

#define kDefaultNumChairs 3     // the default num of chairs for waiting = 3
#define kDefaultNumBarbers 1    // the default num of barbers = 1

class Shop {
    
public:
    Shop(int num_barbers, int num_chairs); // a Shop with n barbers, n chairs
    Shop();                 // initialize a Shop object with 1 barber, 3 chairs
    virtual ~Shop();

    int visitShop(int id);              // return barber ID or -1 (not served)
    void leaveShop(int cust_id, int barber_id);
    void helloCustomer(int id);
    void byeCustomer(int id);
    int get_cust_drops() const;

private:
    struct Barber {
        int customer_in_chair_ = 0;
        bool in_service_ = false;
        bool money_paid_ = false;
        pthread_cond_t cond_customer_served_;
        pthread_cond_t cond_barber_paid_;
        pthread_cond_t cond_barber_sleeping_;
    };
    
    const int nChairs_;               // the max number of threads that can wait
    const int nBarbers_;              // # of barbers in Shop
    queue<int> waiting_chairs_;       // includes the ids of all waiting threads
    int cust_drops_;                  // # of customers who left w/o service
    queue<int> sleeping_barbers_;    // includes ids of barbers not in service
    Barber* barbers_;                 // all barbers and their states

    // Mutexes and condition variables to coordinate threads
    // mutex_ is used in conjuction with all conditional variables
    pthread_mutex_t mutex_;
    pthread_cond_t  cond_customers_waiting_;
  
    void init();
    string int2string(long i);
    void print(int person, string message);
};
#endif
