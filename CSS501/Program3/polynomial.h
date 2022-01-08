/* ---------------------------------------------------------------------------
 * polynominal.h
 *
 * Lauren Coseo - CSS 501
 *
 * Creation Date: 11/15/21
 *
 * Date of Last Modification: 11/29/21
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Purpose: The Polynomial class holds a polynomial of x Terms with each
 * Term holding the coefficient and power, as well as pointing to the
 * previous and next Term, creating a circular linked list for the entire
 * Polynomial. The class also has basic operations and comparisons.
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Notes:
 *   -- Assummes you can insert and remove a Term
 * -------------------------------------------------------------------------*/


#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <string>
using namespace std;

 struct Term {     // a term on the sparse polynomial
    double coeff;       // the coefficient of each term
    int power;          // the degree of each term
    Term *prev;         // a pointer to the previous higher term
    Term *next;         // a pointer to the next lower term
  };

class Polynomial {

// Overloaded <<: prints Cn * x^n + Cn-1 * X^n-1 + ... C1 * X + C0
friend ostream& operator<<( ostream &output, const Polynomial& p );

public:
    
    // Constructors
    Polynomial( );                      // default
    Polynomial( const Polynomial& p );
    
    // Destructor
    ~Polynomial( );
    
    // returns the degree of a polynomial
    int degree( ) const;
    
    // returns the coefficient of the x^power term.
    double coefficient( const int power ) const;

    // replaces the coefficient of the x^power term
    bool changeCoefficient( const double newCoefficient, const int power );
 
    // Arithmetic operators
    Polynomial operator+( const Polynomial& p ) const;
    Polynomial operator-( const Polynomial& p ) const;

    // Boolean comparison operators
    bool operator==( const Polynomial& p ) const;
    bool operator!=( const Polynomial& p ) const;

    // Assignment operators
    Polynomial& operator=( const Polynomial& p );
    Polynomial& operator+=( const Polynomial& p );
    Polynomial& operator-=( const Polynomial& p );
    
 private:
 
    int size;       // # terms in the sparse polynomial
    Term *head;     // a pointer to the doubly-linked circular list of
                    // sparse polynomial

    // insert a new Term into the Polynomial linked list
    bool insert( Term* pos, const double newCoefficient, const int power );
    
    // remove a Term from the the Polynomial linked list
    bool remove( Term* pos );
    
    // get the position of a x-powered Term or return the head
    Term* getPosition(const int power) const;

};

#endif
