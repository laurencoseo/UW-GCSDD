//---------------------------------------------------------------------------
// TRANSACTION.H
// Class Transaction (for buy/sell transactions of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// Transaction class:  creates a Transaction object with a type, customer ID,
//                     and Collectible item
//   -- allows for output of a Transaction
//   -- allows for creation of a Transaction
//   -- allows for deletion of a Transaction
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#ifndef Transaction_h
#define Transaction_h

#include <stdio.h>
#include <ctime>
#include "Collectible.h"

class Transaction {
    
    //-----------------------------  <<  --------------------------------------
    // Overloaded output operator for class Transaction
    // Preconditions:   None
    // Postconditions:  Transactions's attributes are sent to the
    //                  output istream
    friend ostream& operator<<( ostream& output, const Transaction& t);
    
private:
    int customerID;             // ID for customer who made transaction
    Collectible* item;          // item exchanged in transaction
    char type;                  // B for Buy, S for Sell
    
public:
    //-------------------------- Constructor -----------------------------
    // Default constructor for Transaction
    // Preconditions:   None
    // Postconditions:  Data members set to default
    Transaction();
    
    //-------------------------- Constructor -----------------------------
    // Constructor for Transaction
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    Transaction(int custID, Collectible& c, char actionType);
    
    //---------------------------- Destructor --------------------------------
    // Destructor for class Transaction
    // Preconditions:   Transaction points to memory on the heap
    // Postconditions:  Transaction is emptied and deallocated
    virtual ~Transaction() {}
    
};

#endif /* Transaction_h */
