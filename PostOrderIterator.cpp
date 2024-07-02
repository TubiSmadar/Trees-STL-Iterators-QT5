// Tuvia Smadar
// gunslokij@gmail.com
#include "PostOrderIterator.hpp"

// Constructor for PostOrderIterator: initializes with the root node
template <typename T>
PostOrderIterator<T>::PostOrderIterator(TreeNode<T>* root) : lastVisitedNode(nullptr) {
    if (root) pushChildren(root);
}

// Helper function to push all children of a node onto the stack in reverse order
template <typename T>
void PostOrderIterator<T>::pushChildren(TreeNode<T>* node) {
    nodeStack.push(node);
    // Push children in reverse order to ensure correct post-order traversal
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        pushChildren(*it);
    }
}

// Inequality operator to compare two PostOrder iterators
template <typename T>
bool PostOrderIterator<T>::operator!=(const PostOrderIterator& other) const {
    // Check if either of the iterators has more nodes to process
    return !nodeStack.empty() || !other.nodeStack.empty();
}

// Dereference operator to access the value of the current node
template <typename T>
T& PostOrderIterator<T>::operator*() {
    return nodeStack.top()->value; // Return the value of the current node
}

// Pre-increment operator to move the iterator to the next node in post-order traversal
template <typename T>
PostOrderIterator<T>& PostOrderIterator<T>::operator++() {
    lastVisitedNode = nodeStack.top(); // Update the last visited node
    nodeStack.pop(); // Remove the current node from the stack
    return *this; // Return the iterator pointing to the next node
}
