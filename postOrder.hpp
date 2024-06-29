
#ifndef POSTORDER_HPP
#define POSTORDER_HPP

#include "node.hpp"
#include <stack>
using namespace std;

template <typename T>
class PostOrderIterator {
    private:
        std::stack<Node<T>*> stack;
        Node<T>* lastVisited;

        void pushChild(Node<T>* node);
    public:
        // Constructor
        PostOrderIterator(Node<T>* root);

        // Not equal operator
        bool operator!=(const PostOrderIterator& other) const;

        // Get value operator
        T& operator*();

        // Iterator operator
        PostOrderIterator& operator++();
};
#endif // POSTORDER_HPP