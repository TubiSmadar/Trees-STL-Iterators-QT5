// Tuvia Smadar
// gunslokij@gmail.com
#include "BFSIterator.hpp"
#include <stdexcept> // For std::runtime_error
#include <iostream>

// Constructor for BFSIterator: initializes the iterator with the root node
template <typename T>
BFSIterator<T>::BFSIterator(TreeNode<T>* root) {
    if (root) {
        nodeQueue.push(root); // Push the root node into the queue
    }

}

// Inequality operator to compare two BFS iterators
template <typename T>
bool BFSIterator<T>::operator!=(const BFSIterator& other) const {
    // Check if either of the iterators has more nodes to process
    return !nodeQueue.empty() || !other.nodeQueue.empty();
}

// Dereference operator to access the value of the current node
template <typename T>
T& BFSIterator<T>::operator*() {
    if (nodeQueue.empty()) {
        throw std::runtime_error("Dereferencing end iterator.");
    }
    return nodeQueue.front()->value; // Return the value of the current node
}

// Pre-increment operator to move the iterator to the next node in BFS order
template <typename T>
BFSIterator<T>& BFSIterator<T>::operator++() {
    if (nodeQueue.empty()) {
        throw std::runtime_error("Incrementing end iterator.");
    }
    TreeNode<T>* currentNode = nodeQueue.front(); // Get the current node
    nodeQueue.pop(); // Remove the current node from the queue

    // Add all children of the current node to the queue
    for (TreeNode<T>* child : currentNode->children) {
        if (child) {
            nodeQueue.push(child);
        }
    }

    return *this; // Return the iterator pointing to the next node
}
