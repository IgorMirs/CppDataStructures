#include "AVLTree.h"
#include <iostream>
#include <algorithm>

using std::max;

template <typename T>
AVLTree<T>::AVLTree() : root (nullptr) {}

template <typename T>
void AVLTree<T>::print() const {
    print("", root, false);
}

template <typename T>
void AVLTree<T>::print(const std::string& prefix, const AVLNode<T>* node, bool isRight) const {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isRight ? "R--" : "L--");

        //get balance
        int h_l = get_height(node->left);
        int h_r = get_height(node->right);
        int balance = h_l - h_r;

        //print the value of the node
        std::cout << '[' << node->data << ", " << balance << ']' << std::endl;

        //enter the next tree level
        print(prefix + "    ", node->right, true);
        print(prefix + "    ", node->left, false);
    }
}

template <typename T>
void AVLTree<T>::insert(const T& val) {
    insert(val, root);
}


template <typename T>
void AVLTree<T>::insert(const T& val, AVLNode<T>* & node) {
    if (!node) {
        node = new AVLNode<T>(val);
    }
    if (val < node->data) {
        insert(val, node->left);
    }
    if (val > node->data) {
        insert(val, node->right);
    }
    node->height = max( get_height( node->left ), get_height( node->right ) ) + 1;

    balance(node);
}

template <typename T>
void AVLTree<T>::balance(AVLNode<T>*& node) {
    if (!node) {
        return;
    }
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    
    if (left_height - right_height > 1) { //left unbalanced
        if(get_height(node->left->left) >= get_height(node->left->right)) {
            rotate_right(node);
        }
        else {
            rotate_right_double(node);
        }
    }
    if (right_height - left_height > 1) { //right unbalanced
        if(get_height(node->right->right) >= get_height(node->right->left)) {
            rotate_left(node);
        }
        else {
            rotate_left_double(node);
        }
    }

    //node->height = max( get_height( node->left ), get_height( node->right ) ) + 1;
}


template <typename T>
void AVLTree<T>::rotate_right(AVLNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }
    AVLNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    left_kid->height = max(get_height(left_kid->left), node->height) + 1;
    node = left_kid;
}

template <typename T>
void AVLTree<T>::rotate_left(AVLNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }
    AVLNode<T>* right_kid = node->right;
    node->right = right_kid->left;
    right_kid->left = node;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    right_kid->height = max(get_height(right_kid->right), node->height) + 1;

    node = right_kid;
}

template <typename T>
void AVLTree<T>::rotate_right_double(AVLNode<T>*& node) {
    if(!node || !node->left) {
        return;
    }
    rotate_left(node->left);
    rotate_right(node);
}

template <typename T>
void AVLTree<T>::rotate_left_double(AVLNode<T>*& node) {
    if(!node || !node->right) {
        return;
    }
    rotate_right(node->right);
    rotate_left(node);
}


template <typename T>
int AVLTree<T>::get_height(AVLNode<T>* node) const {
    return (!node) ? 0 : node->height;
}


template <typename T>
void AVLTree<T>::remove(const T& val) {
    remove(val, root);
}

template <typename T>
void AVLTree<T>::remove(const T& val, AVLNode<T>*& node) {
    if (!node) {
        return;
    }
    else if (val < node->data) {
        remove(val, node->left);
    }
    else if (val > node->data) {
        remove(val, node->right);
    }
    else if (node->left && node->right) { //two children
        node->data = get_min(node->right);
        remove(val, node->right);
    }
    else { //leaf or one child
        AVLNode<T>* to_delete = node;
        node = (node->left) ? node->left : node->right;
        delete to_delete;
    }
    if (node) {
        node->height = max( get_height( node->left ), get_height( node->right ) ) + 1;
    }

    balance(node);
}

template <typename T>
const T& AVLTree<T>::get_min(AVLNode<T>* node) const {
    if (!node) {
        throw std::string("Error:get_min\n");
    }
    else {
        AVLNode<T>* cur = node;
        while (cur->left) {
            cur = cur->left;
        }
        return cur->data; 
    }
}

