//---------------------------------------------------------------------------
// COMPARABLE.CPP
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


#include "Comparable.h"


//-----------------------  getQuantity  ------------------------------------
// Getter method for the Comparable's quantity
// Preconditions:   None
// Postconditions:  Returns quantity attributes
int Comparable::getQuantity() const {
    return quantity;
}

//-----------------------  setQuantity  ------------------------------------
// Setter method for the Comparable's quantity
// Preconditions:   None
// Postconditions:  Sets the quantity attribute equal to the parameter
void Comparable::setQuantity(int count) {
    quantity = count;
}

//-----------------------------  <<  --------------------------------------
// Overloaded output operator for class SearchTree
// Preconditions:   tree must point to a SearchTree
// Postconditions:  tree's Comparable and count are sent to the
//                  output istream
ostream& operator<<(ostream& output, const Comparable& c) {
    c.print(output);
    return output;
}
