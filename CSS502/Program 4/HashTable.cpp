//---------------------------------------------------------------------------
// HASHTABLE.CPP
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

#include "HashTable.h"

//-------------------------- Constructor ------------------------------
// Default constructor for HashTable
// Preconditions:   None
// Postconditions:  Data members set to default
HashTable::HashTable() {
    hashTableSize = 0;
}

//-------------------------- Constructor ------------------------------
// Constructor for HasbTable with size parameter
// Preconditions:   None
// Postconditions:  Data members set to parameters
HashTable::HashTable(int maxSize) {
    // set the hashTableSize
    hashTableSize = maxSize;

    for (int i = 0; i < hashTableSize; i++) {
        hashTable.push_back(nullptr);
    }
}

//---------------------------- Destructor -----------------------------
// Destructor for class HashTable
// Preconditions:   HashTable points to memory on the heap
// Postconditions:  HashTable is emptied and deallocated
HashTable::~HashTable() {
//    for (int i = 0; i < hashTableSize; i++) {
//        delete hashTable[i];
//        hashTable[i] = nullptr;
//    }
}

//------------------------------- add -----------------------------
// Add a key:value pair to the hash table
// Preconditions:   None
// Postconditions:  Pair is added
bool HashTable::add(HashableItem* item) {
    hashTable[item->getKey()] = item;
    return true;
}

////------------------------------- add -----------------------------
//// Add a key:value pair to the hash table
//// Preconditions:   None
//// Postconditions:  Pair is added
//bool HashTable::add(const int key, HashableItem* item) {
//    hashTable[key] = item;
//    return true;
//}

//------------------------------- add ---------------------------------
// Add a key:value pair to the hash table
// Preconditions:   None
// Postconditions:  Pair is added
bool HashTable::add(const char key, HashableItem* item) {
    int numKey = hash(key);
    hashTable[numKey] = item;
    return true;
}

//-------------------------- contains -----------------------------
// Method to determine if a key contains a value
// Preconditions:   None
// Postconditions:  Returns true if the key has a value, false
//                  otherwise
bool HashTable::contains(int key) {
    return hashTable[key] != nullptr;
}

//-------------------------- getItem -----------------------------
// Method to get item at a specified key
// Preconditions:   None
// Postconditions:  Returns the item at the key
HashableItem* HashTable::getItem(int key) {
    return hashTable[key];
}

//-------------------------- getItem ----------------------------------
// Method to get item at a specified key
// Preconditions:   None
// Postconditions:  Returns the item at the key
HashableItem* HashTable::getItem(char key) {
    int numKey = hash(key);
    return hashTable[numKey];
}

//------------------------------ hash --------------------------------
// Method to get the index of the HashableItem's search key
// Preconditions:   None
// Postconditions:  Returns the index for the specificed Collectible
int HashTable::hash(char ch) const {
    // return the char cast as an int
    int hashNum = ch - 'A';
    return hashNum;
}

//------------------------------  []  -------------------------------------
// Overloaded operator for [] indexing
// Preconditions:   None
// Postconditions:  Returns the HashableItem ptr at the given int index
HashableItem* HashTable::operator[](int index) const {
    return hashTable[index];
}

//------------------------------  []  -------------------------------------
// Overloaded operator for [] indexing
// Preconditions:   None
// Postconditions:  Returns the HashableItem ptr at the given char index
HashableItem* HashTable::operator[](char index) const {
    int numIndex = hash(index);
    return hashTable[numIndex];
}
