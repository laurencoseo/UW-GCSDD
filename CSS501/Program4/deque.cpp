/* ---------------------------------------------------------------------------
 * deque.cpp
 *
 * Lauren Coseo - CSS 501
 *
 * Creation Date: 12/4/21
 *
 * Date of Last Modification: 12/10/21
 *
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Purpose: The template Deque class holds Objects in double-sided Queues
 * 
 * -------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * Notes:
 *   -- None
 * -------------------------------------------------------------------------*/

template <class Object>
Deque<Object>::Deque( ) {                          // the constructor
  front = back = NULL;
}

template <class Object>
Deque<Object>::Deque( const Deque &rhs ) {         // the copy constructor
  front = back = NULL;
  *this = rhs;
}

template <class Object>
Deque<Object>::~Deque( ) {                         // the destructor
  clear( );
}

template <class Object>
bool Deque<Object>::isEmpty( ) const {             // check if a deque is empty
  return front == NULL;
}

template <class Object>
int Deque<Object>::size( ) const {                 // retrieves # deque nodes
  int i = 0;
  for ( DequeNode *ptr = front; ptr != NULL; ptr = ptr->next ) // traverse que
    ++i;

  return i;
}

template <class Object>
const Object &Deque<Object>::getFront( ) const {   // retrieve the front node
  if ( isEmpty( ) )
    throw "empty queue";
  return front->item;
}

template <class Object>
const Object &Deque<Object>::getBack( ) const {    // retrieve the tail node
  if ( isEmpty( ) )
    throw "empty queue";
  return back->item;
}

template <class Object>
void Deque<Object>::clear( ) {          // clean up all entries.
  while ( !isEmpty( ) )                 // dequeue till the queue gets empty.
    removeFront( );
}

// add a new node to front
template <class Object>
void Deque<Object>::addFront( const Object &obj ) {
  //implement the function body.
  DequeNode* newNode = new DequeNode;
  newNode->item = obj;
  newNode->prev = NULL;
  newNode->next = NULL;

  if (front == NULL)
  {
    front = newNode;
    back = newNode;
  }
  else {
    newNode->next = front;
    front->prev = newNode;
    front = newNode;
    newNode->prev = NULL;
  }
  
}

// add a new node to tail
template <class Object>
void Deque<Object>::addBack( const Object &obj ) { 
  DequeNode* newNode = new DequeNode;
  newNode->item = obj;
  newNode->prev = NULL;
  newNode->next = NULL;


  if (front == NULL) 
  {
    front = newNode;
    back = newNode;

  }
  else 
  {
    newNode->prev = back;
    back->next = newNode;
    back = newNode;
    newNode->next = NULL;

  }

}

template <class Object>
Object Deque<Object>::removeFront( ) {  // remove the front node
//implement the function body.
  Object temp = front->item;

  if (front->next == NULL)
  {
    front = NULL;
    back = NULL;
  }
  else
  {
    DequeNode* tempNode = front->next;
    front->next = NULL;
    front->prev = NULL;
    delete front;
    front = tempNode;
    front->prev = NULL;
  }
  return temp;
}

template <class Object>
Object Deque<Object>::removeBack( ) {   // remove the tail node

  Object temp = back->item;

  if (back->prev == NULL)
  {
    front = NULL;
    back = NULL;
  }
  else
  {
    DequeNode* tempNode = back->prev;
    back->prev = NULL;
    back->next = NULL;
    delete back;
    back = tempNode;
    back->next = NULL;
  }

  return temp;

}

template <class Object>
const Deque<Object> &Deque<Object>::operator=( const Deque &rhs ) { // assign
  if ( this != &rhs ) { // avoid self assignment
    clear( );
    for ( DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next )
      addBack( rptr->item );
  }
  return *this;
}