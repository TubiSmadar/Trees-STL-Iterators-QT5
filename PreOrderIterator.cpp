// Tuvia Smadar
// gunslokij@gmail.com
#include "PreOrderIterator.hpp"

// Constructor for PreOrderIterator: initializes with the root node
template <typename T>
PreOrderIterator<T>::PreOrderIterator(TreeNode<T>* root) {
    if (root) {
        nodeStack.push(root); // Push the root node onto the stack
    }
}

// Inequality operator to compare two PreOrder iterators
template <typename T>
bool PreOrderIterator<T>::operator!=(const PreOrderIterator& other) const {
    // Check if either of the iterators has more nodes to process
    return !nodeStack.empty() || !other.nodeStack.empty();
}

// Dereference operator to access the value of the current node
template <typename T>
T& PreOrderIterator<T>::operator*() {
    return nodeStack.top()->value; // Return the value of the current node
}

// Pre-increment operator to move the iterator to the next node in pre-order traversal
template <typename T>
PreOrderIterator<T>& PreOrderIterator<T>::operator++() {
    TreeNode<T>* currentNode = nodeStack.top(); // Get the current node
    nodeStack.pop(); // Remove the current node from the stack

    // Push children of the current node onto the stack in reverse order
    for (auto it = currentNode->children.rbegin(); it != currentNode->children.rend(); ++it) {
        nodeStack.push(*it);
    }

    return *this; // Return the iterator pointing to the next node
}
