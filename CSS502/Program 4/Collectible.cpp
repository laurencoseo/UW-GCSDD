//---------------------------------------------------------------------------
// COLLECTIBLE.CPP
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

#include "Collectible.h"

//-------------------------- Constructor -----------------------------
// Default constructor for Collectible
// Preconditions:   None
// Postconditions:  Data members set to default
Collectible::Collectible() {
    year = 0;
}
