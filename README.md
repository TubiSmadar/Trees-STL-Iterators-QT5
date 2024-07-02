# Tree Visualization and Traversal

## Overview

This project implements a generic k-ary tree data structure in C++, which supports various tree traversal algorithms (pre-order, post-order, in-order, breadth-first search (BFS), and depth-first search (DFS)). It also includes a graphical visualization of the tree using the SFML library. The tree can store different types of data, including integers, doubles, characters, strings, and complex numbers.

## Features

- **Generic k-ary Tree**: A flexible tree structure where each node can have up to k children.
- **Traversal Algorithms**: Support for pre-order, post-order, in-order, BFS, and DFS traversals.
- **Heap Transformation**: Functionality to transform the tree into a heap.
- **Graphical Visualization**: Visual representation of the tree using SFML.
- **Comprehensive Tests**: Unit tests to validate the functionality of the tree and its operations.

## Dependencies

- **C++17**: The project uses features from C++17.
- **SFML**: The Simple and Fast Multimedia Library is used for graphical visualization. You can install SFML on Ubuntu using the following command:
    ```
    sudo apt-get install libsfml-dev
    ```

- **doctest**: A testing framework for C++. You can include it as a single header in your project.

## Installation

Clone the repository:
    ```
    git clone https://github.com/TubiSmadar/yourrepository.git
    cd yourrepository
    ```

Compile the project:
    ```
    make
    ```

## Usage
### Running the Tree Visualization

To run the tree visualization, execute the tree binary:

    ```
    ./tree
    ```

### Running Tests

To run the unit tests, execute the test binary:

    ```
    ./test
    ```

## File Structure

- **main.cpp**: Entry point for the tree visualization application.
- **Tree.hpp**: Definition and implementation of the generic k-ary tree class.
- **TreeNode.hpp**: Definition of the tree node class.
- **Iterators**: Various iterator classes for different traversal methods.
-   **PreOrderIterator.hpp**
-   **PostOrderIterator.hpp**
-   **InOrderIterator.hpp**
-   **BFSIterator.hpp**
-   **DFSIterator.hpp**
- **NodeItem.hpp**: Class for representing a tree node in the graphical visualization.
- **Complex.hpp**: Class for representing complex numbers.
- **tests.cpp**: Unit tests for the tree and its operations.
- **Makefile**: Build configuration.

## Detailed Description
### Tree Class

The Tree class template defines a k-ary tree, where each node can have up to k children. It supports the following operations:

-    **add_root**(T value): Adds a root node with the specified value.
-    **add_sub_node(TreeNode<T> parent, T value)**: Adds a sub-node with the specified value to the given parent node.
-    **get_root()**: Returns the root node of the tree.
-    **delete_tree(TreeNode<T> node)**: Recursively deletes the subtree starting from the given node.
-    **myHeap()**: Transforms the tree into a heap.
-    **draw(sf::RenderWindow& window, const sf::Font& font) const**: Draws the tree using SFML.

### Iterators

The tree supports various traversal algorithms through iterators:

-    **PreOrderIterator**
-    **PostOrderIterator**
-    **InOrderIterator**
-    **BFSIterator**
-    **DFSIterator**

### Visualization

The project uses SFML to visualize the tree. Nodes are represented as circles, and edges are drawn as lines connecting the nodes. The tree is positioned and drawn on an SFML window.
Testing

Unit tests are written using the `doctest` framework. The tests cover:

-    Tree creation and node addition
-    Traversal algorithms
-    Tree structure validation
-    Edge cases and error handling