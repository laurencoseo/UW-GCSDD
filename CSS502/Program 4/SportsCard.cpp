//---------------------------------------------------------------------------
// SPORTSCARD.CPP
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

#include "SportsCard.h"

//-------------------------- Constructor -----------------------------
// Default constructor for SportsCard
// Preconditions:   None
// Postconditions:  Data members set to default
SportsCard::SportsCard() : Collectible() {
    player = "";
    manufacturer = "";
    grade = "";
    setQuantity(0);
    setKey('S');
}

//----------------------------  print  ------------------------------------
// Prints the SportsCard to the ostream
// Preconditions:   None
// Postconditions:  Prints the attributes of a SportsCard
void SportsCard::print(ostream& output) const {
    output << "S" << ", " << getQuantity() << ", " << player << ", " << year
            << ", " << manufacturer << ", " << grade;
}

//-----------------------------  <  ------------------------------------
// Determine if one SportsCard is less than another SportsCard
// Preconditions:   None
// Postconditions:  true is returned if this SportsCard's attributes are
//                  less than rhs's attributes, in order of player,
//                  then year, then manufacturer, then grade;
//                  False is returned otherwise
bool SportsCard::operator<(const Comparable& rhs) const {
    // Cast the Collectible to a SportsCard
    const SportsCard &rhsCard = static_cast<const SportsCard &>(rhs);
    
    // Compare players
    if (rhsCard.player != player) {
        return rhsCard.player < player;
    }
    // Compare years
    if (rhsCard.year != year) {
        return rhsCard.year < year;
    }
    // Compare manufacturers
    if (rhsCard.manufacturer != manufacturer) {
        return rhsCard.manufacturer < manufacturer;
    }
    // Compare grades
    if (rhsCard.grade != grade) {
        return rhsCard.grade < grade;
    }
    return false;
}

//-----------------------------  >  ------------------------------------
// Determine if one SportsCard is greater than another SportsCard
// Preconditions:   None
// Postconditions:  true is returned if this SportsCard's attributes are
//                  greater than rhs's attributes, in order of type,
//                  then year, then grade; False is returned otherwise
bool SportsCard::operator>(const Comparable& rhs) const {
    // Cast the Comparable to a SportsCard
    const SportsCard &rhsCard = static_cast<const SportsCard &>(rhs);
    
    // Compare players
    if (rhsCard.player != player) {
        return rhsCard.player > player;
    }
    // Compare years
    if (rhsCard.year != year) {
        return rhsCard.year > year;
    }
    // Compare manufacturers
    if (rhsCard.manufacturer != manufacturer) {
        return rhsCard.manufacturer > manufacturer;
    }
    // Compare grades
    if (rhsCard.grade != grade) {
        return rhsCard.grade > grade;
    }
    return false;
}

//----------------------------  ==  ------------------------------------
// Determine if one Collectible is equal to another Collectible
// Preconditions:   None
// Postconditions:  true is returned if this Collectible's attributes are
//                  equal to rhs's attributes, false is returned otherwise
bool SportsCard::operator==(const Comparable& rhs) const {
    // Cast the Collectible to a SportsCard
    const SportsCard &rhsCard = static_cast<const SportsCard &>(rhs);

    return (rhsCard.player == player && rhsCard.year == year
            && rhsCard.grade == grade && rhsCard.manufacturer == manufacturer);
}

//----------------------------  !=  ------------------------------------
// Determine if one SportsCard is not equal to another SportsCard
// Preconditions:   None
// Postconditions:  true is returned if this SportsCard's attributes are not
//                  equal to rhs's attributes, false is returned otherwise
bool SportsCard::operator!=(const Comparable& rhs) const {
    return !(this == &rhs);
}

//--------------------------  create  ----------------------------------
// Create a new instance of a SportsCard object, to be used by a factory
// Preconditions:   None
// Postconditions:  A new SportsCard object is created
SportsCard* SportsCard::create(string s) const {
    // return a new SportsCard object
    SportsCard* newCard = new SportsCard();
    vector<string> splitString;
    stringstream stringstrm (s);
    string substr;

    while (getline(stringstrm, substr, ',')) {
        splitString.push_back(substr);
    }
    
    int year;
    string grade;
    string player;
    string manufacturer;
    
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
        cout << "Cannot create SportsCard - Invalid input for year" << endl;
        delete newCard;
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
        cout << "Cannot create SportsCard - Invalid input for grade" << endl;
        delete newCard;
        return nullptr;
    }
    
    // check the input for title
    try {
        if (splitString[2] != "")
        {
            player = splitString[2];
        } else {
            throw 505;
        }
        
    }
    catch (...) {
        cout << "Cannot create SportsCard - Invalid input for player" << endl;
        delete newCard;
        return nullptr;
    }
    
    // check the input for title
    try {
        if (splitString[3] != "")
        {
            manufacturer = splitString[3];
        } else {
            throw 505;
        }
        
    }
    catch (...) {
        cout << "Cannot create SportsCard - Invalid input for manufacturer"
                << endl;
        delete newCard;
        return nullptr;
    }
    
    newCard->year = year;
    newCard->grade = grade;
    newCard->player = player;
    newCard->manufacturer = manufacturer;
    
    return newCard;
}
