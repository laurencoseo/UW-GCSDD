//---------------------------------------------------------------------------
// COLLECTIBLEFACTORY.CPP
// Class CollectibleFactory (for collectibles of the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// CollectibleFactory class: creates a CollectibleFactory object that holds
//                           each unique collectible of the store
//   -- allows for creation of a collectible type
//
// Notes:
//   -- None
//---------------------------------------------------------------------------

#include "CollectibleFactory.h"

//-------------------------- Constructor -----------------------------
// Default constructor for CollectibleFactory
// Preconditions:   None
// Postconditions:  HashTable set to default
CollectibleFactory::CollectibleFactory() {
    // collectibles is assigned to a HashTable of size 26
    collectibles = HashTable(26);
    
    // HashTable is set up with:
    collectibles.add(new Coin);
    collectibles.add(new ComicBook);
    collectibles.add(new SportsCard);

}

//------------------------ createCollectible -------------------------
// Method to create a specific subclass of Collectible
// Preconditions:   None
// Postconditions:  New Collectible subclass created
Collectible* CollectibleFactory::createCollectible(char ch, string s) {
    if (collectibles[ch] == nullptr) {
        // throw an error message
        cout << "Invalid unique collectible key: " << ch << endl;
        return nullptr;
    }
    else {
        HashableItem* item = collectibles[ch];
        // Cast the HashableItem to a Collectible
        Collectible* c = static_cast<Collectible*>(item);
        return c->create(s);
    }
}

