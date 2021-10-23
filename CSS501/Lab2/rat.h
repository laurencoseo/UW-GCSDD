// ------------------------------------------------ rat.h -------------------------------------------------------
// Lauren Coseo - CSS 501
// Creation Date: 10/12/21
// Date of Last Modification: 10/18/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose: A Rational class that holds one Rational number (fraction) and deals with math operators and assignments
// -------------------------------------------------------------------------------------------------------------------- 
// Notes: None.
// --------------------------------------------------------------------------------------------------------------------

// a Rational object holds one Rational number, one fraction

#ifndef RAT_H
#define RAT_H
#include <iostream>
using namespace std;

class Rational {                           // not fully commented
public:
  Rational(int = 0, int = 1);             // default constructor
  Rational add(const Rational &);
  Rational subtract(const Rational &);
  Rational multiply(const Rational &);
  Rational divide(const Rational &);

  int getNumerator() const;
  int getDenominator() const;

  Rational operator+(const Rational &rat) const;
  Rational operator/(const Rational &rat) const;
  Rational operator-(const Rational &rat) const;
  Rational operator*(const Rational &rat) const;
   
  Rational& operator+=(const Rational &rat);

  bool operator==(const Rational &rat) const;
  bool operator!=(const Rational &rat) const;

  bool operator<(const Rational &rat) const;
  bool operator<=(const Rational &rat) const;

  bool operator>(const Rational &rat) const;
  bool operator>=(const Rational &rat) const;
  
  friend ostream& operator<<(ostream &outStream, const Rational &rat);
  friend istream& operator>>(istream &inStream, Rational &rat);

   void printRational();
   void printRationalAsFloat();
private:
   int numerator;
   int denominator;

   void reduce();                 // utility function, reduce to lowest terms
};

#endif

