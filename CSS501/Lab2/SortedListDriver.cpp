// ------------------------------------------------ SortedListDriver.cpp-------------------------------------------------------
// Lauren Coseo - CSS 501
// Creation Date: 10/13/21
// Date of Last Modification: 10/18/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Test SortedList class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes: operator+ does not sort.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "SortedList.h"

using namespace std;

template<class Object>
void input( SortedList<Object> &list ) {
  Object item;

  for ( int i = 0; i < 5; i++ ) {
    cin >> item;
    list.insert( item );
  }
}

template<class Object>
void test( SortedList<Object> &list1, SortedList<Object> &list2 ) {
  SortedList<Object> list3;

  cout << "Enter items for list1 " << endl;
  input( list1 );

  cout << "Enter items for list2 " << endl;
  input( list2 );

  list3 = list1 + list2;

  list1.print( );
  list2.print( );
  list3.print( );
}

int main( ) {
  SortedList<string> strList1, strList2;
  test( strList1, strList2 );

  SortedList<int> intList1, intList2;
  test( intList1, intList2 );
}


