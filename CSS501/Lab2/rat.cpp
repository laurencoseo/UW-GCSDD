// ------------------------------------------------ rat.cpp -------------------------------------------------------
// Lauren Coseo - CSS 501
// Creation Date: 10/12/21
// Date of Last Modification: 10/18/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose: A Rational class that holds one Rational number (fraction) and deals with math operators and assignments
// -------------------------------------------------------------------------------------------------------------------- 
// Notes: None.
// --------------------------------------------------------------------------------------------------------------------

// a Rational object holds one Rational number, one fraction
#include "rat.h"

//------------------------------ Rational ------------------------------------
// default constructor:  parameters are numerator and denominator respectively
// if the number is negative, the negative is always stored in the numerator
Rational::Rational(int n, int d) 
{
   numerator = d < 0 ? -n : n;
   denominator = d < 0 ? -d : d;
   reduce();
}

//--------------------------------- add --------------------------------------
// addition of 2 Rationals, current object and parameter
Rational Rational::add(const Rational& a) 
{
   Rational t;

   t.numerator = a.numerator * denominator + a.denominator * numerator;
   t.denominator = a.denominator * denominator;
   if (denominator != 0) t.reduce();

   return t;
}

//------------------------------ subtract ------------------------------------
// subtraction of 2 Rationals, current object and parameter
Rational Rational::subtract(const Rational& s) 
{
   Rational t;

   t.numerator = s.denominator * numerator - denominator * s.numerator;
   t.denominator = s.denominator * denominator;
   if (denominator != 0) t.reduce();

   return t;
}

//------------------------------ multiply ------------------------------------
// multiplication of 2 Rationals, current object and parameter
Rational Rational::multiply(const Rational& m) 
{
   Rational t;

   t.numerator = m.numerator * numerator;
   t.denominator = m.denominator * denominator;
   if (denominator != 0) t.reduce();

   return t;
}

//-------------------------------- divide ------------------------------------
// division of 2 Rationals, current object and parameter,
// division by zero is unreliable
Rational Rational::divide(const Rational& v) 
{
  Rational t;

  t.numerator = v.denominator * numerator;
  t.denominator = denominator * v.numerator;
  if (denominator != 0) 
  { 
    t.reduce();
  }
  else
  {
    cerr << "Cannot divide by 0.";
    return *this;
  }
   return t;
}

//---------------------------- getNumerator ---------------------------------
int Rational::getNumerator() const 
{
  return numerator;
}

//---------------------------- getDenominator ---------------------------------
int Rational::getDenominator() const 
{
  return denominator;
}

//---------------------------- operator+ ---------------------------------
// overloaded +: addition of 2 Rationals, current object and parameter
Rational Rational::operator+(const Rational &rat) const
{
  Rational sum;
  
  sum.numerator = rat.numerator * denominator + rat.denominator * numerator;

  sum.denominator = rat.denominator * denominator;
  sum.reduce();

  return sum;
}

//---------------------------- operator/ ---------------------------------
// overloaded /: division of 2 Rationals, current object and parameter
Rational Rational::operator/(const Rational &rat) const
{
  Rational div;

  if (rat.numerator !=0)
  {
    div.numerator = rat.denominator * numerator;
    div.denominator = denominator * rat.numerator;
    div.reduce();
  } 
  else if (rat.numerator == 0 || rat.denominator == 0)
  {
    cerr << "Cannot divide by 0.";
    return *this;
  }

  return div;
}

//---------------------------- operator- ---------------------------------
// overloaded -: subtraction of 2 Rationals, current object and parameter.
Rational Rational::operator-(const Rational &rat) const
{
  Rational sub;
  
  sub.numerator = rat.numerator * denominator - rat.denominator * numerator;

  sub.denominator = rat.denominator * denominator;
  sub.reduce();

  return sub;
}

//---------------------------- operator* ---------------------------------
// overloaded *: multiplication of 2 Rationals, current object and parameter
Rational Rational::operator*(const Rational &rat) const
{
  Rational mult;

  mult.numerator = rat.numerator * numerator;
  mult.denominator = rat.denominator * denominator;
  mult.reduce();

  return mult;
}
   
//---------------------------- operator+= ---------------------------------
// overloaded +=: addition of 2 Rationals, current object and parameter   
Rational& Rational::operator+=(const Rational &rat)
{
  numerator = rat.numerator * denominator + rat.denominator * numerator;
  denominator = rat.denominator * denominator;

  reduce();

  return *this;
}

//---------------------------- operator== ---------------------------------
// overloaded ==: equals comparison of 2 Rationals, current object and parameter
bool Rational::operator==(const Rational &rat) const 
{
  return((numerator == rat.numerator) && (denominator == rat.denominator));
}

//---------------------------- operator!= ---------------------------------
// overloaded !=: non-equal comparison of 2 Rationals, current object and parameter
bool Rational::operator!=(const Rational &rat) const 
{
  return((numerator != rat.numerator) || (denominator != rat.denominator));
}

//---------------------------- operator< ---------------------------------
// overloaded <: less than comparison of 2 Rationals, current object and parameter
bool Rational::operator<(const Rational &rat) const 
{
  return((numerator * rat.denominator) < (rat.numerator * denominator));
}

//---------------------------- operator<= ---------------------------------
// overloaded <=: less than or equals comparison of 2 Rationals, current object and parameter
bool Rational::operator<=(const Rational &rat) const 
{
  return((numerator * rat.denominator) <= (rat.numerator * denominator));
}

//---------------------------- operator> ---------------------------------
// overloaded >: greater than comparison of 2 Rationals, current object and parameter
bool Rational::operator>(const Rational &rat) const 
{
  return((numerator * rat.denominator) > (rat.numerator * denominator));
}

//---------------------------- operator>= ---------------------------------
// overloaded >=: greater than or equals comparison of 2 Rationals, current object and parameter
bool Rational::operator>=(const Rational &rat) const 
{
  return((numerator * rat.denominator) >= (rat.numerator * denominator));
}

//---------------------------- operator<< ---------------------------------
// overloaded <<: outstream of a Rational
ostream& operator<<(ostream &outStream, const Rational &rat) 
{
  if (rat.numerator == 0) 
  {
    outStream << rat.numerator;
  } else if (rat.denominator == 0)
  { 
    outStream << "Error, denominator is equal to zero.";
  } else
  {
    outStream << rat.numerator << "/" << rat.denominator;
  }
  return outStream;
}

//---------------------------- operator>> ---------------------------------
// overloaded >>: instream of a Rational
istream& operator>>(istream &inStream, Rational &rat) 
{
  inStream >> rat.numerator >> rat.denominator;
  if (rat.denominator == 0)
  {
    rat.numerator = 0;
    rat.denominator = 1;
  }
  else
  {
    rat.reduce();
  }
  return inStream;
}

//---------------------------- printRational ---------------------------------
void Rational::printRational() 
{
   if (denominator == 0)
      cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
   else if (numerator == 0)
      cout << 0;
   else
      cout << numerator << "/" << denominator;
}

//------------------------ printRationalAsFloat ------------------------------
void Rational::printRationalAsFloat() 
{  
   if (denominator == 0)
      cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
   else
      cout << float(numerator) / float(denominator);
}

//-------------------------------- reduce ------------------------------------
// reduce fraction to lowest terms
void Rational::reduce() 
{
   int n = numerator < 0 ? -numerator : numerator;
   int d = denominator;
   int largest = n > d ? n : d;

   int gcd = 0;                                 // greatest common divisor

   for (int loop = largest; loop >= 2; loop--)
      if (numerator % loop == 0 && denominator % loop == 0) 
      {
         gcd = loop;
         break;
      }

   if (gcd != 0) 
   {
      numerator /= gcd;
      denominator /= gcd;
   }
}

