//
// Created by Bogdan Zarnescu on 16.05.2022.
//

#ifndef SDA_PROFIECT_FINAL_BINARYTREE_H
#define SDA_PROFIECT_FINAL_BINARYTREE_H

#include "BinaryTreeNode.h"

template<class T> class BinaryTree {
private:
    BinaryTreeNode<T> *root;
    int size;

    /**
     * Add element in the tree.
     * @param ad type BinaryTreeNode<T> *
     * @param elem type T
     */
    void add(BinaryTreeNode<T> *ad, T elem) {
        if(ad->info > elem) {
            if(ad->left != nullptr) {
                add(ad->left, elem);
            } else {
                ad->left = new BinaryTreeNode<T>(elem, nullptr, nullptr);
            }
        } else {
            if(ad->right != nullptr) {
                add(ad->right, elem);
            } else {
                ad->right = new BinaryTreeNode<T>(elem, nullptr, nullptr);
            }
        }
    }

    /**
     * Shows all entities in the tree.
     * @param ad BinaryTreeNode<T> *
     */
    void showInOrder(BinaryTreeNode<T> *ad) {
        if(ad != nullptr) {
            showInOrder(ad->left);
            cout << ad->info << endl;
            showInOrder(ad->right);
        }
    }

    /**
     * Gets next minimum succesor in the tree.
     * @param ad BinaryTreeNode<T> *
     * @return next minimum succesor
     */
    BinaryTreeNode<T> *minValueNode(BinaryTreeNode<T> *ad) {
        BinaryTreeNode<T> *current = ad;
        while(current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    /**
     * Delete element from the tree.
     * @param ad BinaryTreeNode<T> *
     * @param elem type T
     * @return the new tree
     */
    BinaryTreeNode<T> *deleteElem(BinaryTreeNode<T> *ad, T elem) {
        if(ad == NULL) {
            return ad;
        }
        if(ad->info > elem) {
            ad->left = deleteElem(ad->left, elem);
        } else if(ad->info < elem) {
            ad->right = deleteElem(ad->right, elem);
        } else {
            if(ad->left == NULL and ad->right == NULL) {
                return NULL;
            } else if(ad->left == NULL) {
                BinaryTreeNode<T> *temp = ad->right;
                free(ad);
                return temp;
            } else if(ad->right == NULL) {
                BinaryTreeNode<T> *temp = ad->left;
                free(ad);
                return temp;
            }
            BinaryTreeNode<T> *temp = minValueNode(ad->right);
            ad->info = temp->info;
            ad->right = deleteElem(ad->right, temp->info);
        }
        return ad;
    }

    /**
     * Search element in the tree.
     * @param ad BinaryTreeNode<T> *
     * @param elem type T
     * @return true or false
     */
    bool searchElem(BinaryTreeNode<T> *ad, T elem) {
        if(ad->info == elem) {
            return true;
        } else if(ad->info > elem) {
            if(ad->left != nullptr) {
                return searchElem(ad->left, elem);
            }
        } else {
            if(ad->right != nullptr) {
                return searchElem(ad->right, elem);
            }
        }
        return false;
    }

public:
    /**
     * Binary tree constructor.
     */
    BinaryTree() {
        this->root = nullptr;
        this->size = 0;
    }

    /**
     * Add element in the tree.
     * @param elem type T
     */
    void add(T elem) {
        if(this->root == nullptr) {
            this->root = new BinaryTreeNode<T>(elem, nullptr, nullptr);
            this->size++;
        } else {
            add(this->root, elem);
            this->size++;
        }
    }

    /**
     * Show the tree.
     */
    void show() {
        showInOrder(this->root);
    }

    /**
     * Delete element in the tree.
     * @param elem type T
     */
    void deleteElem(T elem) {
        if(searchElem(elem)) {
            this->root = deleteElem(this->root, elem);
            this->size--;
        }
    }

    /**
     * Search element in the tree.
     * @param elem type T
     * @return true or false
     */
    bool searchElem(T elem) {
        if(this->root == nullptr) {
            return false;
        } else {
            return searchElem(this->root, elem);
        }
    }

    /**
     * Gets size of tree.
     * @return size of tree
     */
    int sizeBinaryTree() {
        return this->size;
    }
};

#endif //SDA_PROFIECT_FINAL_BINARYTREE_H
