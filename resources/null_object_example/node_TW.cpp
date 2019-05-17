#include <iostream>
#include <sstream>
#include "node.h"   // provides node, empty_node, normal_node

using namespace std;
using namespace binary_tree_lab;

// ########### empty_node (subclass of node) implementation ###########
//
//  An empty_node stores no item and has no child nodes.
//
//  empty_node inherits the public members of node and needs to provide
//  appropriate implementations for the virtual functions in node.cpp.

// Default empty_node constructor
//  Note: Implemented inline in node.h

// isEmpty
//   Postcondition: Returns `true` if the tree whose root is this node
//     has no stored data values; otherwise, returns `false`.
bool empty_node::isEmpty() const
{
    return true;
}

// clear
//   Postcondition: The node is empty.
void empty_node::clear()
{
    return; // because there is nothing to do
}

// isLeaf
//   Postcondition: Returns `true` if this is a leaf node, otherwise
//     returns `false`.
bool empty_node::isLeaf() const
{
    return false;
}

// contains
//   Postcondition: Returns `true` if the tree whose root is this node
//     contains the item `val`; otherwise, returns `false`.
bool empty_node::contains(int val) const
{
    return false;
}

// insert
//   Postcondition: Stores `val` in a new normal_node and returns a
//     pointer to that new node.
node * empty_node::insert(int val)
{
    node* temp = new normal_node(val);
    return temp;
}

// size
//   Postcondition: Returns the size (number of stored values) in the
//     tree rooted at this node.
size_t empty_node::size() const
{
    return 0;
}

// height
//   Postcondition: Returns the height of the tree rooted at this node.
int empty_node::height() const
{
    return -1;
}

// preorder
//   Postcondition: Returns the empty string.
std::string empty_node::preorder() const
{
    return "";
}

// inorder
//   Postcondition: Returns the empty string.
//   Note: When traversing a tree, empty nodes are not reported.
std::string empty_node::inorder() const
{
    return "";
}

// ########### normal_node (subclass of node) implementation ###########
//
//  A normal_node stores a int value and has pointers to its left and right
//  child nodes.  normal_node inherits the public members of node and needs
//  to provide appropriate implementations for node functions in node.cpp.

// normal_node node constructor
//   Initializes a leaf node.
//   Postcondition: The new node is a normal_node with data equal to
//     `val` and two empty subtrees.
normal_node::normal_node(int val)
{
    data = val;
    left = new empty_node;
    right = new empty_node;
}

// destructor
//   Deallocates memory for all descendants of this node.
normal_node::~normal_node()
{
    clear();
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}

// accessor methods -- implemented inline in node.h

// isEmpty
//   Postcondition: Returns `true` if the tree whose root is this node
//     has no stored data values; otherwise, returns `false`.
bool normal_node::isEmpty() const
{
    return false;
}

// insert in a normal_node
//   Postcondition: Returns a pointer to this node.
//   Postcondition: `val` is an item in the tree rooted at this node.
//
//   Implementation notes:
//     - If this node is already holding the value `val`, insert does
//       nothing but return the `this` pointer.
//     - Otherwise, depending on how `val` compares with the data
//       in this node, insert makes a recursive call to insert `val`
//       on either the left- or right-subtree of this node and returns
//       the `this` pointer.
//     - ** Duplicate values will not be inserted! **
node * normal_node::insert(int val)
{
    node* temp = NULL;

    if (val < data)       // insert into left subtree
    {
        temp = left;
        left = left -> insert(val);
    }

    else if (val > data)  // insert into right subtree
    {
        temp = right;
        right = right -> insert(val);
    }

    // check if an empty node was replaced by a normal_node
    if (temp != NULL && temp -> isEmpty())
    {
        delete temp;
    }

    return this;
}

// size
//   Postcondition: Returns the size (number of stored values) in the
//     tree rooted at this node.
size_t normal_node::size() const
{
    return 1 + left -> size() + right -> size();
}

// getMax
//   Postcondition: Returns the largest item from the tree rooted at
//     this node.
int normal_node::getMax() const
{
    if (right -> isEmpty())
        return data;
    else
        return right -> getMax();
}

// getMin
//   Postcondition: Returns the smallest item from the tree rooted at
//     this node.
int normal_node::getMin() const
{
    if (left -> isEmpty())
        return data;
    else
        return left -> getMin();
}

// contains
//   Postcondition: Returns `true` if the tree whose root is this node
//     contains the item `val`; otherwise, returns `false`.
//
bool normal_node::contains(int val) const
{
    if (data == val)
        return true;
    else if (val < data)
        return left -> contains(val);
    else
        return right -> contains(val);
}

// isLeaf
//   Postcondition: Returns `true` if this node has empty left- and
//    right-subtrees; otherwise, returns `false`.
bool normal_node::isLeaf() const
{
    return left -> isEmpty() && right -> isEmpty();
}

// height
//   Postcondition: Returns the height of the tree rooted at this node.
int normal_node::height() const
{
    int leftsub = left -> height();
    int rightsub = right -> height();
    if (leftsub >= rightsub)
        return leftsub + 1;
    else
        return rightsub + 1;
}

// clear
//   Postcondition: This node is a leaf.
void normal_node::clear()
{
    if (isLeaf())
        return;

    left -> clear();
    delete left;
    left = new empty_node;

    right -> clear();
    delete right;
    right = new empty_node;
}

// preorder
//   Prints the items in the tree rooted at the current node,
//     using a preorder traversal (root, left, right) and separating
//     the items with a single space.
string normal_node::preorder() const
{
    stringstream tempstr;
    tempstr << data;
    return tempstr.str() + " " + left -> preorder() + right -> preorder();
}

// inorder for normal node
//   Prints the items in the tree rooted at the current node,
//     using an inorder traversal (left, root, right) and separating
//     the items with a single space.
string normal_node::inorder() const
{
    stringstream tempstr;
    tempstr << data;
    return left -> inorder() + tempstr.str() + " " + right -> inorder();
}

