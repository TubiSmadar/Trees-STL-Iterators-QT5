#ifndef INORDER_HPP
#define INORDER_HPP
#include "node.hpp"
#include <stack>
#include <cstddef>

template <typename T>
class InOrderIterator {
private:
    std::stack<Node<T>*> stack;
    Node<T>* current;
    void pushLeftChild(Node<T>* node);
public:
    InOrderIterator(Node<T>* root);
    bool operator!=(const InOrderIterator& other) const;
    T& operator*();
    InOrderIterator& operator++();
};

#endif // INORDERITERATOR_HPP