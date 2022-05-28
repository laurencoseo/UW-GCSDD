//---------------------------------------------------------------------------
// INVENTORY.CPP
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

#include "Inventory.h"

//-------------------------- Constructor -----------------------------
// Default constructor for Inventory
// Preconditions:   None
// Postconditions:  Data members set to default
Inventory::Inventory() {
    allStock = HashTable(26);
    
    SearchTree coinStock = SearchTree();
    allStock.add('M', &coinStock);              
    
    SearchTree comicStock = SearchTree();
    allStock.add('C', &comicStock);
    
    SearchTree cardStock = SearchTree();
    allStock.add('S', &cardStock);
}

//---------------------------- addItem --------------------------------
// Adds an item to the inventory with quantity of 1 or updates quantity
// of existing item in inventory
// Preconditions:   None
// Postconditions:  New stock item created or quantity updated
bool Inventory::addItem(Collectible* c) {
    // get tree collection of collectibles
    HashableItem* item = allStock.getItem(c->getKey());
    SearchTree* tree = static_cast<SearchTree*>(item);
    return tree->insert(c);        // add to tree
}

//---------------------------- removeItem --------------------------------
// Removes one instance of an item from inventory if it exists, or delete an
// item if there is only 1
// Preconditions:   None
// Postconditions:  Item quantity is reduced
bool Inventory::removeItem(Collectible* c) {
    // get tree collection of collectibles
    HashableItem* item = allStock.getItem(c->getKey());
    SearchTree* tree = static_cast<SearchTree*>(item);
    return tree->remove(*c);
}

//---------------------------- build -----------------------------------
// Adds collectible item to the store's inventory from an input file
// Preconditions:   None
// Postconditions:  Fills search trees in inventory with collectible
//                  subclass items
void Inventory::build(ifstream& infile) {
    while(infile.peek() != EOF) {
        string fileInput;
        getline(infile, fileInput);
        
        stringstream inputStream(fileInput);
        string temp;
        
        const char* key;
        int num;
        inputStream >> num;
        inputStream.get();
        // char key1 = temp[0];
        getline(inputStream, temp, ',');        // pulls the first string
        key = temp.c_str();
        
        getline(inputStream, temp);
        // create subclass object using factory
        Collectible* c = collFactory.createCollectible(*key, temp);
        
        if (c != nullptr) {
            // add object to applicable stock search tree
            HashableItem* tree = allStock.getItem(*key);
            SearchTree* castTree = static_cast<SearchTree *>(tree);
            castTree->insert(c);
        }
    }
}

//---------------------------- display --------------------------------
// Displays each item in inventory
// Preconditions:   None
// Postconditions:  Inventory is outputted in the order of coin,
//                  comic book, then sports card
void Inventory::display() {
    
    vector<char> itemTypes = {'M', 'C', 'S'};

    for (int i = 0; i < itemTypes.size(); i++) {
        HashableItem* tree = allStock.getItem(itemTypes[i]);
        SearchTree* castTree = static_cast<SearchTree *>(tree);
        cout << *castTree;
    }

}
