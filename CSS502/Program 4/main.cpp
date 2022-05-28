//---------------------------------------------------------------------------
// MAIN.CPP
// Author: Lauren Coseo
//---------------------------------------------------------------------------

#include <iostream>
#include "StoreManager.h"
#include <fstream>


int main(int argc, const char * argv[]) {
    string inventoryFile = "hw4inventory.txt";
    ifstream invStream(inventoryFile);

    string customerFile = "hw4customers.txt";
    ifstream custStream(customerFile);
    
    string commandFile = "hw4commands.txt";
    ifstream commStream(commandFile);
    
    Store clarksCollectibles;
    StoreManager clarksCollManager(&clarksCollectibles);
    
    // initialize inventory
    clarksCollectibles.buildInventory(invStream);
    
    // initialize customer list
    clarksCollectibles.buildCustomerList(custStream);
    
    // process command sequence
    clarksCollManager.runCommands(commStream);
    
}
