// Tuvia Smadar
// gunslokij@gmail.com
#include "InOrderIterator.hpp"
#include <stdexcept> // For std::runtime_error

// Constructor to initialize the InOrder iterator with the root node
template <typename T>
InOrderIterator<T>::InOrderIterator(TreeNode<T>* root) : current(root) {
    pushLeft(root); // Push all left children of the root to the stack
}

// Helper function to push all left children of a node onto the stack
template <typename T>
void InOrderIterator<T>::pushLeft(TreeNode<T>* node) {
    while (node) {
        nodeStack.push(node);
        if (!node->children.empty()) {
            node = node->children[0];
        } else {
            break;
        }
    }
}

// Inequality operator to compare two InOrder iterators
template <typename T>
bool InOrderIterator<T>::operator!=(const InOrderIterator& other) const {
    // Check if either of the iterators has more nodes to process
    return !nodeStack.empty() || !other.nodeStack.empty();
}

// Dereference operator to access the value of the current node
template <typename T>
T& InOrderIterator<T>::operator*() {
    if (nodeStack.empty()) {
        throw std::runtime_error("Dereferencing end iterator."); // Error handling for dereferencing end
    }
    return nodeStack.top()->value; // Return the value of the current node
}

// Pre-increment operator to move the iterator to the next node in InOrder traversal
template <typename T>
InOrderIterator<T>& InOrderIterator<T>::operator++() {
    if (nodeStack.empty()) {
        throw std::runtime_error("Incrementing end iterator."); // Error handling for incrementing end
    }
    TreeNode<T>* node = nodeStack.top(); // Get the current node
    nodeStack.pop(); // Remove the current node from the stack

    // If the current node has a right child, push all its left children onto the stack
    if (!node->children.empty()) {
        if (node->children.size() > 1) {
            pushLeft(node->children[1]);
        } else {
            current = nullptr;
        }
    } else {
        current = nullptr;
    }

    return *this; // Return the iterator pointing to the next node
}
