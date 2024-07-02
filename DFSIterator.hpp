// Tuvia Smadar
// gunslokij@gmail.com
#ifndef DFSITERATOR_HPP
#define DFSITERATOR_HPP

#include "TreeNode.hpp"
#include <stack>

// DFSIterator class template for depth-first traversal of a tree
template <typename T>
class DFSIterator {
private:
    std::stack<TreeNode<T>*> nodeStack; // Stack to manage nodes for DFS

public:
    // Constructor: initializes the iterator with the root node
    DFSIterator(TreeNode<T>* root);

    // Inequality operator: checks if two iterators are not equal
    bool operator!=(const DFSIterator& other) const;

    // Dereference operator: returns the value of the current node
    T& operator*();

    // Pre-increment operator: moves the iterator to the next node
    DFSIterator& operator++();
};

#include "DFSIterator.cpp"
#endif // DFSITERATOR_HPP
