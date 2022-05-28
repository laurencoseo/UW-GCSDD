//---------------------------------------------------------------------------
// CUSTOMERCOMMAND.CPP
// Class CustomerCommand (for displaying a customer's transactions)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// CustomerCommand class: executes a command to print a customer's transactions
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#include "CustomerCommand.h"

//-------------------------- Constructor -----------------------------
// Default Constructor for CustomerCommand
// Preconditions:   None
// Postconditions:  Data members set to parameters
CustomerCommand::CustomerCommand() {
    setKey('C');
}

//-------------------------- Constructor -----------------------------
// Constructor for CustomerCommand
// Preconditions:   None
// Postconditions:  Data members set to parameters
CustomerCommand::CustomerCommand(int custID) : customerID(custID) {

}

//--------------------------  execute  ---------------------------------
// Executes the method specified
// Preconditions:   None
// Postconditions:  Returns true if executed, false if not
bool CustomerCommand::execute(Store* store) const {
    store->customer(customerID);
    return true;
}

//--------------------------  create  ----------------------------------
// Create a new instance of a CustomerCommand object, to be used by a factory
// Preconditions:   None
// Postconditions:  A new CustomerCommand object is created
Command* CustomerCommand::create(string s) const {
    int custID = stoi(s.c_str());
    CustomerCommand* newCommand = new CustomerCommand(custID);
    return newCommand;
}
