//---------------------------------------------------------------------------
// COMPARABLE.H
// Simple class Comparable (for chars)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// Comparable class:  an object that encapsulates a character (char)
//   -- allows input and output of the Comparable
//   -- allows for comparison of 2 Comparables (==, !=, <, >)
//
// Assumptions:
//   -- user must enter valid char when using >>
//---------------------------------------------------------------------------

#ifndef Comparable_h
#define Comparable_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Comparable {
    //-----------------------------  <<  --------------------------------------
    // Overloaded output operator for class SearchTree
    // Preconditions:   tree must point to a SearchTree
    // Postconditions:  tree's Comparable and count are sent to the
    //                  output istream
    friend ostream& operator<<(ostream& output, const Comparable& c);
    
public:
    //-------------------------- Constructor -----------------------------------
    // Default constructor for class Comparable
    // Preconditions:   None
    // Postconditions:  None
    Comparable() {}
    
    //---------------------------- Destructor ----------------------------------
    // Destructor for class Comparable
    // Preconditions:   ptr points to memory on the heap
    // Postconditions:  
    virtual ~Comparable() {}
    
    //--------------------------------  ==  ------------------------------------
    // Pure virtual overloaded operator<
    // Preconditions:   None
    // Postconditions:  None
    virtual bool operator==( const Comparable& rhs) const = 0;
    
    //--------------------------------  !=  ------------------------------------
    // Pure virtual overloaded operator<
    // Preconditions:   None
    // Postconditions:  None
    virtual bool operator!=( const Comparable& rhs) const = 0;
    
    //--------------------------------  <  ------------------------------------
    // Pure virtual overloaded operator<
    // Preconditions:   None
    // Postconditions:  None
    virtual bool operator<( const Comparable& rhs) const = 0;
    
    //--------------------------------  <  ------------------------------------
    // Pure virtual overloaded operator>
    // Preconditions:   None
    // Postconditions:  None
    virtual bool operator>( const Comparable& rhs) const = 0;
    
    //-----------------------------  print  ------------------------------------
    // Pure virtual print method for derived class
    // Preconditions:   None
    // Postconditions:  None
    virtual void print(ostream& output) const = 0;
    
    //-----------------------  getQuantity  ------------------------------------
    // Getter method for the Comparable's quantity
    // Preconditions:   None
    // Postconditions:  Returns quantity attributes
    int getQuantity() const;
    
    //-----------------------  setQuantity  ------------------------------------
    // Setter method for the Comparable's quantity
    // Preconditions:   None
    // Postconditions:  Sets the quantity attribute equal to the parameter
    void setQuantity(int count);
    
private:
    int quantity;           // quantity of Comparable
};


#endif /* Comparable_h */
