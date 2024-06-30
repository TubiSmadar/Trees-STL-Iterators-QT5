#ifndef BFS_HPP
#define BFS_HPP

#include "node.hpp"
#include <queue>

template <typename T>
class BFSIterator {
private:
    std::queue<Node<T>*> queue;
public:
    BFSIterator(Node<T>* root);
    bool operator!=(const BFSIterator& other) const;
    T& operator*();
    BFSIterator& operator++();
};

#include "bfs.cpp"
#endif // BFS_HPP