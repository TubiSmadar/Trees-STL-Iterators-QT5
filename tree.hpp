#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "preOrder.hpp"
#include "postOrder.hpp"
#include "inOrder.hpp"
#include "dfs.hpp"
#include "bfs.hpp"
#include <stdexcept>
#include <vector>
#include <queue>
#include <algorithm>

template <typename T>
class Tree {
private:
    Node<T>* root;
    size_t k;
    void heapify(Node<T>* node);

public:
    Tree(size_t max_children = 2);
    ~Tree();
    void add_root(const Node<T>& value);
    void add_sub_node(Node<T> parent, const Node<T>& value);
    void delete_tree(Node<T>* node);
    Node<T>* get_root();

    PreOrderIterator<T> begin_pre_order();
    PreOrderIterator<T> end_pre_order();
    PostOrderIterator<T> begin_post_order();
    PostOrderIterator<T> end_post_order();
    InOrderIterator<T> begin_in_order();
    InOrderIterator<T> end_in_order();
    BFSIterator<T> begin_bfs_scan();
    BFSIterator<T> end_bfs_scan();
    DFSIterator<T> begin_dfs_scan();
    DFSIterator<T> end_dfs_scan();
    void myHeap();
};

// Definitions of template methods

template <typename T>
Tree<T>::Tree(size_t max_children) : root(nullptr), k(max_children) {}

template <typename T>
Tree<T>::~Tree() {
    delete_tree(root);
}

template <typename T>
void Tree<T>::delete_tree(Node<T>* node) {
    if (node) {
        for (auto child : node->children) {
            delete_tree(child);
        }
        delete node;
    }
}

template <typename T>
void Tree<T>::add_root(const Node<T>& value) {
    if (root) delete_tree(root);
    root = new Node<T>(value);
}

template <typename T>
void Tree<T>::add_sub_node(Node<T> parent, const Node<T>& value) {
    if (parent.children.size() >= k) {
        throw std::overflow_error("Max children reached");
    }
    Node<T>* newNode = new Node<T>(value);
    parent.children.push_back(newNode);
}

template <typename T>
Node<T>* Tree<T>::get_root() {
    return root;
}

template <typename T>
PreOrderIterator<T> Tree<T>::begin_pre_order() {
    return PreOrderIterator<T>(root);
}

template <typename T>
PreOrderIterator<T> Tree<T>::end_pre_order() {
    return PreOrderIterator<T>(nullptr);
}

template <typename T>
PostOrderIterator<T> Tree<T>::begin_post_order() {
    return PostOrderIterator<T>(root);
}

template <typename T>
PostOrderIterator<T> Tree<T>::end_post_order() {
    return PostOrderIterator<T>(nullptr);
}

template <typename T>
InOrderIterator<T> Tree<T>::begin_in_order() {
    return InOrderIterator<T>(root);
}

template <typename T>
InOrderIterator<T> Tree<T>::end_in_order() {
    return InOrderIterator<T>(nullptr);
}

template <typename T>
BFSIterator<T> Tree<T>::begin_bfs_scan() {
    return BFSIterator<T>(root);
}

template <typename T>
BFSIterator<T> Tree<T>::end_bfs_scan() {
    return BFSIterator<T>(nullptr);
}

template <typename T>
DFSIterator<T> Tree<T>::begin_dfs_scan() {
    return DFSIterator<T>(root);
}

template <typename T>
DFSIterator<T> Tree<T>::end_dfs_scan() {
    return DFSIterator<T>(nullptr);
}

template <typename T>
void Tree<T>::heapify(Node<T>* node) {
    if (!node) return;
    for (auto child : node->children) {
        if (child && node->value > child->value) {
            std::swap(node->value, child->value);
            heapify(child);
        }
    }
}

template <typename T>
void Tree<T>::myHeap() {
    if (!root) return;
    std::queue<Node<T>*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        Node<T>* node = nodes.front();
        nodes.pop();
        heapify(node);
        for (auto child : node->children) {
            nodes.push(child);
        }
    }
}

#endif // TREE_HPP
