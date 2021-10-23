/* ---------------------------------------------------------------------------
 * complex.h
 *
 * Lauren Coseo - CSS 501
 *
 * Creation Date: 10/18/21
 *
 * Date of Last Modification: 10/21/21
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Purpose: The complex Class holds information and performs arthimetic
 * operations and comparisons for complex numbers of the type: x + yi
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Notes:
 * Implementation and assumptions:
 *   -- Complexes are stored as two doubles, one real and one imaginary
 *   -- Dividing by zero returns the original complex number
 *   -- Assumes good user input
 * -------------------------------------------------------------------------*/


#ifndef complex_hpp
#define complex_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class complex {
    
// overloaded <<: prints complex number in the form x+yi or x-yi
//      special cases for 0, -1, and 1
friend ostream& operator<<(ostream&, const complex&);

// overloaded >>: takes 2 doubles as real and imag, does no error checking
friend istream& operator>>(istream&, complex&);
    
public:
    complex(double = 0.0, double = 0.0);         // default constructor
    
    // getters
    double getReal();                            // get real number
    double getImaginary();                       // get imaginary number
    
    // setters
    void setReal(double r);                      // set real number
    void setImaginary(double i);                 // set imaginary number
    
    // operator overloads
    complex operator+(const complex &) const;    // add 2 complexes
    complex operator-(const complex &) const;    // subtract 2 complexes
    complex operator*(const complex &) const;    // multiply 2 complexes
    complex operator/(const complex &) const;    // divide 2 complexes
                                                    // division by zero prints
                                                    // error message
    
    // boolean comparison operators
    bool operator==(const complex &) const;      // is object == parameter?
    bool operator!=(const complex &) const;      // is object != parameter?
    
    // assignment operators
    complex& operator+=(const complex &);        // current object += parameter
    complex& operator-=(const complex &);        // current object -= parameter
    complex& operator*=(const complex &);        // current object *= parameter
    complex& operator/=(const complex &);        // current object /= parameter
                                                    // division by zero prints
                                                    // error message
    // conjugate
    complex conjugate() const;                   // returns x - yi
    
private:
    double real;
    double imag;
};

#endif /* complex_hpp */
