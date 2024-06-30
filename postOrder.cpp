#include "postOrder.hpp"

template <typename T>
PostOrderIterator<T>::PostOrderIterator(Node<T>* root) : lastVisited(nullptr) {
    if (root) pushChildren(root);
}

template <typename T>
void PostOrderIterator<T>::pushChild(Node<T>* node) {
    stack.push(node);
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        pushChildren(*it);
    }
}

template <typename T>
bool PostOrderIterator<T>::operator!=(const PostOrderIterator& other) const {
    return !stack.empty() || !other.stack.empty();
}

template <typename T>
T& PostOrderIterator<T>::operator*() {
    return stack.top()->value;
}

template <typename T>
PostOrderIterator<T>& PostOrderIterator<T>::operator++() {
    lastVisited = stack.top();
    stack.pop();
    return *this;
}