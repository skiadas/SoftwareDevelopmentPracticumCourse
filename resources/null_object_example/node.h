//  node.h
//  Header file for CS 223, Lab 7: Binary Search Tree Class
//
//  Barb Wahl & Theresa Wilson, 3-30-18
//
//  In Lab 7, node objects are linked together to create a binary search tree.
//
//  Implementation Note:
//
//     There are two kinds of node, a "normal" node that holds a int
//     value and has pointers to left and right subtrees, and an "empty" node
//     that can be pointed to by a normal node's left or right pointers to
//     indicate an empty subtree. An empty node is also useful for
//     implementing an empty binary_tree -- use an empty node as the root node.
//
//     The node classes are implemented in C++ by creating an abstract
//     superclass `node` and concrete subclasses `normal_node` and `empty_node`.
//
//     REMINDERS:
//
//        1. A virtual function in the superclass that provides an
//           implementation is *allowed* (NOT required) to be re-implemented in
//           subclasses.
//
//        2. A virtual function in the superclass that is declared as "= 0" in
//           the superclass is a purely virtual function and is *REQUIRED* to
//           be implemented in each subclass.

//  DO NOT CHANGE THIS FILE!

//  ############################ node (superclass) ############################

#ifndef TREE_NODE_H
#define TREE_NODE_H

namespace binary_tree_lab
{
  class node
    {
      public:
        // Default constructor with empty implementation -- must be provided
        // since the copy constructor has been declared private.
        node() { /* empty implementation */ }

        // These "=0" functions must be implemented in BOTH subclasses
        virtual bool isEmpty() const = 0;
        virtual void clear() = 0;
        virtual bool isLeaf() const = 0;
        virtual bool contains(int val) const = 0;
        virtual node * insert(int val) = 0;
        virtual size_t size() const = 0;
        virtual int height() const = 0;
        virtual std::string preorder() const = 0;
        virtual std::string inorder() const = 0;

        // Override these functions for normal_node only, NOT for empty_node.
        virtual ~node() { /* empty implementation */ }
        virtual int getData() const { return -999; }
        virtual int getMax() const { return -999; }
        virtual int getMin() const { return -999; }
        virtual node * getLeft() const { return NULL; }
        virtual node * getRight() const { return NULL; }

      private:
        // Disable the superclass copy constructor by making it private.

        // *** Do not implement! ***
        node(const node& other);

    };  // node superclass definition

    //  #################### empty_node (subclass of node) ####################
    //
    //  An empty_node stores no item and has no child nodes.
    //
    //  empty_node inherits the public members of node and needs to provide
    //  appropriate implementations for the virtual functions in node.cpp.

    class empty_node : public node
    {
      public:
        // Default empty_node constructor
        //   Note: An empty_node has no instance variables to initialize
        //     so we use an empty implementation for this constructor.
        //
        //   IMPLEMENTED HERE. Do not implement in the CPP file.
        empty_node() { }

        // isEmpty
        //   Postcondition: Returns `true` if the tree whose root is this node
        //     has no stored data values; otherwise, returns `false`.
        bool isEmpty() const;

        // clear
        //   Postcondition: The node is empty.
        void clear();

        // isLeaf
        //   Postcondition: Returns `true` if this is a leaf node, otherwise
        //     returns `false`.
        //   Hint: An empty node is not a leaf node.
        bool isLeaf() const;

        // contains
        //   Postcondition: Returns `true` if the tree whose root is this node
        //     contains the item `val`; otherwise, returns `false`.
        bool contains(int val) const;

        // insert
        //   Postcondition: Stores `val` in a new normal_node and returns a
        //     pointer to that new node.
        node * insert(int val);

        // size
        //   Postcondition: Returns the size (number of stored values) in the
        //     tree rooted at this node.
        size_t size() const;

        // height
        //   Postcondition: Returns the height of the tree rooted at this node.
        //   Hint: How do we define the height of an empty tree?
        int height() const;

        // preorder
        //   Postcondition: Returns the empty string.
        //   Note: When traversing a tree, empty nodes are not reported.
        std::string preorder() const;

        // inorder
        //   Postcondition: Returns the empty string.
        //   Note: When traversing a tree, empty nodes are not reported.
        std::string inorder() const;

    };  // empty_node class definition

    //  #################### normal_node (subclass of node) ####################
    //
    //  A normal_node stores a int value and has pointers to its left and right
    //  child nodes.  normal_node inherits the public members of node and needs
    //  to provide appropriate implementations for node functions in node.cpp.

    class normal_node : public node
    {
      public:
        // normal_node node constructor
        //   Initializes a leaf node.
        //   Postcondition: The new node is a normal_node with data equal to
        //     `val` and two empty subtrees.
        explicit normal_node(int val);

        // destructor
        //   Deallocates memory for all descendants of this node.
        ~normal_node();

        // accessor methods -- implemented here
        // DO NOT IMPLEMENT IN CPP FILE
        int    getData()  const { return data; }
        node * getLeft()  const { return left; }
        node * getRight() const { return right; }

        // isEmpty
        //   Postcondition: Returns `true` if the tree whose root is this node
        //     has no stored data values; otherwise, returns `false`.
        bool isEmpty() const;

        // insert in a normal_node
        //   Postcondition: Returns a pointer to this node.
        //   Postcondition: `val` is an item in the tree rooted at this node.
        //   Postcondition: The tree rooted at this node is still in binary-
        //      search-tree order.
        //
        //   Implementation notes:
        //     - If this node is already holding the value `val`, insert does
        //       nothing but return the `this` pointer.
        //     - Otherwise, depending on how `val` compares with the data
        //       in this node, insert makes a recursive call to insert `val`
        //       on either the left- or right-subtree of this node and returns
        //       the `this` pointer.
        //     - ** Duplicate values will not be inserted! **
        node * insert(int val);

        // size
        //   Postcondition: Returns the size (number of stored values) in the
        //     tree rooted at this node.
        //   Implementation note:  Use recursive divide-and-conquer.
        size_t size() const;

        // getMax
        //   Postcondition: Returns the largest item from the tree rooted at
        //     this node.
        int getMax() const;

        // getMin
        //   Postcondition: Returns the smallest item from the tree rooted at
        //     this node.
        int getMin() const;

        // contains
        //   Postcondition: Returns `true` if the tree whose root is this node
        //     contains the item `val`; otherwise, returns `false`.
        //
        //   Hint: Similar logic to `insert(val)`.
        bool contains(int val) const;

        // isLeaf
        //   Postcondition: Returns `true` if this node has empty left- and
        //    right-subtrees; otherwise, returns `false`.
        bool isLeaf() const;

        // height
        //   Postcondition: Returns the height of the tree rooted at this node.
        //   Implementation note:  Use recursive divide-and-conquer.
        int height() const;

        // clear
        //   Postcondition: This node is a leaf.
        //   Implementation note:  Use recursive divide-and-conquer.
        void clear();

        // preorder
        //   Prints the items in the tree rooted at the current node,
        //     using a preorder traversal (root, left, right) and separating
        //     the items with a single space.
        std::string preorder() const;

        // inorder for normal node
        //   Prints the items in the tree rooted at the current node,
        //     using an inorder traversal (left, root, right) and separating
        //     the items with a single space.
        std::string inorder() const;

      private:
        // INSTANCE VARIABLES
        int data;
        node * left;   // pointer to root of left subtree, or to an empty_node
        node * right;  // pointer to root of right subtree, or to an empty_node

    };  // normal_node class definition

}  // namespace binary_tree_lab

#endif  /* TREE_NODE_H */
