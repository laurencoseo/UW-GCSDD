//---------------------------------------------------------------------------
// HASHABLEITEM.CPP
// Class HashableItem (for items to be stored in hash table)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// HashableItem class: creates a Hashable object with searchKey
//   -- allows for getting and setting key
//
// Notes:
//   -- Abstract class with no implementation
//---------------------------------------------------------------------------

#include "HashableItem.h"

//-------------------------- Constructor -----------------------------
// Default constructor for HashableItem
// Preconditions:   None
// Postconditions:  Data members set to default
HashableItem::HashableItem() {
    searchKey = 0;
}

//---------------------------- getKey --------------------------------
// Method to get the search key of the HashableItem
// Preconditions:   None
// Postconditions:  Return searchKey data member
int HashableItem::getKey() const {
    return searchKey;
}

//---------------------------- setKey --------------------------------
// Method to set the search key of the HashableItem
// Preconditions:   None
// Postconditions:  searchKey data member is updated
void HashableItem::setKey(const int key) {
    searchKey = key;
}

//---------------------------- setKey --------------------------------
// Method to set the search key of the HashableItem
// Preconditions:   None
// Postconditions:  searchKey data member is updated
void HashableItem::setKey(const char key) {
    searchKey = key - 'A';
}
