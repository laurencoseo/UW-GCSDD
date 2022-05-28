//---------------------------------------------------------------------------
// STOREMANAGER.H
// Class StoreManager (facilitates running commands)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// StoreManager class:  creates a StoreManager object to run commands
//   -- run commands on the store from an input file
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#ifndef StoreManager_h
#define StoreManager_h

#include <stdio.h>
#include "CommandFactory.h"
#include "Store.h"

class StoreManager {
    
private:
    CommandFactory commFactory;         // factory of store commands
    Store* store;                       // store to run commands on
    
public:
    //----------------------- Constructor -------------------------------
    // Default constructor for StoreManager
    // Preconditions:   None
    // Postconditions:  Data members set to default
    StoreManager();
    
    //----------------------- Constructor -------------------------------
    // Constructor for StoreManager
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    StoreManager(Store* s);
    
    //---------------------------- Destructor --------------------------------
    // Destructor for class StoreManager
    // Preconditions:   StoreManager points to memory on the heap
    // Postconditions:  StoreManager is emptied and deallocated
    virtual ~StoreManager() {}
    
    //---------------------------- runCommands --------------------------------
    // Method to run commands of a store from an input file
    // Preconditions:   None
    // Postconditions:  Commands are executed, if possible
    void runCommands(ifstream& infile);
    
    
};

#endif /* StoreManager_h */

