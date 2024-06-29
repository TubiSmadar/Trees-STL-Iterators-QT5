#ifndef DFS_HPP
#define DFS_HPP

#include "node.hpp"
#include <stack>

template <typename T>
class DFSIterator {
private:
    std::stack<Node<T>*> stack;
public:
    DFSIterator(Node<T>* root);
    bool operator!=(const DFSIterator& other) const;
    T& operator*();
    DFSIterator& operator++();
};

#include "dfs.cpp"
#endif // DFS_HPP