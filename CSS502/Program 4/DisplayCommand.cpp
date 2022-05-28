//---------------------------------------------------------------------------
// DISPLAYCOMMAND.CPP
// Class DisplayCommand (for displaying inventory of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// DisplayCommand class: executes a display inventory command
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#include "DisplayCommand.h"

//-------------------------- Constructor -----------------------------
// Default Constructor for DisplayCommand
// Preconditions:   None
// Postconditions:  Data members set to parameters
DisplayCommand::DisplayCommand() {
    setKey('D');
}

//--------------------------  execute  ---------------------------------
// Executes the method specified
// Preconditions:   None
// Postconditions:  Returns true if executed, false if not
bool DisplayCommand::execute(Store* store) const {
    store->display();
    return true;
}

//--------------------------  create  ----------------------------------
// Create a new instance of a DisplayCommand object, to be used by a factory
// Preconditions:   None
// Postconditions:  A new DisplayCommand object is created
Command* DisplayCommand::create(string s) const {
    // return a new DisplayCommand object
    DisplayCommand* newCommand = new DisplayCommand();
    return newCommand;
}
