//---------------------------------------------------------------------------
// DISPLAYCOMMAND.H
// Class DisplayCommand (for displaying inventory of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// DisplayCommand class: executes a display inventory command
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#ifndef DisplayCommand_h
#define DisplayCommand_h

#include <stdio.h>
#include "Command.h"
#include "Store.h"

class DisplayCommand : public Command {
    
public:
    //-------------------------- Constructor -----------------------------
    // Default Constructor for DisplayCommand
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    DisplayCommand();
    
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

#endif /* DisplayCommand_h */
