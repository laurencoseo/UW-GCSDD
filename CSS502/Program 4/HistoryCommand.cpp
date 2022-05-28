//---------------------------------------------------------------------------
// HISTORYCOMMAND.CPP
// Class HistoryCommand (for displaying all customers' transactions)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// HistoryCommand class: executes a command to print all customers' transactions
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#include "HistoryCommand.h"

//-------------------------- Constructor -----------------------------
// Default Constructor for HistoryCommand
// Preconditions:   None
// Postconditions:  Data members set to parameters
HistoryCommand::HistoryCommand() {
    setKey('H');
}

//--------------------------  execute  ---------------------------------
// Executes the method specified
// Preconditions:   None
// Postconditions:  Returns true if executed, false if not
bool HistoryCommand::execute(Store* store) const {
    store->history();
    return true;
}

//--------------------------  create  ----------------------------------
// Create a new instance of a HistoryCommand object, to be used by a factory
// Preconditions:   None
// Postconditions:  A new HistoryCommand object is created
Command* HistoryCommand::create(string s) const {
    // return a new Coin object
    HistoryCommand* newCommand = new HistoryCommand();
    return newCommand;
}
