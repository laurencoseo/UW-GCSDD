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

#include "StoreManager.h"

//----------------------- Constructor -------------------------------
// Default constructor for StoreManager
// Preconditions:   None
// Postconditions:  Data members set to default
StoreManager::StoreManager() {
    store = nullptr;
    commFactory = CommandFactory();
}

//----------------------- Constructor -------------------------------
// Constructor for StoreManager
// Preconditions:   None
// Postconditions:  Data members set to parameters
StoreManager::StoreManager(Store* s) {
    store = s;
    commFactory = CommandFactory();
}

//---------------------------- runCommands --------------------------------
// Method to run commands of a store from an input file
// Preconditions:   None
// Postconditions:  Commands are executed, if possible
void StoreManager::runCommands(ifstream& infile) {
    while(infile.peek() != EOF) {
        string fileInput;
        getline(infile, fileInput);
        stringstream inputStream(fileInput);
        string temp;
        
        char commandKey;
        getline(inputStream, temp, ',');
        commandKey = temp[0];
        
        string s;
        getline(inputStream, s);
        
        // try to execute command
        commFactory.executeCommand(commandKey, s, store);
    }
}
