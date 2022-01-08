/* ---------------------------------------------------------------------------
 * LongintDriver.cpp
 *
 * Lauren Coseo - CSS 501
 *
 * Creation Date: 12/4/21
 *
 * Date of Last Modification: 12/10/21
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Purpose: Tests the LongInt class and operations
 * 
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Notes:
 *   -- Assummes the user can input anything
 * -------------------------------------------------------------------------*/

#include <iostream>
#include "longint.h"

using namespace std;

int main( ) {

  LongInt a = LongInt("-1");
  LongInt b = LongInt("-123");

  /* ------ default constructor test ------*/
  cout << "-------- default constructor test --------" << endl;
  LongInt c;
  cout << "setting up LongInt c using default constructor" << endl;
  cout << "c: " << c << endl;
  cout << endl;

  /* ------- constructor test (str) -------*/
  cout << "-------- constructor (str) test --------" << endl;
  LongInt d = LongInt("00012");
  cout << "setting up LongInt d using constructor with str parameter" << endl;
  cout << "d: " << d << endl;
  cout << endl;

  /* ------ constructor test (LongInt) -----*/
  cout << "-------- constructor (LongInt) test --------" << endl;
  LongInt e = LongInt(d);
  cout << "setting up LongInt e using constructor with LongInt parameter d" << endl;
  cout << "d: " << d << endl;
  cout << "e: " << e << endl;
  cout << endl;

  /* -------- operator= test --------*/
  cout << "-------- operator= test --------" << endl;
  LongInt g = LongInt(d);
  cout << "setting up LongInt g to equal d" << endl;
  cout << "d: " << d << endl;
  cout << "g: " << g << endl;
  cout << endl;

  /* -------- operator+ test --------*/
  cout << "-------- operator+ test --------" << endl;
  c = LongInt("3");
  d = LongInt("24");
  e = LongInt("98");
  LongInt f = LongInt("-50");
  cout << a << " + " << b << " = " << a + b << endl << endl;
  cout << a << " + " << c << " = " << a + c << endl << endl;
  cout << c << " + " << d << " = " << c + d << endl << endl;
  cout << d << " + " << a << " = " << d + a << endl << endl;
  cout << d << " + " << e << " = " << d + e << endl << endl;
  cout << f << " + " << d << " = " << f + d << endl << endl;
  cout << d << " + " << f << " = " << d + f << endl << endl;
  cout << endl;

  /* -------- operator- test --------*/
  cout << "-------- operator- test --------" << endl;
  cout << a << " - " << b << " = " << a - b << endl << endl;
  cout << a << " - " << c << " = " << a - c << endl << endl;
  cout << c << " - " << d << " = " << c - d << endl << endl;
  cout << d << " - " << a << " = " << d - a << endl << endl;
  cout << d << " - " << e << " = " << d - e << endl << endl;
  cout << f << " - " << d << " = " << f - d << endl << endl;
  cout << d << " - " << f << " = " << d - f << endl << endl;
  cout << endl;
  
  /* -------- operator== test --------*/
  cout << "-------- operator== test --------" << endl;
  a = b;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  bool equals = (a == b);
  cout << "does a = b? ";
  if (equals)
      cout << "true" << endl;
  else
      cout << "false" << endl;
  cout << endl;

  /* -------- operator!= test --------*/
  cout << "-------- operator!= test --------" << endl;
  a = b;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  bool notEquals = (a != b);
  cout << "does a != b? ";
  if (notEquals)
      cout << "true" << endl;
  else
      cout << "false" << endl;
  cout << endl;
  
  /* -------- operator< test --------*/
  cout << "-------- operator< test --------" << endl;
  c = LongInt("-23");
  d = LongInt("1");
  e = LongInt("100");
  cout << a << " < " << b << " =  " << ( a < b ) << endl;
  cout << c << " < " << d << " =  " << ( c < d ) << endl;
  cout << e << " < " << d << " =  " << ( e < d ) << endl;
  cout << endl;

  /* -------- operator<= test --------*/
  cout << "-------- operator<= test --------" << endl;
  cout << a << " <= " << b << " =  " << ( a <= b ) << endl;
  cout << c << " <= " << d << " =  " << ( c <= d ) << endl;
  cout << e << " <= " << d << " =  " << ( e <= d ) << endl;
  cout << endl;

  /* -------- operator> test --------*/
  cout << "-------- operator> test --------" << endl;
  cout << a << " > " << b << " =  " << ( a > b ) << endl;
  cout << c << " > " << d << " =  " << ( c > d ) << endl;
  cout << e << " > " << d << " =  " << ( e > d ) << endl;
  cout << endl;

  /* -------- operator>= test --------*/
  cout << "-------- operator>= test --------" << endl;
  cout << a << " >= " << b << " =  " << ( a >= b ) << endl;
  cout << c << " >= " << d << " =  " << ( c >= d ) << endl;
  cout << e << " >= " << d << " =  " << ( e >= d ) << endl;
  cout << endl;
  
 

}