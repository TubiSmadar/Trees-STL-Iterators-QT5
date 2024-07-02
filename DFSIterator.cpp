// Tuvia Smadar
// gunslokij@gmail.com
#include "DFSIterator.hpp"
#include <stdexcept> // For std::runtime_error

// Constructor to initialize the DFS iterator with the root node
template <typename T>
DFSIterator<T>::DFSIterator(TreeNode<T>* root) {
    if (root) {
        nodeStack.push(root); // Push the root node onto the stack
    }
}

// Inequality operator to compare two DFS iterators
template <typename T>
bool DFSIterator<T>::operator!=(const DFSIterator& other) const {
    // Check if either of the iterators has more nodes to process
    return !nodeStack.empty() || !other.nodeStack.empty();
}

// Dereference operator to access the value of the current node
template <typename T>
T& DFSIterator<T>::operator*() {
    if (nodeStack.empty()) {
        throw std::runtime_error("Dereferencing end iterator."); // Error handling for dereferencing end
    }
    return nodeStack.top()->value; // Return the value of the current node
}

// Pre-increment operator to move the iterator to the next node in DFS order
template <typename T>
DFSIterator<T>& DFSIterator<T>::operator++() {
    if (nodeStack.empty()) {
        throw std::runtime_error("Incrementing end iterator."); // Error handling for incrementing end
    }
    TreeNode<T>* currentNode = nodeStack.top(); // Get the current node
    nodeStack.pop(); // Remove the current node from the stack

    // Add all children of the current node to the stack in reverse order
    for (auto it = currentNode->children.rbegin(); it != currentNode->children.rend(); ++it) {
        nodeStack.push(*it);
    }

    return *this; // Return the iterator pointing to the next node
}
