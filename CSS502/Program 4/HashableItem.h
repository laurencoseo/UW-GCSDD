//---------------------------------------------------------------------------
// HASHABLEITEM.H
// Class HashableItem (for items to be stored in hash table)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// HashableItem class: creates a Hashable object with searchKey
//   -- allows for getting and setting key
//
// Notes:
//   -- Abstract class with no implementation
//---------------------------------------------------------------------------

#ifndef HashableItem_h
#define HashableItem_h

#include <stdio.h>

class HashableItem {
    
private:
    int searchKey;          // hash table key

protected:
    //---------------------------- setKey --------------------------------
    // Method to set the search key of the HashableItem
    // Preconditions:   None
    // Postconditions:  searchKey data member is updated
    void setKey(const int key);
    
    //---------------------------- setKey --------------------------------
    // Method to set the search key of the HashableItem
    // Preconditions:   None
    // Postconditions:  searchKey data member is updated
    void setKey(const char key);

public:
    //-------------------------- Constructor -----------------------------
    // Default constructor for HashableItem
    // Preconditions:   None
    // Postconditions:  Data members set to default
    HashableItem();
    
    //---------------------------- getKey --------------------------------
    // Method to get the search key of the HashableItem
    // Preconditions:   None
    // Postconditions:  Return searchKey data member
    int getKey() const;
};

#endif /* HashableItem_h */
