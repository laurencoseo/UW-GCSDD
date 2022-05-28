//---------------------------------------------------------------------------
// STORE.H
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

#ifndef Store_h
#define Store_h

#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Inventory.h"

class Store {
    
private:
    Inventory inventory;                // store's entire inventory
    HashTable customersByID;            // table of store's customers by ID
    SearchTree customersByName;         // list of store's customers by name
    
public:
    //----------------------- Constructor -------------------------------
    // Default constructor for Store
    // Preconditions:   None
    // Postconditions:  Data members set to default
    Store();
    
    //---------------------------- Destructor --------------------------------
    // Destructor for class Store
    // Preconditions:   Store points to memory on the heap
    // Postconditions:  Store is emptied and deallocated
    virtual ~Store() {}
    
    //---------------------- buildInventory -----------------------------
    // Method to build a Store's inventory of items from a file
    // Preconditions:   None
    // Postconditions:  New items are created and added to the inventory
    void buildInventory(ifstream& infile);
    
    //----------------------- buildCustomerList -------------------------
    // Method to build a Store's customer list of items from a file
    // Preconditions:   None
    // Postconditions:  New customers are created and added to customer lists
    void buildCustomerList(ifstream& infile);
    
//    //-------------------------- runCommands -----------------------------
//    // Method to run commands given by a file
//    // Preconditions:   None
//    // Postconditions:  Commands are executed if matched to a method
//    void runCommands(ifstream& infile);
    
    //----------------------------- buy ----------------------------------
    // Simulates a buy action, including adding the transaction and
    // updating the inventory
    // Preconditions:   None
    // Postconditions:  New transaction and stock items are added
    bool buy(int custID, Collectible& item, char ch = 'B');

    //----------------------------- sell ----------------------------------
    // Simulates a sell action, including adding the transaction and
    // updating the inventory
    // Preconditions:   None
    // Postconditions:  New transaction are added and stock items are updated
    bool sell(int custID, Collectible& item, char ch = 'S');
    
    //----------------------------- display --------------------------------
    // Displays the store's entire inventory
    // Preconditions:   None
    // Postconditions:  Inventory is outputted in the order of Coin, Comic
    //                  Book, SportsCard
    void display();
    
    //----------------------------- customer --------------------------------
    // Displays a customer's transaction log
    // Preconditions:   None
    // Postconditions:  Transactions are outputted one line at a time
    void customer(int custID);
    
    //----------------------------- history --------------------------------
    // Displays every customers' transaction log
    // Preconditions:   None
    // Postconditions:  Transactions are outputted one line at a time, with
    //                  customers in alphabetical order
    void history();
};

#endif /* Store_h */
