// Tuvia Smadar
// gunslokij@gmail.com
#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <vector>
#include <string>
#include <sstream>

// Template class for a tree node
template <typename T>
class TreeNode {
public:
    T value; // Value stored in the node
    std::vector<TreeNode<T>*> children; // Children of the node

    // Constructor to initialize the node with a value
    TreeNode(T val) : value(val) {}

    // Converts the node's value to a string
    std::string to_str() const {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }

    // Converts the node's value to a short string (same as to_str)
    std::string to_short_string() const {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }
};

#endif // TREENODE_HPP
