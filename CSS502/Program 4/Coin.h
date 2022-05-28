//---------------------------------------------------------------------------
// COIN.H
// Class Coin (for coin collectible items in the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// Coin class:  creates a Coin object with type and grade
//   -- allows for output of a Coin
//   -- allows for comparison of 2 Coins
//   -- allows for creation of a Coin
//
// Notes:
//   -- Derived class of Collectible
//---------------------------------------------------------------------------

#ifndef Coin_h
#define Coin_h

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>
#include "Collectible.h"
using namespace std;

class Coin : public Collectible {
    
public:
    
    //-------------------------- Constructor -----------------------------
    // Default constructor for Coin
    // Preconditions:   None
    // Postconditions:  Data members set to default
    Coin();
    
    //---------------------------- Destructor --------------------------------
    // Destructor for class Coin
    // Preconditions:   Coin points to memory on the heap
    // Postconditions:  Coin is emptied and deallocated
    virtual ~Coin() {}
    
    //-----------------------------  <  ------------------------------------
    // Determine if one Coin is less than another Coin
    // Preconditions:   None
    // Postconditions:  true is returned if this Coin's attributes are
    //                  less than rhs's attributes, in order of type, then year,
    //                  then grade; False is returned otherwise
    virtual bool operator<(const Comparable& rhs) const;
    
    //-----------------------------  >  ------------------------------------
    // Determine if one Coin is greater than another Coin
    // Preconditions:   None
    // Postconditions:  true is returned if this Coin's attributes are greater
    //                  than rhs's attributes, in order of type, then year,
    //                  then grade; False is returned otherwise
    virtual bool operator>(const Comparable& rhs) const;
    
    //----------------------------  ==  ------------------------------------
    // Determine if one Coin is equal to another Coin
    // Preconditions:   None
    // Postconditions:  true is returned if this Coin's attributes are
    //                  equal to rhs's attributes, false is returned otherwise
    virtual bool operator==(const Comparable& rhs) const;
    
    //----------------------------  !=  ------------------------------------
    // Determine if one Coin is not equal to another Coin
    // Preconditions:   None
    // Postconditions:  true is returned if this Coin's attributes are not
    //                  equal to rhs's attributes, false is returned otherwise
    virtual bool operator!=(const Comparable& rhs) const;
    
    //--------------------------  create  ----------------------------------
    // Create a new instance of a Coin object, to be used by a factory
    // Preconditions:   None
    // Postconditions:  A new Coin object is created
    virtual Coin* create(string s) const;

    //----------------------------  print  ------------------------------------
    // Helper Method - Prints the Coin to the ostream
    // Preconditions:   None
    // Postconditions:  Prints the attributes of a coin
    virtual void print(ostream& output) const;
    
    
private:
    string type;        // type of Coin
    int grade;          // grade or condition of Coin

};

#endif /* Coin_h */
