// Tuvia Smadar
// gunslokij@gmail.com
#ifndef POSTORDERITERATOR_HPP
#define POSTORDERITERATOR_HPP

#include "TreeNode.hpp"
#include <stack>

// PostOrderIterator class template for post-order traversal of a tree
template <typename T>
class PostOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack; // Stack to manage nodes for post-order traversal
    TreeNode<T>* lastVisitedNode; // Pointer to the last visited node

    // Helper function to push all children of a node onto the stack in reverse order
    void pushChildren(TreeNode<T>* node);

public:
    // Constructor: initializes the iterator with the root node
    PostOrderIterator(TreeNode<T>* root);

    // Inequality operator: checks if two iterators are not equal
    bool operator!=(const PostOrderIterator& other) const;

    // Dereference operator: returns the value of the current node
    T& operator*();

    // Pre-increment operator: moves the iterator to the next node
    PostOrderIterator& operator++();
};

#include "PostOrderIterator.cpp"
#endif // POSTORDERITERATOR_HPP
