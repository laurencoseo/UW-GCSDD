//---------------------------------------------------------------------------
// COLLECTIBLE.H
// Class Collectible (for collectible items in the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// Collectible class:  creates a Collectible object with a year 
//   -- allows for output of a Collectible
//   -- allows for comparison of 2 Collectibles
//   -- allows for creation of a Collectible
//
// Notes:
//   -- Abstract class with no implementation
//---------------------------------------------------------------------------

#ifndef Collectible_h
#define Collectible_h

#include "HashableItem.h"
#include "Comparable.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
using namespace std;

class Collectible : public HashableItem, public Comparable {
    
public:
    
    //-------------------------- Constructor -----------------------------
    // Default constructor for Collectible
    // Preconditions:   None
    // Postconditions:  Data members set to default
    Collectible();
    
    //---------------------------- Destructor ------------------------------
    // Destructor for class Collectible
    // Preconditions:   Collectible points to memory on the heap
    // Postconditions:  Collectible is emptied and deallocated
    virtual ~Collectible() {}
    
    //--------------------------  create  ----------------------------------
    // Create a new instance of a Collectible object, to be used by a factory
    // Preconditions:   None
    // Postconditions:  A new Collectible object is created
    virtual Collectible* create(string s) const = 0;
 
protected:
    int year;           // year Collectible was made
};

#endif /* Collectible_h */
