#ifndef BFS_CPP
#define BFS_CPP
#include "bfs.hpp"

template <typename T>
BFSIterator<T>::BFSIterator(Node<T>* root) {
    if (root) {
        queue.push(root);
    }
}

template <typename T>
bool BFSIterator<T>::operator!=(const BFSIterator& other) const {
    return !queue.empty() || !other.queue.empty();
}

template <typename T>
T& BFSIterator<T>::operator*() {
    return queue.front()->value;
}

template <typename T>
BFSIterator<T>& BFSIterator<T>::operator++() {
    Node<T>* node = queue.front();
    queue.pop();
    for (auto child : node->children) {
        queue.push(child);
    }
    return *this;
}
#endif