// ------------------------------------------------ driver.cpp-------------------------------------------------------
// Lauren Coseo - CSS 501
// Creation Date: 10/13/21
// Date of Last Modification: 10/18/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Swap any kind of object
// -------------------------------------------------------------------------------------------------------------------- 
// Notes: Template swap function allows any object to be swapped.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;



// ------------------------------------mySwap----------------------------------------------- 
// mySwap: function to swap any two Objects, both are parameters
// pre-condition: Both Objects must be the same type
// post-condition: Objects are swapped
template<class Object>
void mySwap(Object &first, Object &second)
{
  Object tmp = first;
  first = second;
  second = tmp;
}

int main( ) {
   int x = 5, y = 7;
  double a = 2, b = 4;
  string p = "abc", q = "xyz";
  vector<int> v(5, 5), w(7, 7);
  cout <<"Before swap:"<<setw(3)<<"x="<<x<<setw(3)<<"y="<<y<<endl;
  mySwap( x, y );
  cout <<"After swap:"<<setw(3)<<"x="<<x<<setw(3)<<"y="<<y<<endl;
  
  cout <<"Before swap:"<<setw(3)<<"a="<<a<<setw(3)<<"b="<<b<<endl;
  mySwap( a, b );
  cout <<"After swap:"<<setw(3)<<"a="<<a<<setw(3)<<"b="<<b<<endl;
  
  cout <<"Before swap:"<<setw(3)<<"p="<<p<<setw(3)<<"q="<<q<<endl;
  mySwap( p, q );
  cout <<"After swap:"<<setw(3)<<"p="<<p<<setw(3)<<"q="<<q<<endl;
  
  cout <<"Before swap v:"<<endl;  
  for ( int i = 0; i < v.size( ); i++ )
    cout << v[i];
  cout<<endl;
  
   cout <<"Before swap w:"<<endl;  
  for ( int i = 0; i < w.size( ); i++ )
    cout << w[i];
  cout<<endl;
  
  mySwap( v, w );
  //cout <<"After swap:"<<setw(3)<<"v="<<v<<setw(3)<<"v="<<v<<endl;
  cout <<"After swap v:"<<endl;
  for ( int i = 0; i < v.size( ); i++ )
    cout << v[i];

	cout<<endl;
	
	cout <<"After swap w:"<<endl;  
  for ( int i = 0; i < w.size( ); i++ )
    cout << w[i];
  cout << endl;

}


