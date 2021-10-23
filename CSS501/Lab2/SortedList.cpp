// ------------------------------------------------ SortedList.cpp-------------------------------------------------------
// Lauren Coseo - CSS 501
// Creation Date: 10/13/21
// Date of Last Modification: 10/18/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Create sorted list through user input
// -------------------------------------------------------------------------------------------------------------------- 
// Notes: operator+ does not sort.
// --------------------------------------------------------------------------------------------------------------------

#ifndef _SORTEDLIST_CPP_
#define _SORTEDLIST_CPP_
// #include "SortedList.h"

template <class Object> 
void SortedList<Object>::insert( const Object &item ) {
  array.push_back( item );
  insertionSort( );
}

template <class Object>
const SortedList<Object> &SortedList<Object>::
operator+( const SortedList<Object> &rhs ) {
  SortedList<Object> *list = new SortedList<Object>;

  list->array = array;
  for ( int i = 0; i < rhs.array.size( ); i++ )
    list->array.push_back( rhs.array[i] );

  return *list;
}

template <class Object>
void SortedList<Object>::print( ) {
  for ( int i = 0; i < array.size( ); i++ )
    cout << array[i] << " ";
  cout << endl;
}

template <class Object>
void SortedList<Object>::insertionSort( ) {
  for ( int unsorted = 1; unsorted < array.size( ); ++unsorted ) {
    // Assume the 0th item is sorted. Unsorted items start from the 1st item
    Object unsortedTop = array[unsorted]; // Copy the top of unsorted group

    int i;
    for ( i = unsorted - 1; ( i >= 0 ) && (array[i] > unsortedTop ); --i )
      // Upon a successful comparison, shift array[i] to the right
      array[i + 1]  = array[i];
    // insert the unsorted top into the sorted group;
    array[i + 1] = unsortedTop;
  }
}

#endif
