/* ---------------------------------------------------------------------------
 * polynominal.cpp
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


#ifndef POLYNOMIAL_CPP
#define POLYNOMIAL_CPP
#include "polynomial.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


/* ---------------------------------------------------------------------------
 * operator<<
 *
 * description:
 * Overloads the output operator
 *
 * preconditions: One parameter of type Polynomial
 *
 * postconditions:
 * prints Cn * x^n + Cn-1 * X^n-1 + ... C1 * X + C0
 * -------------------------------------------------------------------------*/
ostream& operator<<(ostream &output, const Polynomial& p)
{
    Term* currTerm = p.head->next;
    while (currTerm != p.head)
    {
        if (currTerm != p.head->next)
        {
            // print "+" or "-" if not the first term
            if (currTerm->coeff > 0)
                output << " + ";
            else
                output << " - ";
            
            // print coefficient as positive if not the first term
            if (currTerm->coeff > 1)
                output << currTerm->coeff;
            else if (currTerm->coeff < -1)
                output << -(currTerm->coeff);
        }
        
        if (currTerm == p.head->next)
            output << currTerm->coeff;
        
        if (currTerm->power > 1)
            output << "x^" << currTerm->power;
        else if (currTerm->power == 1)
            output << "x";
        
        if (currTerm->coeff == 1 && currTerm->power == 0)
            output << currTerm->coeff;
        else if (currTerm->coeff == -1 && currTerm->power == 0)
            output << -(currTerm->coeff);
    
        currTerm = currTerm->next;
    }
    return output;
}

/* ---------------------------------------------------------------------------
 * Polynomial default constructor
 *
 * description:
 * Constructs a polynomial object
 *
 * preconditions: none
 *
 * postconditions:
 * Constructs a new 0-degree polynomial with 0.0 coefficient
 * -------------------------------------------------------------------------*/
Polynomial::Polynomial() {
    size = 0;
    head = new Term();
    head->coeff = 0.0;
    head->power = 0;
    head->prev = head;
    head->next = head;
}

/* ---------------------------------------------------------------------------
 * Polynomial constructor
 *
 * description:
 * Constructs a polynomial object by creating a deep copy of another
 *
 * preconditions: parameter of type Polynomial
 *
 * postconditions:
 * Constructs a new Polynomial object from another polynomial
 * -------------------------------------------------------------------------*/
Polynomial::Polynomial(const Polynomial& p)
{
    size = 0;
    head = new Term();
    head->coeff = 0.0;
    head->power = 0;
    head->prev = head;
    head->next = head;
    
    Term* currTerm = p.head->next;
    while (currTerm != p.head)
    {
        changeCoefficient(currTerm->coeff, currTerm->power);
        currTerm = currTerm->next;
    }
}

/* ---------------------------------------------------------------------------
 * Destructor
 *
 * description:
 * Destructs a polynomial object
 *
 * preconditions: none
 *
 * postconditions:
 * Deallocates memory for a polynomial object
 * -------------------------------------------------------------------------*/
Polynomial::~Polynomial()
{
    Term* currTerm = head->next;
    Term* nextTerm = currTerm->next;
    while(currTerm != head)
    {
        remove(currTerm);
        currTerm = nextTerm;
        nextTerm = nextTerm->next;
    }
    
    remove(head);
}
  
/* ---------------------------------------------------------------------------
 * degree
 *
 * description:
 * Constructs a polynomial object
 *
 * preconditions: none
 *
 * postconditions:
 * returns the highest degree of a polynomial or 0 if there are no Terms
 * -------------------------------------------------------------------------*/
int Polynomial::degree() const
{
    return head->next->power;
}

/* ---------------------------------------------------------------------------
 * coefficient
 *
 * description:
 * Returns the coefficient of the x^power term.
 *
 * preconditions: Parameter is an int for the power
 *
 * postconditions:
 * returns the coefficient of the x^power term.
 * -------------------------------------------------------------------------*/
double Polynomial::coefficient(const int power) const
{
    Term* myTerm = getPosition(power);
    if (myTerm->power == power && myTerm != head)
    {
        return myTerm->coeff;
    }
    return 0.0;
}

/* ---------------------------------------------------------------------------
 * changeCoefficient
 *
 * description:
 * replaces the coefficient of the x^power term
 *
 * preconditions: Two parameters of a coefficient and a power
 *
 * postconditions:
 * polynominal term has a new coefficient
 * -------------------------------------------------------------------------*/
bool Polynomial::changeCoefficient(const double newCoefficient, const int power)
{
    Term* myTerm = getPosition(power);
    if (myTerm != head)
    {
        if (newCoefficient == 0)
            remove(myTerm);
        else if (myTerm-> power == power)
            myTerm->coeff = newCoefficient;
        else
            insert(myTerm, newCoefficient, power);
    } else
    {
        if (newCoefficient != 0)
            insert(myTerm, newCoefficient, power);
    }
    return true;
}
  

/* ---------------------------------------------------------------------------
 * operator+
 *
 * description:
 * overload the addition operator
 *
 * preconditions: One parameter of type Polynomial
 *
 * postconditions:
 * returns sum of 2 polynomials
 * -------------------------------------------------------------------------*/
Polynomial Polynomial::operator+(const Polynomial& p) const
{
    Polynomial sum = *this;

    sum += p;

    return sum;

}

/* ---------------------------------------------------------------------------
 * operator-
 *
 * description:
 * overload the subtraction operator
 *
 * preconditions: One parameter of type Polynomial
 *
 * postconditions:
 * returns difference of 2 polynomials
 * -------------------------------------------------------------------------*/
Polynomial Polynomial::operator-(const Polynomial& p) const
{
    Polynomial diff = *this;

    diff -= p;

    return diff;
}

/* ---------------------------------------------------------------------------
 * operator==
 *
 * description:
 * overload the equals comparison
 *
 * preconditions: One parameter of type Polynomial
 *
 * postconditions:
 * returns whether or not the 2 polynomials are equal
 * -------------------------------------------------------------------------*/
bool Polynomial::operator==(const Polynomial& p) const
{
    // use degree and coefficient functions
    if (size != p.size)
        return false;
    
    Term* thisTerm = head->next;
    Term* pTerm = p.head->next;
    while (thisTerm != head)
    {

        if (thisTerm->coeff != pTerm->coeff || thisTerm->power != pTerm->power)
            return false;
        
        thisTerm = thisTerm->next;
        pTerm = pTerm->next;
    }
    return true;
}

/* ---------------------------------------------------------------------------
 * operator!=
 *
 * description:
 * overload the not equals comparison
 *
 * preconditions: One parameter of type Polynomial
 *
 * postconditions:
 * returns whether or not the 2 polynomials are not equal
 * -------------------------------------------------------------------------*/
bool Polynomial::operator!=(const Polynomial& p) const
{
    return !(*this == p);
}

/* ---------------------------------------------------------------------------
 * operator=
 *
 * description:
 * overload the assignment operator
 *
 * preconditions: One parameter of type Polynomial
 *
 * postconditions:
 * Creates a new Polynomial
 * -------------------------------------------------------------------------*/
Polynomial& Polynomial::operator=(const Polynomial& p)
{
    if (this != &p)
    {
        Term* currTerm = head->next;
        Term* nextTerm = head->next->next;
        while(currTerm != head)
        {
            remove(currTerm);
            currTerm = nextTerm;
            nextTerm = nextTerm->next;
        }
        remove(head);
    
        size = 0;
        head = new Term();
        head->coeff = 0.0;
        head->power = 0;
        head->prev = head;
        head->next = head;
        
        Term* newTerm = p.head->next;
        while (newTerm != p.head)
        {
            changeCoefficient(newTerm->coeff, newTerm->power);
            newTerm = newTerm->next;
        }
    }
    return *this;
}

/* ---------------------------------------------------------------------------
 * operator+=
 *
 * description:
 * overload the plus equals operator
 *
 * preconditions: One parameter of type Polynomial
 *
 * postconditions:
 * returns sum of 2 polynomials
 * -------------------------------------------------------------------------*/
Polynomial& Polynomial::operator+=(const Polynomial& p)
{
    Polynomial newPoly;
    
    int highestDegree = max(this->degree(), p.degree());

    for (int i = highestDegree; i >=0; i--)
    {
        double sum = coefficient(i) + p.coefficient(i);
        newPoly.changeCoefficient(sum, i);
    }
    *this = newPoly;
    
    return *this;
}

/* ---------------------------------------------------------------------------
 * operator-=
 *
 * description:
 * overload the minus equals operator
 *
 * preconditions: One parameter of type Polynomial
 *
 * postconditions:
 * returns difference of 2 polynomials
 * -------------------------------------------------------------------------*/
Polynomial& Polynomial::operator-=(const Polynomial& p)
{
    Polynomial newPoly;
    
    int highestDegree = max(this->degree(), p.degree());

    for (int i = highestDegree; i >=0; i--)
    {
        double diff = coefficient(i) - p.coefficient(i);
        newPoly.changeCoefficient(diff, i);
    }
    *this = newPoly;
    
    return *this;
}

/* ---------------------------------------------------------------------------
 * insert
 *
 * description:
 * Inserts a new Term into the Polynomial linked list
 *
 * preconditions: Two parameters, coefficient and power
 *
 * postconditions:
 * returns true if Term is added
 * -------------------------------------------------------------------------*/
bool Polynomial::insert(Term* pos, const double newCoefficient, const int power)
{
    Term* newTerm = new Term();
    newTerm->coeff = newCoefficient;
    newTerm->power = power;
    newTerm->prev = pos->prev;
    newTerm->next = pos;
    pos->prev = newTerm;
    newTerm->prev->next = newTerm;
    
    size++;
    return true;
    
    // if null return false
    // return false;
}

/* ---------------------------------------------------------------------------
 * remove
 *
 * description:
 * Removes a Term from a specified position in the Polynomial linked list
 *
 * preconditions: One paramter of type Term
 *
 * postconditions:
 * returns true if Term was removed
 * -------------------------------------------------------------------------*/
bool Polynomial::remove(Term* pos)
{
    // reattach other terms on either side
    Term* prevTerm = pos->prev;
    Term* nextTerm = pos->next;
    prevTerm->next = nextTerm;
    nextTerm->prev = prevTerm;
    
    // set NULL and delete
    pos->prev = NULL;
    pos->next = NULL;
    delete pos;
    
    size--;

    return true;
}

/* ---------------------------------------------------------------------------
 * getPosition
 *
 * description:
 * Finds position of x^power term or finds the next lowest term/head
 *
 * preconditions: One parameter, power
 *
 * postconditions:
 * returns position of x^power term or finds the next lowest term/head
 * -------------------------------------------------------------------------*/
Term* Polynomial::getPosition(const int power) const
{
    Term* i = head->next;
    while(i != head && i->power > power)
    {
        if (i->power == power)
            return i;
        
        i = i->next;
    }
    return i;
}



#endif

