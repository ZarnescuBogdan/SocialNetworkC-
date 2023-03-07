//
// Created by Bogdan Zarnescu on 16.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_BINARYTREENODE_H
#define SDA_PROFIECT_FINAL_BINARYTREENODE_H

#include <iostream>

using namespace std;

template<typename T> class BinaryTree;

template<class T> class BinaryTreeNode {
private:
    T info;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
public:
    BinaryTreeNode(T info1) : info(info1) {
        this->left = nullptr;
        this->right = nullptr;
    }
    BinaryTreeNode(T info1, BinaryTreeNode<T> *left1, BinaryTreeNode<T> *right1) : info(info1), left(left1), right(right1) {}
    friend class BinaryTree<T>;
    BinaryTreeNode<T> &operator=(const BinaryTreeNode<T> &binaryTree) {
        this->info = binaryTree.info;
        this->left = binaryTree.left;
        this->right = binaryTree.right;
    }
};

#endif //SDA_PROFIECT_FINAL_BINARYTREENODE_H
