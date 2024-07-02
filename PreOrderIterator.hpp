// Tuvia Smadar
// gunslokij@gmail.com
#ifndef PREORDERITERATOR_HPP
#define PREORDERITERATOR_HPP

#include "TreeNode.hpp"
#include <stack>

// PreOrderIterator class template for pre-order traversal of a tree
template <typename T>
class PreOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack; // Stack to manage nodes for pre-order traversal

public:
    // Constructor: initializes the iterator with the root node
    PreOrderIterator(TreeNode<T>* root);

    // Inequality operator: checks if two iterators are not equal
    bool operator!=(const PreOrderIterator& other) const;

    // Dereference operator: returns the value of the current node
    T& operator*();

    // Pre-increment operator: moves the iterator to the next node
    PreOrderIterator& operator++();
};

#include "PreOrderIterator.cpp"
#endif // PREORDERITERATOR_HPP
