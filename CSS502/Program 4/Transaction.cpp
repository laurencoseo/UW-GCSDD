//---------------------------------------------------------------------------
// TRANSACTION.CPP
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

#include "Transaction.h"

//-------------------------- Constructor -----------------------------
// Default constructor for Transaction
// Preconditions:   None
// Postconditions:  Data members set to default
Transaction::Transaction() {
    customerID = 0;
    type = '\0';
    item = nullptr;
}

//-------------------------- Constructor -----------------------------
// Constructor for Transaction
// Preconditions:   None
// Postconditions:  Data members set to parameters
Transaction::Transaction(int custID, Collectible& c, char actionType) {
    customerID = custID;
    item = &c;
    type = actionType;
}

//-----------------------------  <<  --------------------------------------
// Overloaded output operator for class Transaction
// Preconditions:   None
// Postconditions:  Transactions's attributes are sent to the
//                  output istream
ostream& operator<<( ostream& output, const Transaction& t) {
    output << t.type << " " << t.customerID << " " << t.item << endl;
    return output;
}
