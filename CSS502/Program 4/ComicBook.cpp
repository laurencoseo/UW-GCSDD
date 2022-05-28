//---------------------------------------------------------------------------
// COMICBOOK.CPP
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

#include "ComicBook.h"

//-------------------------- Constructor -----------------------------
// Default constructor for ComicBook
// Preconditions:   None
// Postconditions:  Data members set to default
ComicBook::ComicBook() : Collectible() {
    publisher = "";
    title = "";
    grade = "";
    setQuantity(0);
    setKey('C');
}

//----------------------------  print  ------------------------------------
// Prints the ComicBook to the ostream
// Preconditions:   None
// Postconditions:  Prints the attributes of a ComicBook
void ComicBook::print(ostream& output) const {
    output << "C" << ", " << getQuantity() << ", " << publisher << ", "
            << title << ", " << year << ", " << grade;
}

//-----------------------------  <  ------------------------------------
// Determine if one ComicBook is less than another ComicBook
// Preconditions:   None
// Postconditions:  true is returned if this ComicBook's attributes are
//                  less than rhs's attributes, in order of publisher,
//                  then title, then year, then grade;
//                  False is returned otherwise
bool ComicBook::operator<(const Comparable& rhs) const {
    // Cast the Comparable to a ComicBook
    const ComicBook &rhsComic = static_cast<const ComicBook &>(rhs);
    
    // Compare publishers
    if (rhsComic.publisher != publisher) {
        return rhsComic.publisher < publisher;
    }
    // Compare titles
    if (rhsComic.title != title) {
        return rhsComic.title < title;
    }
    // Compare year
    if (rhsComic.year != year) {
        return rhsComic.year < year;
    }
    // Compare grades
    if (rhsComic.grade != grade) {
        return rhsComic.grade < grade;
    }
    return false;
}

//-----------------------------  >  ------------------------------------
// Determine if one ComicBook is greater than another ComicBook
// Preconditions:   None
// Postconditions:  true is returned if this ComicBook's attributes are
//                  greater than rhs's attributes, in order of type,
//                  then year, then grade; False is returned otherwise
bool ComicBook::operator>(const Comparable& rhs) const {
    // Cast the Comparable to a ComicBook
    const ComicBook &rhsComic = static_cast<const ComicBook &>(rhs);
    
    // Compare publishers
    if (rhsComic.publisher != publisher) {
        return rhsComic.publisher > publisher;
    }
    // Compare titles
    if (rhsComic.title != title) {
        return rhsComic.title > title;
    }
    // Compare year
    if (rhsComic.year != year) {
        return rhsComic.year > year;
    }
    // Compare grades
    if (rhsComic.grade != grade) {
        return rhsComic.grade > grade;
    }
    return false;
}

//----------------------------  ==  ------------------------------------
// Determine if one Collectible is equal to another Collectible
// Preconditions:   None
// Postconditions:  true is returned if this Collectible's attributes are
//                  equal to rhs's attributes, false is returned otherwise
bool ComicBook::operator==(const Comparable& rhs) const {
    // Cast the Collectible to a ComicBook
    const ComicBook &rhsComic = static_cast<const ComicBook &>(rhs);

    return (rhsComic.publisher == publisher && rhsComic.year == year
            && rhsComic.grade == grade && rhsComic.title == title);
}

//----------------------------  !=  ------------------------------------
// Determine if one ComicBook is not equal to another ComicBook
// Preconditions:   None
// Postconditions:  true is returned if this ComicBook's attributes are not
//                  equal to rhs's attributes, false is returned otherwise
bool ComicBook::operator!=(const Comparable& rhs) const {
    return !(this == &rhs);
}


//--------------------------  create  ----------------------------------
// Create a new instance of a ComicBook object, to be used by a factory
// Preconditions:   None
// Postconditions:  A new ComicBook object is created
ComicBook* ComicBook::create(string s) const {
    // return a new ComicBook object
    ComicBook* newComic = new ComicBook();
    vector<string> splitString;
    stringstream stringstrm (s);
    string substr;

    while (getline(stringstrm, substr, ',')) {
        splitString.push_back(substr);
    }
    
    int year;
    string grade;
    string title;
    string publisher;
    
    // check the input for year
    try {
        if (isdigit(stoi(splitString[0].c_str())))
        {
            year = stoi(splitString[0].c_str());
        } else {
            throw 505;
        }
    }
    catch (...) {
        cout << "Cannot create ComicBook - Invalid input for year" << endl;
        delete newComic;
        return nullptr;
    }
    
    // check the input for grade
    try {
        if (splitString[1] != "")
        {
            grade = stoi(splitString[1].c_str());
        } else {
            throw 505;
        }
    }
    catch (...) {
        cout << "Cannot create ComicBook - Invalid input for grade" << endl;
        delete newComic;
        return nullptr;
    }
    
    // check the input for title
    try {
        if (splitString[2] != "")
        {
            title = splitString[2];
        } else {
            throw 505;
        }
        
    }
    catch (...) {
        cout << "Cannot create ComicBook - Invalid input for title" << endl;
        delete newComic;
        return nullptr;
    }
    
    // check the input for title
    try {
        if (splitString[3] != "")
        {
            title = splitString[3];
        } else {
            throw 505;
        }
        
    }
    catch (...) {
        cout << "Cannot create ComicBook - Invalid input for publisher" << endl;
        delete newComic;
        return nullptr;
    }
    
    newComic->year = year;
    newComic->grade = grade;
    newComic->title = title;
    newComic->publisher = publisher;
    
    return newComic;
}
