//---------------------------------------------------------------------------
// COMMANDFACTORY.CPP
// Class CommandFactory (for commands of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// CommandFactory class:  creates a CommandFactory object that holds each
//                        unique command of the store
//   -- allows for execution of the command
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#include "CommandFactory.h"

//-------------------------- Constructor -----------------------------
// Default constructor for Factory
// Preconditions:   None
// Postconditions:  HashTable set to default
CommandFactory::CommandFactory() {
    // commands is assigned to a HashTable with a size of 26
    commands = HashTable(26);
    
    // HashTable is set up with:
    commands.add(new BuyCommand);
    commands.add(new CustomerCommand);
    commands.add(new DisplayCommand);
    commands.add(new HistoryCommand);
    commands.add(new SellCommand);
}

//--------------------------- executeCommand -------------------------
// Method to execute a specific derived class of Command
// Preconditions:   None
// Postconditions:  Command is created and executed
void CommandFactory::executeCommand(char ch, string s, Store* store) {
    if (commands[ch] == nullptr) {
        // throw an error message
        cout << "Invalid unique command key: " << ch << endl;
    }
    else {
        HashableItem* commandHash = commands[ch];
        Command* c = static_cast<Command*>(commandHash);
        // Cast the HashableItem to a Command
        Command* newCommand = c->create(s);
        if (newCommand == nullptr) {
            cout << "Cannot execute - Invalid data types" << endl;
        }
        else {
            c->execute(store);
        }
        delete newCommand;
    }
}

