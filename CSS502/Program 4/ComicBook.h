//---------------------------------------------------------------------------
// COMICBOOK.H
// Class ComicBook (for comic book collectible items in the Store)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// ComicBook class:  creates a ComicBook object with publisher, title, and
//                   grade
//   -- allows for output of a ComicBook
//   -- allows for comparison of 2 ComicBooks
//   -- allows for creation of a ComicBook
//
// Notes:
//   -- Derived class of Collectible
//---------------------------------------------------------------------------

#ifndef ComicBook_h
#define ComicBook_h

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include "Collectible.h"
using namespace std;

class ComicBook : public Collectible {
    
public:

    //-------------------------- Constructor -----------------------------
    // Default constructor for ComicBook
    // Preconditions:   None
    // Postconditions:  Data members set to default
    ComicBook();
    
    //---------------------------- Destructor --------------------------------
    // Destructor for class ComicBook
    // Preconditions:   ComicBook points to memory on the heap
    // Postconditions:  ComicBook is emptied and deallocated
    virtual ~ComicBook() {}
    
    //-----------------------------  <  ------------------------------------
    // Determine if one ComicBook is less than another ComicBook
    // Preconditions:   None
    // Postconditions:  true is returned if this ComicBook's attributes are
    //                  less than rhs's attributes, in order of publisher,
    //                  then title, then year, then grade;
    //                  False is returned otherwise
    virtual bool operator<(const Comparable& rhs) const;
    
    //-----------------------------  >  ------------------------------------
    // Determine if one ComicBook is greater than another ComicBook
    // Preconditions:   None
    // Postconditions:  true is returned if this ComicBook's attributes are
    //                  greater than rhs's attributes, in order of type,
    //                  then year, then grade; False is returned otherwise
    virtual bool operator>(const Comparable& rhs) const;
    
    //----------------------------  ==  ------------------------------------
    // Determine if one ComicBook is equal to another ComicBook
    // Preconditions:   None
    // Postconditions:  true is returned if this ComicBook's attributes are
    //                  equal to rhs's attributes, false is returned otherwise
    virtual bool operator==(const Comparable& rhs) const;
    
    //----------------------------  !=  ------------------------------------
    // Determine if one ComicBook is not equal to another ComicBook
    // Preconditions:   None
    // Postconditions:  true is returned if this ComicBook's attributes are not
    //                  equal to rhs's attributes, false is returned otherwise
    virtual bool operator!=(const Comparable& rhs) const;
    
    //--------------------------  create  ----------------------------------
    // Create a new instance of a ComicBook object, to be used by a factory
    // Preconditions:   None
    // Postconditions:  A new ComicBook object is created
    virtual ComicBook* create(string s) const;
    
    //----------------------------  print  ------------------------------------
    // Prints the ComicBook to the ostream
    // Preconditions:   None
    // Postconditions:  Prints the attributes of a ComicBook
    virtual void print(ostream& output) const;
    
    
private:
    string publisher;       // publisher of Comic Book
    string title;           // title of Comic Book
    string grade;           // condition of Comic Book
};


#endif /* ComicBook_h */
