/* ---------------------------------------------------------------------------
 * polynominalDriver.cpp
 *
 * Lauren Coseo - CSS 501
 *
 * Creation Date: 11/15/21
 *
 * Date of Last Modification: 11/29/21
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Purpose: test all of the operations of the Polynomial class
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Notes:
 *   -- None
 * -------------------------------------------------------------------------*/


#include <stdio.h>
#include <iostream>
using namespace std;

#include "polynomial.h"

int main()
{
    /* -------- default constructor test --------*/
    Polynomial p1 = Polynomial();
    Polynomial p3;

    /* -------- changeCoefficient test --------*/
    cout << "-------- changeCoefficient test --------" << endl;
    p1.changeCoefficient(1, 3);
    cout << "p1: " << p1 << endl;
    p1.changeCoefficient(3, 3);
    cout << "changing the cofficient to 3: " << p1 << endl;
    cout << endl;

    /* -------- operator= test --------*/
    cout << "-------- operator= test --------" << endl;
    Polynomial p2 = p1;
    cout << "p2 = p1: " << p2 << endl;
    cout << endl;

    p2.changeCoefficient(-2, 4);
    p2.changeCoefficient(5, 1);
    
    /* -------- degree test --------*/
    cout << "-------- degree test --------" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p1 degree is: " << p1.degree() << endl;
    cout << "p2: " << p2 << endl;
    cout << "p2 degree is: " << p2.degree() << endl;
    cout << "p3: " << p3 << endl;
    cout << "p3 degree is: " << p3.degree() << endl;
    cout << endl;

    /* -------- coefficient test --------*/
    cout << "-------- coefficient test --------" << endl;
    cout << "p1 coefficient of power 3 is: " << p1.coefficient(3) << endl;
    cout << "p2 coefficient of power 4 is: " << p2.coefficient(4) << endl;
    cout << "p2 coefficient of power 2 is: " << p2.coefficient(2) << endl;
    cout << endl;
    
    // change coefficients to more complex polynomial
    p1.changeCoefficient(-7, 7);
    p1.changeCoefficient(-10, 2);
    p1.changeCoefficient(-1, 0);
    p1.changeCoefficient(8, 5);
    
    p2.changeCoefficient(10, 0);
    p2.changeCoefficient(7, 7);
    
    /* -------- operator+ test --------*/
    cout << "-------- operator+ test --------" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    p3 = p1 + p2;
    cout << "p3 = p1 + p2: " << p3 << endl;
    cout << endl;

    /* -------- operator- test --------*/
    cout << "-------- operator- test --------" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    p3 = p1 - p2;
    cout << "p3 = p1 - p2: " << p3 << endl;
    cout << endl;
    
    /* -------- operator== test --------*/
    cout << "-------- operator== test --------" << endl;
    Polynomial p4 = p2;
    cout << "p4: " << p4 << endl;
    cout << "p2: " << p2 << endl;
    bool equals = (p4 == p2);
    cout << "does p4 = p2? ";
    if (equals)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout << endl;

    /* -------- operator!= test --------*/
    cout << "-------- operator!= test --------" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    bool notEquals = (p1 != p2);
    cout << "does p1 != p2? ";
    if (notEquals)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout << endl;
    
    /* -------- operator+= test --------*/
    cout << "-------- operator+= test --------" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p4: " << p4 << endl;
    p1 += p4;
    cout << "p1 += p4: " << p1 << endl;
    cout << endl;
    
    /* -------- operator-= test --------*/
    cout << "-------- operator-= test --------" << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1: " << p1 << endl;
    p2 -= p1;
    cout << "p2 -= p1: " << p2 << endl;
    cout << endl;

}
