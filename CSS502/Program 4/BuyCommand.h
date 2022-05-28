//
//  BuyCommand.hpp
//  InventoryTracking
//
//  Created by Lauren Coseo on 2/22/22.
//

#ifndef BuyCommand_h
#define BuyCommand_h

#include <stdio.h>
#include "Command.h"
#include "Store.h"

class BuyCommand : public Command {
    
private:
    int customerID;             // customer's unqiue key (0-999)
    Collectible* item;          // item being bought
    
public:
    //-------------------------- Constructor -----------------------------
    // Default Constructor for BuyCommand
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    BuyCommand();
    
    //-------------------------- Constructor -----------------------------
    // Constructor for BuyCommand
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    BuyCommand(int custID, Collectible* currItem);
    
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

#endif /* BuyCommand_h */
