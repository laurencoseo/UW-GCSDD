//---------------------------------------------------------------------------
// SEARCHTREE.H
// Class SearchTree (for Nodes holding Comparables and counts)
// Author: Lauren Coseo
//---------------------------------------------------------------------------
// SearchTree class:  creates a binary search trees with Nodes that hold a
//                    Comparable and a count for that Comparable, as well as
//                    left and right child pointers
//   -- allows output of the whole binary search tree
//   -- allows for comparison of 2 Search Trees, Node by Node
//   -- allows for assignment of 2 Search Trees
//   -- allows for insertion, removal, retrieval
//   -- computes depth and height of certain Nodes in Search Tree
//
// Assumptions:
//   -- user can try to input nodes that already exist
//   -- user can try to remove nodes that don't exist
//   -- in <<, Nodes are printed as char " " count (frequency)
//---------------------------------------------------------------------------

#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "Comparable.h"
#include "HashableItem.h"
using namespace std;


class SearchTree : public HashableItem
{
    //-----------------------------  <<  --------------------------------------
    // Overloaded output operator for class SearchTree
    // Preconditions:   tree must point to a SearchTree
    // Postconditions:  tree's Comparable and count are sent to the
    //                  output istream
    friend ostream& operator<<( ostream& output, const SearchTree& tree);
    
private:
    
    struct Node {
        Comparable  *item;
        Node        *leftChild;
        Node        *rightChild;
        
        //-------------------------- Constructor -----------------------------
        // Default constructor for struct Node
        // Preconditions:   None
        // Postconditions:  item and pointers are null
        Node();
        
        //-------------------------- Constructor -----------------------------
        // Constructor for struct Node
        // Preconditions:   parameters of Comparable*
        // Postconditions:  *this item equals newItem, left and right child
        //                  ptrs are set to nullptr
        Node(Comparable* newItem);
        
        //-------------------------- Constructor -----------------------------
        // Constructor for struct Node
        // Preconditions:   parameters of Comparable*, leftPtr, rightPtr
        // Postconditions:  *this item equals newItem, left and right child
        //                  ptrs are set to leftPtr and rightPtr
        Node(Comparable* newItem, Node* leftPtr, Node* rightPtr);
    };
    
    Node* rootPtr;
    
protected:
    
    //----------------------------- clear ------------------------------------
    // Helper Method for makeEmpty
    // Removes and deallocates all of the data from the tree
    // Preconditions:   Node pointer to root of SearchTree
    // Postconditions:  Data is removed and deallocated but tree is not
    //                  destroyed
    void clear(Node* root);
    
    
    //---------------------------- copyTree ----------------------------------
    // Helper Method for copy constructor and overloaded operator=
    // Preconditions:   Node pointer to root of SearchTree
    // Postconditions:  Allocates new memory for Node/Comparable and creates
    //                  a deep copy of the SearchTree with Node* root
    Node* copyTree(const Node* root) const;

    
    //-------------------------- deleteNode ----------------------------------
    // Helper Method for remove
    // Removes one occurrence of a Comparable from the tree. If it is the last
    // occurrence, removes the node
    // Preconditions:   parameters of Node*& root and Comparable& item
    // Postconditions:  returns false if Comparable is not found; otherwise,
    //                  returns true and decrements count or removes Node
    bool deleteNode(Node *&root, const Comparable &item);
    
    
    //-------------------------- deleteRoot ----------------------------------
    // Helper Method for remove, used in deleteNode
    // Removes node (either left, single parent, or double parent)
    // Preconditions:   parameter of Node*& root
    // Postconditions:  Delete or reassigns root
    void deleteRoot(Node *&root);
    
    
    //--------------------- findAndDeleteMostLeft ----------------------------
    // Helper Method for remove, used in deleteRoot
    // Finds and deletes most left child on the right side of a double parent
    // Preconditions:   parameter of Node*& root
    // Postconditions:  return Node pointer to the root
    Node* findAndDeleteMostLeft(Node *&root);
    
    //---------------------------- inorder -----------------------------------
    // Helper Method for overloaded output operator<<
    // Preconditions:   parameter of ostream& output and Node* root
    // Postconditions:  prints the SearchTree in sorting order
    void inorder(ostream& output, const Node* root) const;
    
    
    //------------------------- insertHelper ---------------------------------
    // Helper Method for insert
    // Insert a Comparable into the SearchTree or increments the count if it
    // is already in the tree
    // Preconditions:   parameter of Node*& root, Comparable* item
    // Postconditions:  returns false if Comparable is found (and not inserted)
    //                  with count incremented; otherwise, returns true and
    //                  inserts new Node with Comparable
    bool insertHelper(Node *&root, Comparable *item);
    
    //------------------------ retrieveHelper --------------------------------
    // Helper Method for retrieve
    // Finds a Comparable in the tree using a key stored in the parameter
    // Preconditions:   parameter of Node* root, Comparable& key
    // Postconditions:  Returns Node ptr with Comparable of specific key or
    //                  returns nullptr is Comparable is not found
    const Node* retrieveHelper(const Node* root, const Comparable& key) const;
    
public:
    
    //-------------------------- Constructor ---------------------------------
    // Default constructor for class SearchTree
    // Preconditions:   None
    // Postconditions:  rootPtr is a nullptr
    SearchTree();

    
    //---------------------------- Copy --------------------------------------
    // Copy constructor for class SearchTree
    // Preconditions:   rootPtr points to the root of a new SearchTree that
    //                  is a copy of the parameter tree
    // Postconditions:  tree is copied into *this
    SearchTree(const SearchTree& tree);

    
    //---------------------------- Destructor --------------------------------
    // Destructor for class SearchTree
    // Preconditions:   ptr points to memory on the heap
    // Postconditions:  Tree is emptied, Comparable for ptr is deallocated
    ~SearchTree();
    
    
    //----------------------------- insert -----------------------------------
    // Insert a Comparable into the SearchTree or increments the count if it
    // is already in the tree
    // Preconditions:   rootPtr points to the root of a new SearchTree that
    //                  is a copy of the parameter tree
    // Postconditions:  returns false if Comparable is found (and not inserted)
    //                  with count incremented; otherwise, returns true and
    //                  inserts new Node with Comparable
    bool insert(Comparable *);
    
    
    //----------------------------- remove -----------------------------------
    // Removes one occurrence of a Comparable from the tree. If it is the last
    // occurrence, removes the node
    // Preconditions:   parameter of Comparable&
    // Postconditions:  returns false if Comparable is not found; otherwise,
    //                  returns true and decrements count or removes Node
    bool remove(Comparable &);
    
    
    //----------------------------- makeEmpty --------------------------------
    // Removes and deallocates all of the data from the tree
    // Preconditions:   None
    // Postconditions:  Data is removed and deallocated but tree is not
    //                  destroyed
    void makeEmpty();
    
    
    //----------------------------- retrieve ---------------------------------
    // Finds a Comparable in the tree using a key stored in the parameter
    // Preconditions:   parameter of Comparable&
    // Postconditions:  Returns Comparable ptr with specific key or
    //                  returns nullptr is Comparable is not found
    Comparable* retrieve(const Comparable &) const;

};


#endif // SearchTree_h
