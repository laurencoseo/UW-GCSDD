//---------------------------------------------------------------------------
// CUSTOMERCOMMAND.H
// Class CustomerCommand (for displaying a customer's transactions)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// CustomerCommand class: executes a command to print a customer's transactions
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#ifndef CustomerCommand_h
#define CustomerCommand_h

#include <stdio.h>
#include "Command.h"
#include "Store.h"

class CustomerCommand : public Command {
    
private:
    int customerID;             // customer's unqiue key (0-999)

public:
    //-------------------------- Constructor -----------------------------
    // Default Constructor for CustomerCommand
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    CustomerCommand();
    
    //-------------------------- Constructor -----------------------------
    // Constructor for CustomerCommand
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    CustomerCommand(int custID);
    
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

#endif /* CustomerCommand_h */
