#include "inOrder.hpp"

template <typename T>
InOrderIterator<T>::InOrderIterator(Node<T>* root) : current(root) {
    pushLeftChild(root);
}

template <typename T>
void InOrderIterator<T>::pushLeftChild(Node<T>* node) {
    while (node) {
        stack.push(node);
        if (!node->children.empty()) {
            node = node->children[0];
        } else {
            break;
        }
    }
}

template <typename T>
bool InOrderIterator<T>::operator!=(const InOrderIterator& other) const {
    return !stack.empty() || !other.stack.empty();
}

template <typename T>
T& InOrderIterator<T>::operator*() {
    return stack.top()->value;
}

template <typename T>
InOrderIterator<T>& InOrderIterator<T>::operator++() {
    TreeNode<T>* node = stack.top();
    stack.pop();

    if (!node->children.empty()) {
        if (node->children.size() > 1) {
            pushLeft(node->children[1]);
        } else {
            current = nullptr;
        }
    } else {
        current = nullptr;
    }

    return *this;
}