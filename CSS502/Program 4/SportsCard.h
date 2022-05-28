//---------------------------------------------------------------------------
// SPORTSCARD.H
// Class SportsCard (for coin collectible items in the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// SportsCard class:  creates a SportsCard object with player, manufacturer,
//                    and grade
//   -- allows for output of a SportsCard
//   -- allows for comparison of 2 SportsCards
//   -- allows for creation of a SportsCard
//
// Notes:
//   -- Derived class of Collectible
//---------------------------------------------------------------------------

#ifndef SportsCard_h
#define SportsCard_h

#include <stdio.h>
#include <string>
#include "Collectible.h"
using namespace std;

class SportsCard : public Collectible {
    
public:

    //-------------------------- Constructor -----------------------------
    // Default constructor for SportsCard
    // Preconditions:   None
    // Postconditions:  Data members set to default
    SportsCard();
    
    //---------------------------- Destructor --------------------------------
    // Destructor for class SportsCard
    // Preconditions:   SportsCard points to memory on the heap
    // Postconditions:  SportsCard is emptied and deallocated
    virtual ~SportsCard() {}
    
    //-----------------------------  <  ------------------------------------
    // Determine if one SportsCard is less than another SportsCard
    // Preconditions:   None
    // Postconditions:  true is returned if this SportsCard's attributes are
    //                  less than rhs's attributes, in order of player,
    //                  then year, then manufacturer, then grade;
    //                  False is returned otherwise
    virtual bool operator<(const Comparable& rhs) const;

    //-----------------------------  >  ------------------------------------
    // Determine if one SportsCard is greater than another SportsCard
    // Preconditions:   None
    // Postconditions:  true is returned if this SportsCard's attributes are
    //                  greater than rhs's attributes, in order of type,
    //                  then year, then grade; False is returned otherwise
    virtual bool operator>(const Comparable& rhs) const;
    
    //----------------------------  ==  ------------------------------------
    // Determine if one SportsCard is equal to another SportsCard
    // Preconditions:   None
    // Postconditions:  true is returned if this SportsCard's attributes are
    //                  equal to rhs's attributes, false is returned otherwise
    virtual bool operator==(const Comparable& rhs) const;
    
    //----------------------------  !=  ------------------------------------
    // Determine if one SportsCard is not equal to another SportsCard
    // Preconditions:   None
    // Postconditions:  true is returned if this SportsCard's attributes are not
    //                  equal to rhs's attributes, false is returned otherwise
    virtual bool operator!=(const Comparable& rhs) const;
    
    //--------------------------  create  ----------------------------------
    // Create a new instance of a SportsCard object, to be used by a factory
    // Preconditions:   None
    // Postconditions:  A new SportsCard object is created
    virtual SportsCard* create(string s) const;
    
    //----------------------------  print  ------------------------------------
    // Prints the SportsCard to the ostream
    // Preconditions:   None
    // Postconditions:  Prints the attributes of a SportsCard
    virtual void print(ostream& output) const;

    
private:
    string player;              // player on Sports Card
    string manufacturer;        // manufacturer of Sports Card
    string grade;               // condition of Sports Card
};

#endif /* SportsCard_h */
