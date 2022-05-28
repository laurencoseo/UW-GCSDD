//---------------------------------------------------------------------------
// COLLECTIBLEFACTORY.H
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

#ifndef CollectibleFactory_h
#define CollectibleFactory_h

#include <stdio.h>
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"
#include "HashTable.h"

class CollectibleFactory {
    
public:
    //-------------------------- Constructor -----------------------------
    // Default constructor for CollectibleFactory
    // Preconditions:   None
    // Postconditions:  HashTable set to default
    CollectibleFactory();
    
    //-------------------------- Destructor ------------------------------
    // Destructor for class CollectibleFactory
    // Preconditions:   HashTable points to memory on the heap
    // Postconditions:  HashTable is emptied and deallocated
    virtual ~CollectibleFactory() {}
    
    //------------------------ createCollectible -------------------------
    // Method to create a specific subclass of Collectible
    // Preconditions:   None
    // Postconditions:  New Collectible subclass created
    Collectible* createCollectible(char ch, string s);
    
private:
    HashTable collectibles;         // HashTable to hold pairs
                                    // i.e. 'c':ComicBook
};

#endif /* CollectibleFactory_h */
