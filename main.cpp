// Tuvia Smadar
// gunslokij@gmail.com
#include "Tree.hpp"
#include "Complex.hpp"
#include "TreeNode.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Creating and populating a binary tree with doubles
    Tree<double, 2> doubleTree; // Binary tree that contains doubles.
    doubleTree.add_root(1.1);

    doubleTree.add_sub_node(doubleTree.get_root(), 1.2);
    doubleTree.add_sub_node(doubleTree.get_root(), 1.3);
    TreeNode<double>* doubleNode1 = doubleTree.get_root()->children[0];
    TreeNode<double>* doubleNode2 = doubleTree.get_root()->children[1];
    doubleTree.add_sub_node(doubleNode1, 1.4);
    doubleTree.add_sub_node(doubleNode1, 1.5);
    doubleTree.add_sub_node(doubleNode2, 1.6);

    // Pre-Order traversal
    cout << "Pre-Order: ";
    for (auto it = doubleTree.begin_pre_order(); it != doubleTree.end_pre_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Post-Order traversal
    cout << "Post-Order: ";
    for (auto it = doubleTree.begin_post_order(); it != doubleTree.end_post_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // In-Order traversal
    cout << "In-Order: ";
    for (auto it = doubleTree.begin_in_order(); it != doubleTree.end_in_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // BFS traversal
    cout << "BFS: ";
    for (auto it = doubleTree.begin_bfs_scan(); it != doubleTree.end_bfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Creating and populating a 3-ary tree with doubles
    Tree<double, 3> threeAryDoubleTree;
    threeAryDoubleTree.add_root(1.1);

    threeAryDoubleTree.add_sub_node(threeAryDoubleTree.get_root(), 1.2);
    threeAryDoubleTree.add_sub_node(threeAryDoubleTree.get_root(), 1.3);
    threeAryDoubleTree.add_sub_node(threeAryDoubleTree.get_root(), 1.4);
    threeAryDoubleTree.add_sub_node(threeAryDoubleTree.get_root()->children[0], 1.5);
    threeAryDoubleTree.add_sub_node(threeAryDoubleTree.get_root()->children[1], 1.6);

    // BFS traversal of the 3-ary tree
    cout << "3-ary Tree BFS: ";
    try {
        for (auto it = threeAryDoubleTree.begin_bfs_scan(); it != threeAryDoubleTree.end_bfs_scan(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    } catch (const std::exception& e) {
        cerr << "Exception during BFS traversal of threeAryDoubleTree: " << e.what() << endl;
    }

    // Print the trees using SFML
    doubleTree.printTree();
    threeAryDoubleTree.printTree();

    return 0;
}
