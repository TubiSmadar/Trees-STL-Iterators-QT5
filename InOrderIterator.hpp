// Tuvia Smadar
// gunslokij@gmail.com
#ifndef INORDERITERATOR_HPP
#define INORDERITERATOR_HPP

#include "TreeNode.hpp"
#include <stack>

// InOrderIterator class template for in-order traversal of a tree
template <typename T>
class InOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack; // Stack to manage nodes for in-order traversal
    TreeNode<T>* current; // Current node

    // Helper function to push all left children of a node onto the stack
    void pushLeft(TreeNode<T>* node);

public:
    // Constructor: initializes the iterator with the root node
    InOrderIterator(TreeNode<T>* root);

    // Inequality operator: checks if two iterators are not equal
    bool operator!=(const InOrderIterator& other) const;

    // Dereference operator: returns the value of the current node
    T& operator*();

    // Pre-increment operator: moves the iterator to the next node
    InOrderIterator& operator++();
};

#include "InOrderIterator.cpp"
#endif // INORDERITERATOR_HPP
