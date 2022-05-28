//---------------------------------------------------------------------------
// CUSTOMER.H
// Class Customer (for customers of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// Customer class:  creates a Customer object with with an array of Binary
//                   Search Trees holding coins, comics, and sports cards
//   -- allows for output of Customer's transactions
//   -- allows for comparison of 2 Customers
//   -- allows for adding a transaction to a Customer's log
//
// Notes:
//   -- Allows for name to be first and last name or just first name
//---------------------------------------------------------------------------

#ifndef Customer_h
#define Customer_h

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Transaction.h"
#include "Comparable.h"
#include "HashableItem.h"
using namespace std;

class Customer : public HashableItem, public Comparable {
    
public:
    static const int NUM_CUSTOMERS = 1000;
    
    //------------------------- Constructor -----------------------------
    // Default constructor for Customer
    // Preconditions:   None
    // Postconditions:  Data members set to default
    Customer();
    
    //------------------------- Constructor ------------------------------------
    // Constructor for Customer
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    Customer(int idNum, string custName);
    
    //------------------------- Destructor -------------------------------------
    // Destructor for class Customer
    // Preconditions:   Customer points to memory on the heap
    // Postconditions:  Customer is emptied and deallocated
    ~Customer();
    
    //---------------------------- addTransaction ------------------------------
    // Inserts a Transaction to the end of the customer's transaction list
    // Preconditions:   None
    // Postconditions:  Transaction added
    void addTransaction(Transaction* t);
    
    //---------------------------- getTransactions -----------------------------
    // Gets the size of the transaction log vector of a customer
    // Preconditions:   None
    // Postconditions:  Returns the size of the transaction vector
    long getTransactions() const;
    
    //-----------------------------  <  ----------------------------------------
    // Determine if one Customer is less than another Customer
    // Preconditions:   None
    // Postconditions:  true is returned if this Customer's attributes are
    //                  less than rhs's attributes, false is returned otherwise
    virtual bool operator<(const Comparable& rhs) const;
    
    //-----------------------------  >  ------------------------------------
    // Determine if one Customer is greater than another Customer
    // Preconditions:   None
    // Postconditions:  true is returned if this Customer's attributes are
    //                  greater than rhs's attributes,
    //                  false is returned otherwise
    virtual bool operator>(const Comparable& rhs) const;
    
    //----------------------------  ==  ------------------------------------
    // Determine if one Customer is equal to another Customer
    // Preconditions:   None
    // Postconditions:  true is returned if this Customer's attributes are
    //                  equal to rhs's attributes, false is returned otherwise
    virtual bool operator==(const Comparable& rhs) const;
    
    //----------------------------  !=  ------------------------------------
    // Determine if one Customer is not equal to another Customer
    // Preconditions:   None
    // Postconditions:  true is returned if this Customer's attributes are not
    //                  equal to rhs's attributes, false is returned otherwise
    virtual bool operator!=(const Comparable& rhs) const;
    
    //----------------------------  print  ------------------------------------
    // Helper Method - Prints the Customer to the ostream
    // Preconditions:   None
    // Postconditions:  Prints the attributes and transactions of a Customer
    virtual void print(ostream& output) const;
    
private:
    string name;                        // First and last name (if provided)
    vector<Transaction*> transactionLog; // vector of Transactions
};
#endif /* Customer_h */
