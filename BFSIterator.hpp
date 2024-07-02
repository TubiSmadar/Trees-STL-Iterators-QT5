// Tuvia Smadar
// gunslokij@gmail.com
#ifndef BFSITERATOR_HPP
#define BFSITERATOR_HPP

#include "TreeNode.hpp"
#include <queue>
#include <stdexcept>
#include <iostream> // For debug output

// BFSIterator class template for breadth-first traversal of a tree
template <typename T>
class BFSIterator {
private:
    std::queue<TreeNode<T>*> nodeQueue; // Queue to manage nodes for BFS

public:
    // Constructor: initializes the iterator with the root node
    BFSIterator(TreeNode<T>* root);

    // Inequality operator: checks if two iterators are not equal
    bool operator!=(const BFSIterator& other) const;

    // Dereference operator: returns the value of the current node
    T& operator*();

    // Pre-increment operator: moves the iterator to the next node
    BFSIterator& operator++();
};

#include "BFSIterator.cpp"
#endif // BFSITERATOR_HPP
