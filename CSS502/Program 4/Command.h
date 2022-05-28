//---------------------------------------------------------------------------
// COMMAND.H
// Class Command (for commands of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// Command class: an interface for all commands of the store
//   -- dictates an execute method must be in all command classes
//
// Notes:
//   -- Commands are also Hashable objects
//---------------------------------------------------------------------------

#ifndef Command_h
#define Command_h

#include <string>
#include <vector>
#include "HashableItem.h"
#include "Store.h"
using namespace std;

class Command : public HashableItem {
    
public:
    
    //---------------------------- Destructor --------------------------------
    // Destructor for class Command
    // Preconditions:   Command points to memory on the heap
    // Postconditions:  Command is emptied and deallocated
    virtual ~Command() {}
    
    //--------------------------  create  ----------------------------------
    // Create a new instance of a Command object, to be used by a factory
    // Preconditions:   None
    // Postconditions:  A new Command object is created
    virtual Command* create(string s) const = 0;
    
    //--------------------------  execute  ---------------------------------
    // Executes the method specified in the subclass's execute method
    // Preconditions:   None
    // Postconditions:  Returns true if executed, false if not
    virtual bool execute(Store* store) const = 0;

};

#endif /* Command_h */
