//---------------------------------------------------------------------------
// BUYCOMMAND.CPP
// Class BuyCommand (for buy transactions of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// BuyCommand class: executes a buy transaction of a customer from an
//                   input string
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#include "BuyCommand.h"

//-------------------------- Constructor -----------------------------
// Default Constructor for BuyCommand
// Preconditions:   None
// Postconditions:  Data members set to parameters
BuyCommand::BuyCommand() {
    customerID = 0;
    item = nullptr;
    setKey('B'); 
}

//-------------------------- Constructor -----------------------------
// Constructor for BuyCommand
// Preconditions:   None
// Postconditions:  Data members set to parameters
BuyCommand::BuyCommand(int custID, Collectible* currItem) {
    // initialize data members with the parameters
    customerID = custID;
    item = currItem;
    setKey('B');
}

//--------------------------  create  ----------------------------------
// Create a new instance of a BuyCommand object, to be used by a factory
// Preconditions:   None
// Postconditions:  A new BuyCommand object is created
Command* BuyCommand::create(string s) const {
    vector<string> splitString;
    
    stringstream stringstrm (s);
    string substr;

    while (getline(stringstrm, substr, ',')) {
        splitString.push_back(substr);
    }

//    int custID = stoi(splitString[0].c_str());
//    string itemInfo = splitString[1];
//
//    BuyCommand* newBuy(custID, how to get item?);
//
//    return newBuy;
    return nullptr;
}

//--------------------------  execute  ---------------------------------
// Executes the method specified
// Preconditions:   None
// Postconditions:  Returns true if executed, false if not
bool BuyCommand::execute(Store* store) const {
    // run the Store's buy method with the needed parameters
    bool success = store->buy(customerID, *item);
    return success;
}
