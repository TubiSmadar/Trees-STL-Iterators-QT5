#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template <typename T>
class Node {
public:
    T value;
    std::vector<Node*> children;
    
    Node(const T& val) : value(val) {}
    T get_value() const { return value; }
};

#endif // NODE_HPP