//---------------------------------------------------------------------------
// HASHTABLE.H
// Class HashTable
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// HashTable class: creates an array to hold key:value pairs
//   -- allows for adding items to Hash Table
//   -- allows for retrieving items from HashTable
//
// Notes:
//   -- User-specified hash table
//---------------------------------------------------------------------------

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>
#include <string>
#include <vector>
#include "HashableItem.h"
using namespace std;

class HashTable {
    
private:
    vector<HashableItem*> hashTable;       // vector of HashableItem pts
    int hashTableSize;
    
    //------------------------------ hash --------------------------------
    // Method to get the index of the HashableItem's search key
    // Preconditions:   None
    // Postconditions:  Returns the index for the specificed Collectible
    int hash(char ch) const;

public:

    //-------------------------- Constructor ------------------------------
    // Default constructor for HashTable
    // Preconditions:   None
    // Postconditions:  Data members set to default
    HashTable();
    
    //-------------------------- Constructor ------------------------------
    // Default constructor for HasbTable
    // Preconditions:   None
    // Postconditions:  Data members set to parameters
    HashTable(int maxSize);
    
    //---------------------------- Destructor -----------------------------
    // Destructor for class HashTable
    // Preconditions:   HashTable points to memory on the heap
    // Postconditions:  HashTable is emptied and deallocated
    ~HashTable();
    
    //------------------------------- add ---------------------------------
    // Add a key:value pair to the hash table
    // Preconditions:   None
    // Postconditions:  Pair is added
    bool add(HashableItem* item);
    
//    //------------------------------- add ---------------------------------
//    // Add a key:value pair to the hash table
//    // Preconditions:   None
//    // Postconditions:  Pair is added
//    bool add(const int key, HashableItem* item);
//    
    //------------------------------- add ---------------------------------
    // Add a key:value pair to the hash table
    // Preconditions:   None
    // Postconditions:  Pair is added
    bool add(const char key, HashableItem* item);
    
    //-------------------------- contains ---------------------------------
    // Method to determine if a key contains a value
    // Preconditions:   None
    // Postconditions:  Returns true if the key has a value, false
    //                  otherwise
    bool contains(int key);
    
    //-------------------------- getItem ----------------------------------
    // Method to get item at a specified key
    // Preconditions:   None
    // Postconditions:  Returns the item at the key
    HashableItem* getItem(int key);
    
    //-------------------------- getItem ----------------------------------
    // Method to get item at a specified key
    // Preconditions:   None
    // Postconditions:  Returns the item at the key
    HashableItem* getItem(char key);
    
    //------------------------------  []  -------------------------------------
    // Overloaded operator for [] indexing
    // Preconditions:   None
    // Postconditions:  Returns the HashableItem ptr at the given index
    HashableItem* operator[](int index) const;
    
    //------------------------------  []  -------------------------------------
    // Overloaded operator for [] indexing
    // Preconditions:   None
    // Postconditions:  Returns the HashableItem ptr at the given index
    HashableItem* operator[](char index) const;

};

#endif /* HashTable_h */
