#include "preOrder.hpp"

template <typename T>
PreOrderIterator<T>::PreOrderIterator(Node<T>* root) {
    if (root) {
        stack.push(root);
    }
}

template <typename T>
bool PreOrderIterator<T>::operator!=(const PreOrderIterator& other) const {
    return !stack.empty() || !other.stack.empty();
}

template <typename T>
T& PreOrderIterator<T>::operator*() {
    return stack.top()->value;
}

template <typename T>
PreOrderIterator<T>& PreOrderIterator<T>::operator++() {
    Node<T>* node = stack.top();
    stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        stack.push(*it);
    }
    return *this;
}