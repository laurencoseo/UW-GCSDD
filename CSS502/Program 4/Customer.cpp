//---------------------------------------------------------------------------
// CUSTOMER.CPP
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

#include "Customer.h"

//------------------------- Constructor -----------------------------
// Default constructor for Customer
// Preconditions:   None
// Postconditions:  Data members set to default
Customer::Customer() {
    setKey(0);
    name = "";
    // vector of transaction log
}

//------------------------- Constructor -----------------------------
// Constructor for Customer
// Preconditions:   None
// Postconditions:  Data members set to parameters
Customer::Customer(int idNum, string custName) {
    setKey(idNum);
    name = custName;
}

//------------------------- Destructor ------------------------------
// Destructor for class Customer
// Preconditions:   Customer points to memory on the heap
// Postconditions:  Customer is emptied and deallocated
Customer::~Customer() {
    long size = transactionLog.size();
    for (long i = size - 1; i >= 0; i--) {
        // Printing each element of the vector
         delete transactionLog[i];
    }
}

//---------------------------- addTransaction --------------------------------
// Inserts a Transaction to the end of the customer's transaction list
// Preconditions:   None
// Postconditions:  Transaction added
void Customer::addTransaction(Transaction* t) {
    transactionLog.push_back(t);
}

//---------------------------- getTransactions -----------------------------
// Gets the size of the transaction log vector of a customer
// Preconditions:   None
// Postconditions:  Returns the size of the transaction vector
long Customer::getTransactions() const {
    return transactionLog.size();
}

//-----------------------------  <  ------------------------------------
// Determine if one Customer is less than another Customer
// Preconditions:   None
// Postconditions:  true is returned if this Customer's attributes are
//                  less than rhs's attributes, false is returned otherwise
bool Customer::operator<(const Comparable& rhs) const {
    // Cast the Comparable to a Customer
    const Customer &rhsCust = static_cast<const Customer &>(rhs);
    
    return name < rhsCust.name;
}

//-----------------------------  >  ------------------------------------
// Determine if one Customer is greater than another Customer
// Preconditions:   None
// Postconditions:  true is returned if this Customer's attributes are
//                  greater than rhs's attributes,
//                  false is returned otherwise
bool Customer::operator>(const Comparable& rhs) const {
    // Cast the Comparable to a Customer
    const Customer &rhsCust = static_cast<const Customer &>(rhs);
    
    return name > rhsCust.name;
}

//----------------------------  ==  ------------------------------------
// Determine if one Customer is equal to another Customer
// Preconditions:   None
// Postconditions:  true is returned if this Customer's attributes are
//                  equal to rhs's attributes, false is returned otherwise
bool Customer::operator==(const Comparable& rhs) const {
    // Cast the Comparable to a Customer
    const Customer &rhsCust = static_cast<const Customer &>(rhs);
    
    return name == rhsCust.name;
}

//----------------------------  !=  ------------------------------------
// Determine if one Customer is not equal to another Customer
// Preconditions:   None
// Postconditions:  true is returned if this Customer's attributes are not
//                  equal to rhs's attributes, false is returned otherwise
bool Customer::operator!=(const Comparable& rhs) const {
    return !(this == &rhs);
}

//----------------------------  print  ------------------------------------
// Helper Method - Prints the Customer to the ostream
// Preconditions:   None
// Postconditions:  Prints the attributes and transactions of a Customer
void Customer::print(ostream& output) const {
    output << name << endl;
    for (int i = 0; i < transactionLog.size(); i++) {
        // Printing each element of the vector
        output << transactionLog[i] << endl;
    }
}
