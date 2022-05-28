//---------------------------------------------------------------------------
// COIN.CPP
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

#include "Coin.h"

//-------------------------- Constructor -----------------------------
// Default constructor for Coin
// Preconditions:   None
// Postconditions:  Data members set to default
Coin::Coin() : Collectible() {
    type = "";
    year = 0;
    grade = 0;
    setQuantity(0);
    setKey('M');
}

//----------------------------  print  ------------------------------------
// Prints the Coin to the ostream
// Preconditions:   None
// Postconditions:  Prints the attributes of a coin
void Coin::print(ostream& output) const {
    // output Coin's data members in order
    output << "M" << ", " << getQuantity() << ", " << type << ", " << year
            << ", " << grade;
}

//-----------------------------  <  ------------------------------------
// Determine if one Coin is less than another Coin
// Preconditions:   None
// Postconditions:  true is returned if this Coin's attributes are
//                  less than rhs's attributes, in order of type, then year,
//                  then grade; False is returned otherwise
bool Coin::operator<(const Comparable& rhs) const {
    // Cast the Comparable to a Coin
    const Coin &rhsCoin = static_cast<const Coin &>(rhs);
    
    // Compare types
    if (rhsCoin.type != type) {
        return rhsCoin.type < type;
    }
    // Compare years
    if (rhsCoin.year != year) {
        return rhsCoin.year < year;
    }
    // Compare grades
    if (rhsCoin.grade != grade) {
        return rhsCoin.grade < grade;
    }
    return false;
}

//-----------------------------  >  ------------------------------------
// Determine if one Coin is greater than another Coin
// Preconditions:   None
// Postconditions:  true is returned if this Coin's attributes are greater
//                  than rhs's attributes, in order of type, then year,
//                  then grade; False is returned otherwise
bool Coin::operator>(const Comparable& rhs) const {
    // Cast the Comparable to a Coin
    const Coin &rhsCoin = static_cast<const Coin &>(rhs);
    
    // Compare types
    if (rhsCoin.type != type) {
        return rhsCoin.type > type;
    }
    // Compare years
    if (rhsCoin.year != year) {
        return rhsCoin.year > year;
    }
    // Compare grades
    if (rhsCoin.grade != grade) {
        return rhsCoin.grade > grade;
    }
    return false;
}

//----------------------------  ==  ------------------------------------
// Determine if one Coin is equal to another Coin
// Preconditions:   None
// Postconditions:  true is returned if this Coin's attributes are
//                  equal to rhs's attributes, false is returned otherwise
bool Coin::operator==(const Comparable& rhs) const {
    // Cast the Collectible to a Coin
    const Coin &rhsCoin = static_cast<const Coin &>(rhs);
    
    return (rhsCoin.type == type && rhsCoin.year == year &&
            rhsCoin.grade == grade);
}

//----------------------------  !=  ------------------------------------
// Determine if one Coin is not equal to another Coin
// Preconditions:   None
// Postconditions:  true is returned if this Coin's attributes are not
//                  equal to rhs's attributes, false is returned otherwise
bool Coin::operator!=(const Comparable& rhs) const {
    return !(this == &rhs);
}

//--------------------------  create  ----------------------------------
// Create a new instance of a Coin object, to be used by a factory
// Preconditions:   None
// Postconditions:  A new Coin object is created
Coin* Coin::create(string s) const {
    // return a new Coin object
    Coin* newCoin = new Coin();
    vector<string> splitString;
    stringstream stringstrm (s);
    string substr;

    while (getline(stringstrm, substr, ',')) {
        splitString.push_back(substr);
    }
    
    int year, grade;
    string type;
    
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
        cout << "Cannot create Coin - Invalid input for year" << endl;
        delete newCoin;
        return nullptr;
    }
    
    // check the input for grade
    try {
        if (isdigit(stoi(splitString[1].c_str())))
        {
            grade = stoi(splitString[1].c_str());
        } else {
            throw 505;
        }
    }
    catch (...) {
        cout << "Cannot create Coin - Invalid input for grade" << endl;
        delete newCoin;
        return nullptr;
    }
    
    // check the input for type
    try {
        if (splitString[2] != "")
        {
            type = splitString[2];
        } else {
            throw 505;
        }
        
    }
    catch (...) {
        cout << "Cannot create Coin - Invalid input for type" << endl;
        delete newCoin;
        return nullptr;
    }
    
    newCoin->year = year;
    newCoin->grade = grade;
    newCoin->type = type;

    return newCoin;
}


