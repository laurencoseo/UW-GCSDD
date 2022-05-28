//---------------------------------------------------------------------------
// STORE.CPP
// Class Store (holds the different parts of a store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// Store class:  creates a Store object with with an inventory, customer list
//               by ID, and customer list by name
//   -- allows for all command types of the store (buy, sell, display,
//      customer, and history)
//   -- allows for reading in file and creating inventory, adding customers,
//      and running commands
//
// Notes:
//   -- For stores with collectible items
//   -- For stores with customer IDs between 1-999
//---------------------------------------------------------------------------

#include "Store.h"
#include "CommandFactory.h"

//----------------------- Constructor -------------------------------
// Default constructor for Store
// Preconditions:   None
// Postconditions:  Data members set to default
Store::Store() {
    //customersByName search tree
    customersByName = SearchTree();
    
    // 1000 for size of customersByID
    customersByID = HashTable(1000);
    
    // set up inventory
    inventory = Inventory();
}

//---------------------- buildInventory -----------------------------
// Method to build a Store's inventory of items from a file
// Preconditions:   None
// Postconditions:  New items are created and added to the inventory
void Store::buildInventory(ifstream& infile) {
    inventory.build(infile);
}

//----------------------- buildCustomerList -------------------------
// Method to build a Store's customer list of items from a file
// Preconditions:   None
// Postconditions:  New customers are created and added to customer lists
void Store::buildCustomerList(ifstream& infile) {
    while(infile.peek() != EOF) {
        string fileInput;
        getline(infile, fileInput);

        stringstream inputStream(fileInput);
        string temp;
        
        int custID;
        getline(inputStream, temp, ',');
        custID = atoi(temp.c_str());
        
        // check that customer ID is valid
        if (custID >= 0 && custID < Customer::NUM_CUSTOMERS) {
            string custName;
            getline(inputStream, temp, ',');
            custName = temp;
            Customer* newCustomer = new Customer(custID, custName);
            
            customersByName.insert(newCustomer);
            customersByID.add(newCustomer);
        } else {
            cout << custID << " is not a valid ID." << endl;
        }
    }
}

//----------------------------- buy ----------------------------------
// Simulates a buy action, including adding the transaction and
// updating the inventory
// Preconditions:   None
// Postconditions:  New transaction and stock items are added
bool Store::buy(int custID, Collectible& item, char ch) {
    // create a new Transaction
    Transaction* t = new Transaction(custID, item, ch);
    
    // add Transaction to the customer's transaction list
    HashableItem* c = customersByID.getItem(custID);
    Customer* cust = static_cast<Customer*>(c);
    cust->addTransaction(t);
    
    // add to inventory
    inventory.addItem(&item);

    return true;
}

//----------------------------- sell ----------------------------------
// Simulates a sell action, including adding the transaction and
// updating the inventory
// Preconditions:   None
// Postconditions:  New transaction are added and stock items are updated
bool Store::sell(int custID, Collectible& item, char ch) {
    // create a new Transaction
    Transaction* t = new Transaction(custID, item, ch);
    
    // add Transaction to the customer's transaction list
    HashableItem* c = customersByID.getItem(custID);
    Customer* cust = static_cast<Customer*>(c);
    cust->addTransaction(t);
    
    // remove from inventory
    inventory.removeItem(&item);
    
    return true;
}

//----------------------------- display --------------------------------
// Displays the store's entire inventory
// Preconditions:   None
// Postconditions:  Inventory is outputted in the order of Coin, Comic
//                  Book, SportsCard
void Store::display() {
    // print the inventory using the inventory's display method
    inventory.display();
}

//----------------------------- customer --------------------------------
// Displays a customer's transaction log
// Preconditions:   None
// Postconditions:  Transactions are outputted one line at a time
void Store::customer(int custID) {
    // find customer with custID in hash table customersByID
    HashableItem* c = customersByID.getItem(custID);
    Customer* cust = static_cast<Customer*>(c);
    // check if customer exists
    if (cust == nullptr) {
        cout << "There is no customer with ID: " << custID << endl;
    }
    // display the customer's transactions
    else {
        if (cust->getTransactions() == 0) {
            cout << "Customer has no transactions" << endl;
        } else {
            cout << cust;
        }
    }
}

//----------------------------- history --------------------------------
// Displays every customers' transaction log
// Preconditions:   None
// Postconditions:  Transactions are outputted one line at a time, with
//                  customers in alphabetical order
void Store::history() {
    // traverse through the customersByName list and print the transactions
    cout << customersByName;
}
