/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"
#include "preOrder.hpp"
#include "postOrder.hpp"
#include "inOrder.hpp"
#include "dfs.hpp"
#include "bfs.hpp"
using namespace std;

int main()
{
    Complex a(1.0,1.0);
    Complex b(2.0,1.0);
    Complex c(3.0,1.0);
    Complex d(4.0,1.0);
    Complex e(5.0,1.0);
    Complex f(6.0,1.0);
    Node<Complex> root(a);
    Node<Complex> nodeb(b);
    Node<Complex> nodec(c);
    Node<Complex> noded(d);
    Node<Complex> nodee(e);
    Node<Complex> nodef(f);

    Tree<Complex> tree;
    tree.add_root(root);
    tree.add_sub_node(root,nodeb);
    tree.add_sub_node(root,nodec);
    tree.add_sub_node(nodeb,noded);
    tree.add_sub_node(nodeb,nodee);
    tree.add_sub_node(nodec,nodef);

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO
        
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO
        
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO

    Node<double> root_node(1.0);
    Node<double> n1(1.1);
    Node<double> n2(1.2);
    Node<double> n3(1.3);
    Node<double> n4(1.4);
    Node<double> n5(1.5);
    
    Tree<double> three_ary_tree(3); // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);
    
    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO

    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO
        
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO
        
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO

    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node)
    {
        cout << *node << endl;
    } // prints: TODO

}
