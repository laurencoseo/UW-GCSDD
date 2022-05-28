//---------------------------------------------------------------------------
// INVENTORY.H
// Class Inventory (for inventory of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// Inventory class:  creates a Inventory object with with an array of Binary
//                   Search Trees holding coins, comics, and sports cards
//   -- allows for output of Inventory
//   -- allows for adding/removing from Inventory
//
// Notes:
//   -- Inventory is separated into groups by type of item
//---------------------------------------------------------------------------

#ifndef Inventory_h
#define Inventory_h

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "SearchTree.h"
#include "HashTable.h"
#include "Collectible.h"
#include "CollectibleFactory.h"
using namespace std;

class Inventory {
    
private:
    CollectibleFactory collFactory;
    HashTable allStock;
    
public:
    //-------------------------- Constructor -----------------------------
    // Default constructor for Inventory
    // Preconditions:   None
    // Postconditions:  Data members set to default
    Inventory();
    
    //---------------------------- Destructor --------------------------------
    // Destructor for class Inventory
    // Preconditions:   Inventory points to memory on the heap
    // Postconditions:  Inventory is emptied and deallocated
    virtual ~Inventory() {}
    
    //---------------------------- addItem ---------------------------------
    // Adds an item to the inventory with quantity of 1 or updates quantity
    // of existing item in inventory
    // Preconditions:   None
    // Postconditions:  New stock item created or quantity updated
    bool addItem(Collectible* c);
    
    //---------------------------- removeItem ------------------------------
    // Removes one instance of an item from inventory if it exists
    // Preconditions:   None
    // Postconditions:  Item quantity is reduced
    bool removeItem(Collectible* c);
    
    //---------------------------- build -----------------------------------
    // Adds collectible item to the store's inventory from an input file
    // Preconditions:   None
    // Postconditions:  Fills search trees in inventory with collectible
    //                  subclass items
    void build(ifstream& infile);
    
    //---------------------------- display ---------------------------------
    // Displays each item in inventory
    // Preconditions:   None
    // Postconditions:  Inventory is outputted as quantity then item
    void display();

};

#endif /* Inventory_h */
