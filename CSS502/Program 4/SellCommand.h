//---------------------------------------------------------------------------
// SELLCOMMAND.H
// Class SellCommand (for sell transactions of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// SellCommand class: executes a sell transaction of a customer from an
//                   input string
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#ifndef SellCommand_h
#define SellCommand_h

#include <stdio.h>
#include "Command.h"
#include "Store.h"

class SellCommand : public Command {
    
private:
    int customerID;             // customer's unqiue key (0-999)
    Collectible* item;          // item being sold
    
public:
    //-------------------------- Constructor -----------------------------
    // Default Constructor for SellCommand
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    SellCommand();
    
    //-------------------------- Constructor -----------------------------
    // Constructor for SellCommand
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    SellCommand(int custID, Collectible* currItem);
    
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

#endif /* SellCommand_h */
