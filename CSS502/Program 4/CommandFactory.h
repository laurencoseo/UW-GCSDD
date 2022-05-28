//---------------------------------------------------------------------------
// COMMANDFACTORY.H
// Class CommandFactory (for commands of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// CommandFactory class:  creates a CommandFactory object that holds each
//                        unique command of the store
//   -- allows for execution of a command
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#ifndef CommandFactory_h
#define CommandFactory_h

#include <stdio.h>
#include <string>
#include "BuyCommand.h"
#include "CustomerCommand.h"
#include "DisplayCommand.h"
#include "HistoryCommand.h"
#include "SellCommand.h"
#include "HashTable.h"

class CommandFactory {
    
public:
    //-------------------------- Constructor -----------------------------
    // Default constructor for CommandFactory
    // Preconditions:   None
    // Postconditions:  HashTable set to default
    CommandFactory();
    
    //-------------------------- Destructor ------------------------------
    // Destructor for class CommandFactory
    // Preconditions:   HashTable points to memory on the heap
    // Postconditions:  HashTable is emptied and deallocated
    virtual ~CommandFactory() {}
    
    //--------------------------- executeCommand -------------------------
    // Method to execute a specific derived class of Command
    // Preconditions:   None
    // Postconditions:  Command is created and executed
    void executeCommand(char ch, string s, Store* store);
    
private:
    HashTable commands;
                                    // HashTable to hold pairs
                                    // i.e. 'S': sell
    
};

#endif /* CommandFactory_h */
