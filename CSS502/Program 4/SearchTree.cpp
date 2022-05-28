//---------------------------------------------------------------------------
// SEARCHTREE.CPP
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

#ifndef SEARCHTREE_CPP
#define SEARCHTREE_CPP

#include <algorithm>
#include "SearchTree.h"

/* ---------------------------------------------------------------------------
 
                             N O D E   M E T H O D S
 
--------------------------------------------------------------------------- */

//-------------------------- Constructor -----------------------------
// Default constructor for struct Node
// Preconditions:   None
// Postconditions:  item and pointers are null
SearchTree::Node::Node()
{
    item = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
} // end of default Node constructor


//-------------------------- Constructor -----------------------------
// Constructor for struct Node
// Preconditions:   parameters of Comparable*
// Postconditions:  *this item equals newItem, left and right child
//                  ptrs are set to nullptr
SearchTree::Node::Node(Comparable* newItem)
{
    item = newItem;
    leftChild = nullptr;
    rightChild = nullptr;
} // end of Node constructor


//-------------------------- Constructor -----------------------------
// Constructor for struct Node
// Preconditions:   parameters of Comparable*, leftPtr, rightPtr
// Postconditions:  *this item equals newItem, left and right child
//                  ptrs are set to leftPtr and rightPtr
SearchTree::Node::Node(Comparable* newItem, Node* leftPtr, Node* rightPtr)
{
    item = newItem;
    leftChild = leftPtr;
    rightChild = rightPtr;
} // end of Node constructor


/* ---------------------------------------------------------------------------
 
                    S E A R C H  T R E E  M E T H O D S
 
--------------------------------------------------------------------------- */


//-------------------------- Constructor -----------------------------------
// Default constructor for class SearchTree
// Preconditions:   None
// Postconditions:  rootPtr is a nullptr
SearchTree::SearchTree()
{
    rootPtr = nullptr;
} // end of default SearchTree constructor

//---------------------------- Destructor ----------------------------------
// Destructor for class SearchTree
// Preconditions:   ptr points to memory on the heap
// Postconditions:  Tree is emptied, Comparable for ptr is deallocated
SearchTree::~SearchTree()
{
    clear(rootPtr);
    delete rootPtr;
} // end of destructor

//----------------------------- clear ------------------------------------
// Helper Method for makeEmpty
// Removes and deallocates all of the data from the tree
// Preconditions:   Node pointer to root of SearchTree
// Postconditions:  Data is removed and deallocated but tree is not
//                  destroyed
void SearchTree::clear(Node* root)
{
    if (root != nullptr)
    {
        clear(root->leftChild);
        clear(root->rightChild);
        delete root->item;
        delete root;                // deallocate
    } // end if
    
    rootPtr = nullptr;
}


//----------------------------- makeEmpty --------------------------------
// Removes and deallocates all of the data from the tree
// Preconditions:   None
// Postconditions:  Data is removed and deallocated but tree is not
//                  destroyed
void SearchTree::makeEmpty()
{
    clear(rootPtr);
}


//----------------------------- insert -----------------------------------
// Insert a Comparable into the SearchTree or increments the count if it
// is already in the tree
// Preconditions:   ptr parameter is not nullptr
// Postconditions:  returns false if Comparable is found (and not inserted)
//                  with quantity incremented; otherwise, returns true and
//                  inserts new Node with Comparable
bool SearchTree::insert(Comparable *item)
{
    return insertHelper(rootPtr, item);
}


//------------------------- insertHelper ---------------------------------
// Helper Method for insert
// Insert a Comparable into the SearchTree or increments the quantity if it
// is already in the tree
// Preconditions:   None
// Postconditions:  returns false if Comparable is found (and not inserted)
//                  with quantity incremented; otherwise, returns true and
//                  inserts new Node with Comparable
bool SearchTree::insertHelper(Node *&root, Comparable *item)
{
    // if tree is empty, add node as root
    if (root == nullptr) {
        root = new Node(item);
    }
    // add to the left subtree is item is less than root's item
    else if (*item < *root->item)
        insertHelper(root->leftChild, item);
    // add to the right subtree is item is greater than root's item
    else if (*item > *root->item)
        insertHelper(root->rightChild, item);
    // if they are equal, increment count and return false;
    else
    {
        // increment quantity
        int oldCount = root->item->getQuantity();
        int newCount = oldCount + 1;
        root->item->setQuantity(newCount);
        return false;
    }
    return true;
} // end of insertHelper


//----------------------------- remove -----------------------------------
// Removes one occurrence of a Comparable from the tree. If it is the last
// occurrence, removes the node
// Preconditions:   parameter of Comparable&
// Postconditions:  returns false if Comparable is not found; otherwise,
//                  returns true and decrements count or removes Node
bool SearchTree::remove(Comparable &target)
{
    // boolean starts as false
    bool success = false;
    success = deleteNode(rootPtr, target);
    return success;
}


//-------------------------- deleteNode ----------------------------------
// Helper Method for remove
// Removes one occurrence of a Comparable from the tree. If it is the last
// occurrence, removes the node
// Preconditions:   parameters of Node*& root and Comparable& item
// Postconditions:  returns false if Comparable is not found; otherwise,
//                  returns true and decrements count or removes Node
bool SearchTree::deleteNode(Node *&root, const Comparable &item)
{
    // return false if not found
    if (root == nullptr)
        return false;
    else if (item == *root->item)
    {
        // decrement counter if count is greater than 1
        int oldCount = root->item->getQuantity();
        if (oldCount > 1)
        {
            int newCount = oldCount - 1;
            root->item->setQuantity(newCount);
            return true;
        }
        // If it is the last occurrence, remove the node.
        deleteRoot(root);
        return true;
    }
    else if (item < *root->item)
        return deleteNode(root->leftChild, item);
    else
        return deleteNode(root->rightChild, item);
}


//-------------------------- deleteRoot ----------------------------------
// Helper Method for remove, used in deleteNode
// Removes node (either left, single parent, or double parent)
// Preconditions:   Node*& root
// Postconditions:  Delete or reassigns root
void SearchTree::deleteRoot(Node *&root)
{
    // delete data stored in node
    delete root->item;

    // if root is the leaf
    if (root->leftChild == nullptr && root->rightChild == nullptr)
    {
        delete root;
        root = nullptr;
    }
    
    // if root is a single parent
    else if (root->leftChild == nullptr || root->rightChild == nullptr)
    {
        Node *temp = root;
        root = root->leftChild == nullptr ? root->rightChild : root->leftChild;
        delete temp;
    }
    
    // if root is a double parent
    else
    {
        root = findAndDeleteMostLeft(root->rightChild);
    }
}


//--------------------- findAndDeleteMostLeft ----------------------------
// Helper Method for remove, used in deleteRoot
// Finds and deletes most left child on the right side of a double parent
// Preconditions:   parameter of Node*& root
// Postconditions:  return Node pointer to the root
SearchTree::Node* SearchTree::findAndDeleteMostLeft(Node *&root)
{
    if (root->leftChild == nullptr)
    {
        Node *junk = root;
        root = root->rightChild;
        delete junk;
        return root;
    }
    else
        return findAndDeleteMostLeft(root->leftChild);
    return root;
}


//----------------------------- retrieve ---------------------------------
// Finds a Comparable in the tree using a key stored in the parameter
// Preconditions:   parameter of Comparable&
// Postconditions:  Returns Comparable ptr with specific key or
//                  returns nullptr is Comparable is not found
Comparable* SearchTree::retrieve(const Comparable& key) const
{
    if (retrieveHelper(rootPtr, key) == nullptr)
        return nullptr;                             // Not found
    return retrieveHelper(rootPtr, key)->item;
}


//------------------------ retrieveHelper --------------------------------
// Helper Method for retrieve
// Finds a Comparable in the tree using a key stored in the parameter
// Preconditions:   parameter of Node* root, Comparable& key
// Postconditions:  Returns Node ptr with Comparable of specific key or
//                  returns nullptr is Comparable is not found
const SearchTree::Node* SearchTree::retrieveHelper(const Node* root,
                                             const Comparable& key) const
{
    if (root == nullptr)
        // return nullptr if not found
        return nullptr;                 // Not found
    else if (*root->item == key)
        return root;                    // Found
    else if (*root->item > key)
        // Search left subtree
        return retrieveHelper(root->leftChild, key);
    else
        // Search right subtree
        return retrieveHelper(root->rightChild, key);
}

//---------------------------- inorder -----------------------------------
// Helper Method for overloaded output operator<<
// Preconditions:   parameter of ostream& output and Node* root
// Postconditions:  prints the SearchTree in sorting order
void SearchTree::inorder(ostream& output, const Node* root) const
{
    if (root != nullptr)
    {
        inorder(output, root->leftChild);
        output << *root->item << endl;
        inorder(output, root->rightChild);
    }
} // end of inorder

//-----------------------------  <<  --------------------------------------
// Overloaded output operator for class SearchTree
// Preconditions:   tree must point to a SearchTree
// Postconditions:  tree's Comparable and count are sent to the
//                  output istream
ostream& operator<<( ostream& output, const SearchTree& tree)
{
    tree.inorder(output, tree.rootPtr);
    return output;
} // end of operator<<

#endif
