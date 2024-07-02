// Tuvia Smadar
// gunslokij@gmail.com
#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"
#include "PreOrderIterator.hpp"
#include "PostOrderIterator.hpp"
#include "InOrderIterator.hpp"
#include "BFSIterator.hpp"
#include "DFSIterator.hpp"
#include "NodeItem.hpp"
#include "Complex.hpp"
#include <stdexcept>
#include <vector>
#include <queue>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <map>

// Template class for a generic k-ary tree
template <typename T, int K = 2>
class Tree {
private:
    TreeNode<T>* root; // Root node of the tree
    void heapify(TreeNode<T>* node); // Helper function to maintain heap property

public:
    // Constructor: initializes the tree
    Tree();
    
    // Destructor: deletes the tree
    ~Tree();
    
    // Adds a root node to the tree
    void add_root(T value);
    
    // Adds a sub-node to a given parent node
    void add_sub_node(TreeNode<T>* parent, T value);
    
    // Deletes the entire tree from a given node
    void delete_tree(TreeNode<T>* node);
    
    // Returns the root node of the tree
    TreeNode<T>* get_root();

    // Iterator functions for different traversal methods
    auto begin_pre_order();
    auto end_pre_order();
    auto begin_post_order();
    auto end_post_order();
    auto begin_in_order();
    auto end_in_order();
    BFSIterator<T> begin_bfs_scan();
    BFSIterator<T> end_bfs_scan();
    DFSIterator<T> begin_dfs_scan();
    DFSIterator<T> end_dfs_scan();

    // Function to transform the tree into a heap
    void myHeap();

    // Function to draw the tree using SFML
    void draw(sf::RenderWindow& window, const sf::Font& font) const;

    // Function to print the tree using SFML
    void printTree() const;

private:
    // Helper function to draw the tree nodes and edges
    void draw(sf::RenderWindow& window, TreeNode<T>* node, const sf::Font& font, int x, int y, int circleSize, int horizontalSpacing, int verticalSpacing, int depth) const;
    
    // Helper function to position the nodes for drawing
    void position_nodes(TreeNode<T>* node, float x, float y, float horizontal_spacing, float vertical_spacing, std::map<TreeNode<T>*, sf::Vector2f>& positions) const;
};

// Implementation of the Tree class methods

// Constructor: initializes the tree
template <typename T, int K>
Tree<T, K>::Tree() : root(nullptr) {}

// Destructor: deletes the tree
template <typename T, int K>
Tree<T, K>::~Tree() {
    delete_tree(root);
    root = nullptr;  // Ensure the root node is set to nullptr
}

// Deletes the entire tree from a given node
template <typename T, int K>
void Tree<T, K>::delete_tree(TreeNode<T>* node) {
    if (node) {
        for (auto child : node->children) {
            delete_tree(child);
        }
        delete node;
    }
    if (node == root) {
        root = nullptr;  // Ensure the root node is set to nullptr
    }
}

// Adds a root node to the tree
template <typename T, int K>
void Tree<T, K>::add_root(T value) {
    if (root) delete_tree(root);
    root = new TreeNode<T>(value);
}

// Adds a sub-node to a given parent node
template <typename T, int K>
void Tree<T, K>::add_sub_node(TreeNode<T>* parent, T value) {
    if (!parent) {
        throw std::invalid_argument("Parent node cannot be null");
    }
    if (parent->children.size() >= K) {
        throw std::overflow_error("Max children reached");
    }
    parent->children.push_back(new TreeNode<T>(value));
}

// Returns the root node of the tree
template <typename T, int K>
TreeNode<T>* Tree<T, K>::get_root() {
    if (root)
    {return root;}
    return nullptr;
}

// Iterator functions for different traversal methods
template <typename T, int K>
auto Tree<T, K>::begin_pre_order() {
    if constexpr (K == 2) {
        return PreOrderIterator<T>(root);
    } else {
        return DFSIterator<T>(root);
    }
}

template <typename T, int K>
auto Tree<T, K>::end_pre_order() {
    if constexpr (K == 2) {
        return PreOrderIterator<T>(nullptr);
    } else {
        return DFSIterator<T>(nullptr);
    }
}

template <typename T, int K>
auto Tree<T, K>::begin_post_order() {
    if constexpr (K == 2) {
        return PostOrderIterator<T>(root);
    } else {
        return DFSIterator<T>(root);
    }
}

template <typename T, int K>
auto Tree<T, K>::end_post_order() {
    if constexpr (K == 2) {
        return PostOrderIterator<T>(nullptr);
    } else {
        return DFSIterator<T>(nullptr);
    }
}

template <typename T, int K>
auto Tree<T, K>::begin_in_order() {
    if constexpr (K == 2) {
        return InOrderIterator<T>(root);
    } else {
        return DFSIterator<T>(root);
    }
}

template <typename T, int K>
auto Tree<T, K>::end_in_order() {
    if constexpr (K == 2) {
        return InOrderIterator<T>(nullptr);
    } else {
        return DFSIterator<T>(nullptr);
    }
}

template <typename T, int K>
BFSIterator<T> Tree<T, K>::begin_bfs_scan() {
    return BFSIterator<T>(root);
}

template <typename T, int K>
BFSIterator<T> Tree<T, K>::end_bfs_scan() {
    return BFSIterator<T>(nullptr);
}

template <typename T, int K>
DFSIterator<T> Tree<T, K>::begin_dfs_scan() {
    return DFSIterator<T>(root);
}

template <typename T, int K>
DFSIterator<T> Tree<T, K>::end_dfs_scan() {
    return DFSIterator<T>(nullptr);
}

// Helper function to maintain heap property
template <typename T, int K>
void Tree<T, K>::heapify(TreeNode<T>* node) {
    if (!node) return;
    for (auto child : node->children) {
        if (child && node->value > child->value) {
            std::swap(node->value, child->value);
            heapify(child);
        }
    }
}

// Function to transform the tree into a heap (only for binary trees)
template <typename T, int K>
void Tree<T, K>::myHeap() {
    if constexpr (K != 2) {
        throw std::logic_error("Heap functionality is only supported for binary trees");
    }

    if (!root) return;
    std::queue<TreeNode<T>*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode<T>* node = nodes.front();
        nodes.pop();
        heapify(node);
        for (auto child : node->children) {
            nodes.push(child);
        }
    }
}

// Function to draw the tree using SFML
template <typename T, int K>
void Tree<T, K>::draw(sf::RenderWindow& window, const sf::Font& font) const {
    if (!root) return;

    const float node_radius = 25.f;
    const float vertical_spacing = 80.f;
    const float initial_horizontal_spacing = 200.f;

    std::map<TreeNode<T>*, sf::Vector2f> positions;
    position_nodes(root, window.getSize().x / 2.f, node_radius + 50.f, initial_horizontal_spacing, vertical_spacing, positions);

    for (const auto& pair : positions) {
        TreeNode<T>* node = pair.first;
        sf::Vector2f position = pair.second;

        sf::CircleShape circle(node_radius);
        circle.setFillColor(sf::Color::Yellow);
        circle.setPosition(position - sf::Vector2f(node_radius, node_radius));
        window.draw(circle);

        sf::Text text;
        text.setFont(font);
        if constexpr (std::is_same<T, Complex>::value) {
            text.setString(node->value.to_string());
        } else {
            text.setString(std::to_string(node->value));
        }
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect text_bounds = text.getLocalBounds();
        text.setOrigin(text_bounds.left + text_bounds.width / 2.0f, text_bounds.top + text_bounds.height / 2.0f);
        text.setPosition(position);
        window.draw(text);

        for (TreeNode<T>* child : node->children) {
            if (child) {
                sf::Vector2f child_position = positions[child];
                sf::Vertex line[] =
                {
                    sf::Vertex(position, sf::Color::Black),
                    sf::Vertex(child_position, sf::Color::Black)
                };
                window.draw(line, 2, sf::Lines);
            }
        }
    }
}

// Function to print the tree using SFML
template <typename T, int K>
void Tree<T, K>::printTree() const {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        draw(window, font);
        window.display();
    }
}

// Helper function to position the nodes for drawing
template <typename T, int K>
void Tree<T, K>::position_nodes(TreeNode<T>* node, float x, float y, float horizontal_spacing, float vertical_spacing, std::map<TreeNode<T>*, sf::Vector2f>& positions) const {
    if (!node) return;

    positions[node] = sf::Vector2f(x, y);

    float child_x_offset = x - (node->children.size() - 1) * horizontal_spacing / 2.f;

    for (size_t i = 0; i < node->children.size(); ++i) {
        TreeNode<T>* child = node->children[i];
        if (child) {
            position_nodes(child, child_x_offset + i * horizontal_spacing, y + vertical_spacing, horizontal_spacing / 2.f, vertical_spacing, positions);
        }
    }
}

#endif // TREE_HPP
