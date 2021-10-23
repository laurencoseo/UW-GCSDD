// ------------------------------------------------ SortedList.h-------------------------------------------------------
// Lauren Coseo - CSS 501
// Creation Date: 10/13/21
// Date of Last Modification: 10/18/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Create sorted list through user input
// -------------------------------------------------------------------------------------------------------------------- 
// Notes: operator+ does not sort.
// --------------------------------------------------------------------------------------------------------------------

#ifndef _SORTEDLIST_H_
#define _SORTEDLIST_H_

#include <iostream>
#include <vector>
using namespace std;

template<class Object>
class SortedList {
 public:
  void insert( const Object &item );
  const SortedList<Object> &operator+( const SortedList<Object> &rhs );
  void print( );
 private:
  vector<Object> array;
  void insertionSort( );
};

#include "SortedList.cpp"

#endif

