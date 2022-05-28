//---------------------------------------------------------------------------
// HISTORYCOMMAND.H
// Class HistoryCommand (for displaying all customers' transactions)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// HistoryCommand class: executes a command to print all customers' transactions
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#ifndef HistoryCommand_h
#define HistoryCommand_h

#include <stdio.h>
#include "Command.h"
#include "Store.h"

class HistoryCommand : public Command {
    
public:
    //-------------------------- Constructor -----------------------------
    // Default Constructor for HistoryCommand
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    HistoryCommand();
    
    //--------------------------  create  ----------------------------------
    // Create a new instance of a Command object, to be used by a factory
    // Preconditions:   None
    // Postconditions:  A new Command object is created
    virtual Command* create(string s) const;
    
    //--------------------------  execute  ---------------------------------
    // Executes the method specified
    // Preconditions:   None
    // Postconditions:  Returns true if executed, false if not
    virtual bool execute(Store* store) const;
};

#endif /* HistoryCommand_h */
