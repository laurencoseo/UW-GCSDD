//---------------------------------------------------------------------------
// SELLCOMMAND.CPP
// Class SellCommand (for sell transactions of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// SellCommand class: executes a sell transaction of a customer from an
//                   input string
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#include "SellCommand.h"

//-------------------------- Constructor -----------------------------
// Default Constructor for SellCommand
// Preconditions:   None
// Postconditions:  Data members set to parameters
SellCommand::SellCommand() {
    setKey('S');
}

//-------------------------- Constructor -----------------------------
// Constructor for SellCommand
// Preconditions:   None
// Postconditions:  Data members set to parameters
SellCommand::SellCommand(int custID, Collectible* currItem) :
        customerID(custID), item(currItem) {
    setKey('S');
}


//--------------------------  execute  ---------------------------------
// Executes the method specified
// Preconditions:   None
// Postconditions:  Returns true if executed, false if not
bool SellCommand::execute(Store* store) const {
    store->sell(customerID, *item);
    return true;
}

//--------------------------  create  ----------------------------------
// Create a new instance of a SellCommand object, to be used by a factory
// Preconditions:   None
// Postconditions:  A new SellCommand object is created
Command* SellCommand::create(string s) const {
    vector<string> splitString;
    
    stringstream stringstrm (s);
    string substr;

    while (getline(stringstrm, substr, ',')) {
        splitString.push_back(substr);
    }

    //    int custID = stoi(splitString[0].c_str());
    //    string itemInfo = splitString[1];
    //
    //    SellCommand* newSell(custID, how to get item?);
    //
    //    return newSell;
    return nullptr;
}
