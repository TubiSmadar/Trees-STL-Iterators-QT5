
#ifndef PREORDER_HPP
#define PREORDER_HPP

#include "node.hpp"
#include <stack>
using namespace std;

template <typename T>
class PreOrderIterator {
    private:
        std::stack<Node<T>*> stack;
    public:
        // Constructor
        PreOrderIterator(Node<T>* root);

        // Not equal operator
        bool operator!=(const PreOrderIterator& other) const;

        // Get value operator
        T& operator*();

        // Iterator operator
        PreOrderIterator& operator++();
};
#endif // PREORDER_HPP