/* ---------------------------------------------------------------------------
 * longint.h
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

#ifndef LONGINT_H
#define LONGINT_H
#include <iostream>
#include "deque.h"

using namespace std;

class LongInt {
  // istream and ostream
  friend istream &operator>>( istream &in, LongInt &rhs );
  friend ostream &operator<<( ostream &out, const LongInt &rhs );
 public:
  // Constructors
  LongInt( const string str ); 
  LongInt( const LongInt &rhs );
  LongInt( );

  // Destructor
  ~LongInt( );

  // Arithmetic binary operators
  LongInt operator+( const LongInt &rhs ) const;
  LongInt operator-( const LongInt &rhs ) const;

  // assignment operators
  const LongInt &operator=( const LongInt &rhs );

  // Logical binary operators
  bool operator< ( const LongInt & rhs ) const;
  bool operator<=( const LongInt & rhs ) const;
  bool operator> ( const LongInt & rhs ) const;
  bool operator>=( const LongInt & rhs ) const;
  bool operator==( const LongInt & rhs ) const;
  bool operator!=( const LongInt & rhs ) const;

 private:
  Deque<char> digits;
  bool negative;
  void remove0s( );
};


#endif
