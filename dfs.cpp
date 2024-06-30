#ifndef DFS_CPP
#define DFS_CPP

#include "dfs.hpp"

template <typename T>
DFSIterator<T>::DFSIterator(Node<T>* root) {
    if (root) {
        stack.push(root);
    }
}

template <typename T>
bool DFSIterator<T>::operator!=(const DFSIterator& other) const {
    return !stack.empty() || !other.stack.empty();
}

template <typename T>
T& DFSIterator<T>::operator*() {
    return stack.top()->value;
}

template <typename T>
DFSIterator<T>& DFSIterator<T>::operator++() {
    Node<T>* node = stack.top();
    stack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        stack.push(*it);
    }
    return *this;
}
#endif