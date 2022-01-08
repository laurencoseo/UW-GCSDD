/* ---------------------------------------------------------------------------
 * longint.cpp
 *
 * Lauren Coseo - CSS 501
 *
 * Creation Date: 12/4/21
 *
 * Date of Last Modification: 12/10/21
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Purpose: The LongInt class holds numbers longer than the data type int
 * can accept. It performs arithmetic and comparison operations.
 * 
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Notes:
 *   -- Assummes the user can input anything
 * -------------------------------------------------------------------------*/

#ifndef LONGINT_CPP
#define LONGINT_CPP
#include <iostream>
#include "longint.h"
#include <ctype.h>

using namespace std;

/* ---------------------------------------------------------------------------
 * operator>>
 *
 * description:
 * Accepts user input 
 *
 * preconditions: Two parameters, istream and LongInt
 *
 * postconditions:
 * Turns the input string into a LongInt
 * -------------------------------------------------------------------------*/
istream &operator>>( istream &in, LongInt &rhs )
{
  string str;
  in >> str;
  LongInt newLongInt = LongInt(str);
  rhs = newLongInt;
  return in;
}

/* ---------------------------------------------------------------------------
 * operator<<
 *
 * description:
 * Overloads the output operator
 *
 * preconditions: Two parameters, ostream and LongInt
 *
 * postconditions:
 * prints LongInt
 * -------------------------------------------------------------------------*/
ostream &operator<<( ostream &out, const LongInt &rhs )
{
  if (rhs.digits.getFront() == '0')
  {
    out << "0";
    return out;
  }

  if (rhs.negative)
    out << "-";
  
  Deque<char> temp = rhs.digits;
  while (!temp.isEmpty())
  {
    out << temp.removeFront();
  }
  
  return out;
}

/* ---------------------------------------------------------------------------
 * Constructor (str)
 *
 * description:
 * Constructs a LongInt with an input of a string
 *
 * preconditions: One parameter of type string
 *
 * postconditions:
 * Constructs a LongInt with no leading zeros or characters that are not 0-9
 * -------------------------------------------------------------------------*/
LongInt::LongInt( const string str )
{
  if (str[0] == '-')
    negative = true;
  else
    negative = false;

  digits = Deque<char>();
  for (int i = 0; i < str.length(); i++)
  {
    if (isdigit(str[i]))
      digits.addBack(str[i]);
  }
  remove0s();
  
}

/* ---------------------------------------------------------------------------
 * Constructor (LongInt)
 *
 * description:
 * Constructs a LongInt with an input of a LongInt
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * Constructs a LongInt from another LongInt
 * -------------------------------------------------------------------------*/
LongInt::LongInt( const LongInt &rhs )
{
  digits = rhs.digits;
  negative = rhs.negative;
}

/* ---------------------------------------------------------------------------
 * Default Constructor
 *
 * description:
 * Constructs a default LongInt 
 *
 * preconditions: none
 *
 * postconditions:
 * Constructs a LongInt with a negative boolean and a Deque with a char of '0'
 * -------------------------------------------------------------------------*/
LongInt::LongInt( )
{
  negative = false;
  digits = Deque<char>();
  digits.addBack('0');
}

/* ---------------------------------------------------------------------------
 * Destructor
 *
 * description:
 * Destructs LongInt
 *
 * preconditions: none
 *
 * postconditions:
 * LongInt is destroyed
 * -------------------------------------------------------------------------*/
LongInt::~LongInt( )
{
  digits.clear();
  negative = false;
}

/* ---------------------------------------------------------------------------
 * operator+
 *
 * description:
 * overload the addition operator
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * returns sum of 2 LongInt
 * -------------------------------------------------------------------------*/
LongInt LongInt::operator+( const LongInt &rhs ) const
{
  LongInt newLongInt;
  LongInt lhsCopy = *this;
  LongInt rhsCopy = rhs;

  // positive lhs + negative rhs means ans = lhs - rhs. You should call operator-.
  // negative lhs + positive rhs means ans = rhs - lhs. You should call operator-.
  if (!negative && rhs.negative)
  {
    rhsCopy.negative = !rhsCopy.negative;
    newLongInt = lhsCopy - rhsCopy;
    return newLongInt;
  } else if (negative && !rhs.negative)
  {
    lhsCopy.negative = !lhsCopy.negative;
    newLongInt = rhsCopy - lhsCopy;
    return newLongInt;
  }

  // positive lhs + positive rhs means ans = lhs + rhs.
  int carry = 0;

  while (lhsCopy.digits.size() < rhsCopy.digits.size())
  {
    lhsCopy.digits.addFront('0');
  }

  while (rhsCopy.digits.size() < lhsCopy.digits.size())
  {
    rhsCopy.digits.addFront('0');
  }
  
  newLongInt.digits.clear();

  while (!lhsCopy.digits.isEmpty())
  {
    int lhsNum = lhsCopy.digits.removeBack() - '0';
    int rhsNum = rhsCopy.digits.removeBack() - '0';
    int sum = (lhsNum + rhsNum + carry) % 10;
    carry = (lhsNum + rhsNum + carry) / 10;
    char charSum = '0' + sum;
    newLongInt.digits.addFront(charSum);
  }

  if (carry > 0)
    newLongInt.digits.addFront('0' + carry);

  // negative lhs + negative rhs means ans = -(lhs + rhs). Apply operator+ and thereafter set a negative sign.
  if (negative && rhs.negative)
  {
    newLongInt.negative = !newLongInt.negative;
  }

  return newLongInt;
}

/* ---------------------------------------------------------------------------
 * operator-
 *
 * description:
 * overload the subtraction operator
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * returns difference of 2 LongInt
 * -------------------------------------------------------------------------*/
LongInt LongInt::operator-( const LongInt &rhs ) const
{
  LongInt newLongInt;
  LongInt lhsCopy = *this;
  LongInt rhsCopy = rhs;

  if (!negative && rhs.negative)   // pos lhs - neg rhs: calls operator+
  {
    rhsCopy.negative = !rhsCopy.negative;
    return lhsCopy + rhsCopy;
  } else if (negative && !rhs.negative) // neg lhs - pos rhs: calls operator+                                       // and returns !negative
  {
    lhsCopy.negative = !lhsCopy.negative;
    newLongInt = rhsCopy + lhsCopy;
    newLongInt.negative = !newLongInt.negative;
    return newLongInt;
  } else if (negative && rhs.negative) // neg lhs - neg rhs: pos rhs - pos lhs
  {
    lhsCopy.negative = !lhsCopy.negative;
    rhsCopy.negative = !rhsCopy.negative;
    return rhsCopy - lhsCopy;
  } else if (!negative && !rhs.negative) // pos lhs - pos rhs
  {
    if (lhsCopy < rhsCopy)               // lhsCopy < rhsCopy
    {
      newLongInt = rhsCopy - lhsCopy;
      newLongInt.negative = true;
      return newLongInt;
    }
  }

  // positive lhs - positive rhs means ans = lhs - rhs.
  int borrow = 0;

  while (lhsCopy.digits.size() < rhsCopy.digits.size())
  {
    lhsCopy.digits.addFront('0');
  }

  while (rhsCopy.digits.size() < lhsCopy.digits.size())
  {
    rhsCopy.digits.addFront('0');
  }

  newLongInt.digits.clear();

  while (!lhsCopy.digits.isEmpty())
  {
    int lhsNum = lhsCopy.digits.removeBack() - '0';
    int rhsNum = rhsCopy.digits.removeBack() - '0';
 
    if (borrow > 0)
    {
      borrow = 0;
      lhsNum--;
    }

    int diff = lhsNum - rhsNum;
    
    if (diff < 0)
    {
      borrow = 10;
      diff += borrow;
    }

    char charDiff = '0' + diff;
    newLongInt.digits.addFront(charDiff);
  }
    
  return newLongInt;
}

/* ---------------------------------------------------------------------------
 * operator=
 *
 * description:
 * overload the assignment operator
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * Creates a new LongInt
 * -------------------------------------------------------------------------*/
const LongInt& LongInt::operator=( const LongInt &rhs )
{
  if (this != &rhs)
  {
    // remove what is in this
    digits.clear();

    // make new LongInt
    digits = rhs.digits;
    negative = rhs.negative;
  }
  return *this;
}


/* ---------------------------------------------------------------------------
 * operator<
 *
 * description:
 * overload the less than operator
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * Checks if lhs is less than rhs and returns boolean
 * -------------------------------------------------------------------------*/
bool LongInt::operator< ( const LongInt & rhs ) const
{ 
  Deque<char> thisCopy = digits;
  Deque<char> rhsCopy = rhs.digits;

  // Compare their negative sign. If their signs are different, the operand with a negative sign is a smaller integer.
  if (negative && !rhs.negative)
    return true;
  else if (!negative && rhs.negative)
    return false;
  else if (negative && rhs.negative)
  {
    // Compare their deque size. If their signs are both negative, the operand with a larger deque size is a smaller integer.
    if (thisCopy.size() != rhsCopy.size())
      return thisCopy.size() > rhsCopy.size();
    else
    {
      // Compare their deque elements from the front as removing them. The operand with a smaller deque element is a larger integer in a negative sign.
      while (!thisCopy.isEmpty())
      {
        char thisFront = thisCopy.removeFront();
        char rhsFront = rhsCopy.removeFront();
        // compare digits
        if (thisFront > rhsFront)
          return true;
        else if (thisFront < rhsFront)
          return false;
      }
      return false;
    }
  } else 
  {
    // Compare their deque size. If their signs are both positive but their sizes are different, the operand with a larger deque size is a larger integer. 
    if (thisCopy.size() != rhsCopy.size())
      return thisCopy.size() < rhsCopy.size();
    else
    {
      // Compare their deque elements from the front as removing them. The operand with a larger deque element is a larger integer in a positive sign.
      while (!thisCopy.isEmpty())
      {
        char thisFront = thisCopy.removeFront();
        char rhsFront = rhsCopy.removeFront();
        // compare digits
        if (thisFront < rhsFront)
          return true;
        else if (thisFront > rhsFront)
          return false;
      }
      return false;
    }
  }
}

/* ---------------------------------------------------------------------------
 * operator<=
 *
 * description:
 * overload the less than or equal to operator
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * Checks if lhs is less than or equal to rhs and returns boolean
 * -------------------------------------------------------------------------*/
bool LongInt::operator<=( const LongInt & rhs ) const
{
  return (*this < rhs || *this == rhs);
}

/* ---------------------------------------------------------------------------
 * operator>
 *
 * description:
 * overload the greater than operator
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * Checks if lhs is greater than rhs and returns boolean
 * -------------------------------------------------------------------------*/
bool LongInt::operator> ( const LongInt & rhs ) const
{
  Deque<char> thisCopy = digits;
  Deque<char> rhsCopy = rhs.digits;

  if (negative && !rhs.negative)
    return false;
  else if (!negative && rhs.negative)
    return true;
  else if (negative && rhs.negative)
  {
    if (thisCopy.size() != rhsCopy.size())
      return thisCopy.size() < rhsCopy.size();
    else
    {
      while (!thisCopy.isEmpty())
      {
        char thisFront = thisCopy.removeFront();
        char rhsFront = rhsCopy.removeFront();
        // compare digits
        if (thisFront < rhsFront)
          return true;
        else if (thisFront > rhsFront)
          return false;
      }
      return false;
    }
  } else 
  {
    if (thisCopy.size() != rhsCopy.size())
      return thisCopy.size() > rhsCopy.size();
    else
    {
      // check each digit
      while (!thisCopy.isEmpty())
      {
        char thisFront = thisCopy.removeFront();
        char rhsFront = rhsCopy.removeFront();
        // compare digits
        if (thisFront > rhsFront)
          return true;
        else if (thisFront < rhsFront)
          return false;
      }
      return false;
    }
  }
}

/* ---------------------------------------------------------------------------
 * operator>=
 *
 * description:
 * overload the greater than or equal to operator
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * Checks if lhs is greater than or equal to rhs and returns boolean
 * -------------------------------------------------------------------------*/
bool LongInt::operator>=( const LongInt & rhs ) const
{
  return (*this > rhs || *this == rhs);
}

/* ---------------------------------------------------------------------------
 * operator==
 *
 * description:
 * overload the equals comparison
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * returns whether or not the 2 LongInt are equal
 * -------------------------------------------------------------------------*/
bool LongInt::operator==( const LongInt & rhs ) const
{
  Deque<char> thisCopy = digits;
  Deque<char> rhsCopy = rhs.digits;

  if (negative != rhs.negative || thisCopy.size() != rhsCopy.size())
    return false;
  else
  {
    while (!thisCopy.isEmpty())
    {
      // compare digits
      if (thisCopy.removeBack() != rhsCopy.removeBack())
        return false;
    }
    return true;
  }
}

/* ---------------------------------------------------------------------------
 * operator!=
 *
 * description:
 * overload the not equals comparison
 *
 * preconditions: One parameter of type LongInt
 *
 * postconditions:
 * returns whether or not the 2 LongInt are not equal
 * -------------------------------------------------------------------------*/
bool LongInt::operator!=( const LongInt & rhs ) const
{
  return !(*this == rhs);
}

/* ---------------------------------------------------------------------------
 * remove0s
 *
 * description:
 * removes leading zero from the user input of LongInt
 *
 * preconditions: none
 *
 * postconditions:
 * returns Deque<char> digits without leading zeros
 * -------------------------------------------------------------------------*/
void LongInt::remove0s( )
{
  // dont remove all 0s just the leading ones
  while (!digits.isEmpty() && digits.getFront() == '0')
    digits.removeFront();
  if (digits.isEmpty())
    digits.addFront('0');
}


#endif
