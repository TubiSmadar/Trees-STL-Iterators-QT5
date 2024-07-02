// Tuvia Smadar
// gunslokij@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Complex.hpp"

// Test for Tree<int>
TEST_CASE("Testing Tree<int>") {
    Tree<int, 2> intTree; // Binary tree
    intTree.add_root(1);
    TreeNode<int>* root = intTree.get_root();
    intTree.add_sub_node(root, 2);
    intTree.add_sub_node(root, 3);
    TreeNode<int>* n1 = root->children[0];
    TreeNode<int>* n2 = root->children[1];
    intTree.add_sub_node(n1, 4);
    intTree.add_sub_node(n1, 5);
    intTree.add_sub_node(n2, 6);

    SUBCASE("Check for Node Existence") {
        CHECK(intTree.get_root() != nullptr);
        CHECK(n1->children[0]->value == 4);
        CHECK(n1->children[1]->value == 5);
    }

    SUBCASE("Sum of Nodes Check") {
        int sum = 0;
        for (auto it = intTree.begin_bfs_scan(); it != intTree.end_bfs_scan(); ++it) {
            sum += *it;
        }
        CHECK(sum == 21); // 1 + 2 + 3 + 4 + 5 + 6
    }

    SUBCASE("Clear Tree Check") {
        intTree.delete_tree(intTree.get_root());
        CHECK(intTree.get_root() == nullptr);
    }

    SUBCASE("Heap Functionality") {
        intTree.myHeap();
        std::vector<int> result;
        for (auto it = intTree.begin_bfs_scan(); it != intTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {1, 2, 3, 4, 5, 6}; 
        CHECK(result == expected);
    }
}

// Test for Tree<double>
TEST_CASE("Testing Tree<double>") {
    Tree<double, 2> doubleTree; // Binary tree
    doubleTree.add_root(1.1);
    TreeNode<double>* root = doubleTree.get_root();
    doubleTree.add_sub_node(root, 2.2);
    doubleTree.add_sub_node(root, 3.3);
    TreeNode<double>* n1 = root->children[0];
    TreeNode<double>* n2 = root->children[1];
    doubleTree.add_sub_node(n1, 4.4);
    doubleTree.add_sub_node(n1, 5.5);
    doubleTree.add_sub_node(n2, 6.6);

    SUBCASE("Check for Node Existence") {
        CHECK(doubleTree.get_root() != nullptr);
        CHECK(n1->children[0]->value == 4.4);
        CHECK(n1->children[1]->value == 5.5);
    }

    SUBCASE("Clear Tree Check") {
        doubleTree.delete_tree(doubleTree.get_root());
        CHECK(doubleTree.get_root() == nullptr);
    }

    SUBCASE("Heap Functionality") {
        doubleTree.myHeap();
        std::vector<double> result;
        for (auto it = doubleTree.begin_bfs_scan(); it != doubleTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<double> expected = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6}; 
        CHECK(result == expected);
    }
}

// Test for Tree<Complex>
TEST_CASE("Testing Tree<Complex>") {
    Tree<Complex, 2> complexTree; // Binary tree
    complexTree.add_root(Complex(1.0, 1.0));
    TreeNode<Complex>* root = complexTree.get_root();
    complexTree.add_sub_node(root, Complex(2.0, 2.0));
    complexTree.add_sub_node(root, Complex(3.0, 3.0));
    TreeNode<Complex>* n1 = root->children[0];
    TreeNode<Complex>* n2 = root->children[1];
    complexTree.add_sub_node(n1, Complex(4.0, 4.0));
    complexTree.add_sub_node(n1, Complex(5.0, 5.0));
    complexTree.add_sub_node(n2, Complex(6.0, 6.0));

    SUBCASE("Check for Node Existence") {
        CHECK(complexTree.get_root() != nullptr);
        CHECK(n1->children[0]->value == Complex(4.0, 4.0));
        CHECK(n1->children[1]->value == Complex(5.0, 5.0));
    }

    SUBCASE("Clear Tree Check") {
        complexTree.delete_tree(complexTree.get_root());
        CHECK(complexTree.get_root() == nullptr);
    }

    SUBCASE("Heap Functionality") {
        complexTree.myHeap();
        std::vector<Complex> result;
        for (auto it = complexTree.begin_bfs_scan(); it != complexTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<Complex> expected = {Complex(1.0, 1.0), Complex(2.0, 2.0), Complex(3.0, 3.0), Complex(4.0, 4.0), Complex(5.0, 5.0), Complex(6.0, 6.0)};
        CHECK(result == expected);
    }
}

// Test for Tree<char>
TEST_CASE("Testing Tree<char>") {
    Tree<char, 2> charTree; // Binary tree
    charTree.add_root('A');
    TreeNode<char>* root = charTree.get_root();
    charTree.add_sub_node(root, 'B');
    charTree.add_sub_node(root, 'C');
    TreeNode<char>* n1 = root->children[0];
    TreeNode<char>* n2 = root->children[1];
    charTree.add_sub_node(n1, 'D');
    charTree.add_sub_node(n1, 'E');
    charTree.add_sub_node(n2, 'F');

    SUBCASE("Check for Node Existence") {
        CHECK(charTree.get_root() != nullptr);
        CHECK(n1->children[0]->value == 'D');
        CHECK(n1->children[1]->value == 'E');
    }

    SUBCASE("Concatenation of Nodes Check") {
        std::string concatenation;
        for (auto it = charTree.begin_bfs_scan(); it != charTree.end_bfs_scan(); ++it) {
            concatenation += *it;
        }
        CHECK(concatenation == "ABCDEF");
    }

    SUBCASE("Clear Tree Check") {
        charTree.delete_tree(charTree.get_root());
        CHECK(charTree.get_root() == nullptr);
    }
}

// Test for Tree<std::string>
TEST_CASE("Testing Tree<std::string>") {
    Tree<std::string, 2> stringTree; // Binary tree
    stringTree.add_root("root");
    TreeNode<std::string>* root = stringTree.get_root();
    stringTree.add_sub_node(root, "child1");
    stringTree.add_sub_node(root, "child2");
    TreeNode<std::string>* n1 = root->children[0];
    TreeNode<std::string>* n2 = root->children[1];
    stringTree.add_sub_node(n1, "child3");
    stringTree.add_sub_node(n1, "child4");
    stringTree.add_sub_node(n2, "child5");

    SUBCASE("Check for Node Existence") {
        CHECK(stringTree.get_root() != nullptr);
        CHECK(n1->children[0]->value == "child3");
        CHECK(n1->children[1]->value == "child4");
    }

    SUBCASE("Concatenation of Nodes Check") {
        std::string concatenation;
        for (auto it = stringTree.begin_bfs_scan(); it != stringTree.end_bfs_scan(); ++it) {
            concatenation += *it + " ";
        }
        CHECK(concatenation == "root child1 child2 child3 child4 child5 ");
    }

    SUBCASE("Clear Tree Check") {
        stringTree.delete_tree(stringTree.get_root());
        CHECK(stringTree.get_root() == nullptr);
    }
}

// Test for PreOrderIterator
TEST_CASE("Testing PreOrderIterator") {
    Tree<int, 2> intTree;
    intTree.add_root(1);
    TreeNode<int>* root = intTree.get_root();
    intTree.add_sub_node(root, 2);
    intTree.add_sub_node(root, 3);
    TreeNode<int>* n1 = root->children[0];
    TreeNode<int>* n2 = root->children[1];
    intTree.add_sub_node(n1, 4);
    intTree.add_sub_node(n1, 5);
    intTree.add_sub_node(n2, 6);

    std::vector<int> result;
    for (auto it = intTree.begin_pre_order(); it != intTree.end_pre_order(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {1, 2, 4, 5, 3, 6};
    CHECK(result == expected);
}

// Test for PostOrderIterator
TEST_CASE("Testing PostOrderIterator") {
    Tree<int, 2> intTree;
    intTree.add_root(1);
    TreeNode<int>* root = intTree.get_root();
    intTree.add_sub_node(root, 2);
    intTree.add_sub_node(root, 3);
    TreeNode<int>* n1 = root->children[0];
    TreeNode<int>* n2 = root->children[1];
    intTree.add_sub_node(n1, 4);
    intTree.add_sub_node(n1, 5);
    intTree.add_sub_node(n2, 6);

    std::vector<int> result;
    for (auto it = intTree.begin_post_order(); it != intTree.end_post_order(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {4, 5, 2, 6, 3, 1};
    CHECK(result == expected);
}

// Test for InOrderIterator
TEST_CASE("Testing InOrderIterator") {
    Tree<int, 2> intTree;
    intTree.add_root(1);
    TreeNode<int>* root = intTree.get_root();
    intTree.add_sub_node(root, 2);
    intTree.add_sub_node(root, 3);
    TreeNode<int>* n1 = root->children[0];
    TreeNode<int>* n2 = root->children[1];
    intTree.add_sub_node(n1, 4);
    intTree.add_sub_node(n1, 5);
    intTree.add_sub_node(n2, 6);

    std::vector<int> result;
    for (auto it = intTree.begin_in_order(); it != intTree.end_in_order(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {4, 2, 5, 1, 6, 3};
    CHECK(result == expected);
}

// Test for BFSIterator
TEST_CASE("Testing BFSIterator") {
    Tree<int, 2> intTree;
    intTree.add_root(1);
    TreeNode<int>* root = intTree.get_root();
    intTree.add_sub_node(root, 2);
    intTree.add_sub_node(root, 3);
    TreeNode<int>* n1 = root->children[0];
    TreeNode<int>* n2 = root->children[1];
    intTree.add_sub_node(n1, 4);
    intTree.add_sub_node(n1, 5);
    intTree.add_sub_node(n2, 6);

    std::vector<int> result;
    for (auto it = intTree.begin_bfs_scan(); it != intTree.end_bfs_scan(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    CHECK(result == expected);
}

// Test for DFSIterator
TEST_CASE("Testing DFSIterator") {
    Tree<int, 2> intTree;
    intTree.add_root(1);
    TreeNode<int>* root = intTree.get_root();
    intTree.add_sub_node(root, 2);
    intTree.add_sub_node(root, 3);
    TreeNode<int>* n1 = root->children[0];
    TreeNode<int>* n2 = root->children[1];
    intTree.add_sub_node(n1, 4);
    intTree.add_sub_node(n1, 5);
    intTree.add_sub_node(n2, 6);

    std::vector<int> result;
    for (auto it = intTree.begin_dfs_scan(); it != intTree.end_dfs_scan(); ++it) {
        result.push_back(*it);
    }
    std::vector<int> expected = {1, 2, 4, 5, 3, 6};
    CHECK(result == expected);
}
