#include "BST.h"

#include <iostream>

template <typename T>
BST<T>::BST() : root (nullptr) {}


template <typename T>
BST<T>::~BST() {
    while (!empty()) {
        delete_node(root->data);
    }

}

// template <typename T>
// BST<T>::BST(const BST<T>& other) {
//     root = copy_helper(other.root);
// }

template <typename T>
BTNode<T>* BST<T>::copy_helper(BTNode<T>* node) {
    if (!node) {
        return nullptr;
    }
    BTNode<T>* new_tree = new BTNode<T>(node->data);
    new_tree->left = copy_helper(node->left);
    new_tree->right = copy_helper(node->right);


    return new_tree;
}

template <typename T>
bool BST<T>::empty() const {
    return (root == nullptr); 
}

template <typename T>
void BST<T>::insert(const T& val) {
    //empty tree
    if (empty()) {
        root = new BTNode<T>(val);
    }
    else {
        BTNode<T>* cur = root, *prev = root;
        while (cur) {
            prev = cur;
            if (val < cur->data) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        //cur is nullptr, prev is a parent of cur
        if (val < prev->data) {
            prev->left = new BTNode<T>(val);
        }
        else {
            prev->right = new BTNode<T>(val);
        }
    }
}

template <typename T>
void BST<T>::preorder(BTNode<T>* node) const {
    if (!node) {
        return;
    }
    else {
        std::cout << node->data << ' ';
        preorder(node->left);
        preorder(node->right);
    }
}

template <typename T>
void BST<T>::preorder() const {
    std::cout << "Preorder:\t\t[";
    preorder(root);
    std::cout << "]\n";
}

template <typename T>
void BST<T>::inorder(BTNode<T>* node) const {
    if (!node) {
        return;
    }
    else {
        inorder(node->left);
        std::cout << node->data << ' ';
        inorder(node->right);
    }
}

template <typename T>
void BST<T>::inorder() const {
    std::cout << "Inorder:\t\t[";
    inorder(root);
    std::cout << "]\n";
}

template <typename T>
void BST<T>::postorder(BTNode<T>* node) const {
    if (!node) {
        return;
    }
    else {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << ' ';
    }
}

template <typename T>
void BST<T>::postorder() const {
    std::cout << "Postorder:\t\t[";
    postorder(root);
    std::cout << "]\n";
}

template <typename T>
void BST<T>::print() const {
    print("", root, false);
}


template <typename T>
void BST<T>::print(const std::string& prefix, const BTNode<T>* node, bool isRight) const {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << (isRight ? "R--" : "L--");

        //print the value of the node
        std::cout << node->data << std::endl;

        //enter the next tree level
        print(prefix + "    ", node->right, true);
        print(prefix + "    ", node->left, false);
    }
}


template <typename T>
const T& BST<T>::get_min(BTNode<T>* node) const {
    if (empty()) {
        throw std::string("Empty tree\n");
    }
    else {
        BTNode<T>* cur = node;
        while (cur->left) {
            cur = cur->left;
        }
        return cur->data; 
    }
}

template <typename T>
const T& BST<T>::get_min() const {
    if (empty()) {
        throw std::string("Empty tree\n");
    }
    else {
        BTNode<T>* cur = root;
        while (cur->left) {
            cur = cur->left;
        }
        return cur->data; 
    }
}

template <typename T>
const T& BST<T>::get_max() const {
    if (empty()) {
        throw std::string("Empty tree\n");
    }
    else {
        BTNode<T>* cur = root;
        while (cur->right) {
            cur = cur->right;
        }
        return cur->data; 
    }
}

template <typename T>
BTNode<T>* BST<T>::search(const T& val) const {
    BTNode<T>* node = root;
    
    while (node) {
        if (node->data == val) {
            return node;
        }
        else if (val < node->data) {
            node = node->left;
        }
        else if (val > node->data) {
            node = node->right;
        }
    }

    return nullptr;
}

template <typename T>
BTNode<T>* BST<T>::search_parent(const T& val) const {
    if (!root || root->data == val) {
        return nullptr;
    }
    
    BTNode<T>* cur = root;
    BTNode<T>* prev = root;
    
    while (cur) {
        if (cur->data == val) {
            return prev;
        }
        else if (val < cur->data) {
            prev = cur;
            cur = cur->left;
        }
        else if (val > cur->data) {
            prev = cur;
            cur = cur->right;
        }
    }

    return nullptr;
}


template <typename T>
void BST<T>::delete_node(const T& val) {
    if (empty()) {
        throw std::string("Empty tree");
    }
    BTNode<T>* node = search(val);
    if (!node) {
        throw std::string("No such node to delete");
    }
    BTNode<T>* parent = search_parent(val);

    if (!node->left && !node->right) { //leaf
        delete_leaf(node, parent);
    }
    else if (!node->left || !node->right) { //has one kid
        delete_one_child(node, parent);
    }
    else { //has two kids
        T min_node = get_min(node->right);
        delete_leaf(search(min_node), search_parent(min_node));
        node->data = min_node;
    }
}


template <typename T>
void BST<T>::delete_leaf(BTNode<T>* child, BTNode<T>* parent) {
    if (!child) {
        throw std::string("Delete leaf: no node to delete");
    }
    if (!parent) { //deleting root
        delete root;
        root = nullptr;
        return;
    }
    else if (child->data < parent->data) { //left kid
        parent->left = nullptr;
    }
    else if (child->data > parent->data) { //right kid
        parent->right = nullptr;
    }
        
    delete child;
}


template <typename T>
void BST<T>::delete_one_child(BTNode<T>* child, BTNode<T>* parent) {
    if (!child) {
        throw std::string("Delete one child: no node to delete");
    }
    if (!parent) { //deleting root
        BTNode<T>* to_delete = root;
        root = (root->left) ? root->left : root->right;
        delete to_delete;
        return;
    }

    if (child->right && !child->left) {
        if (child->data < parent->data) { //left kid
            parent->left = child->right;
        }
        else if (child->data > parent->data) { //right kid
            parent->right = child->right;
        }
    }
    else if (!child->right && child->left) {
        if (child->data < child->data) { //left kid
            parent->left = child->left;
        }
        else if (child->data > child->data) { //right kid
            parent->right = child->left;
        }
    }
    delete child;
}

template <typename T>
bool BST<T>::find_target(BTNode<T>* node, const T& val) const {
    if (!node) {
        return false;
    }
    else {
        BTNode<T>* temp = search(val - node->data);
        if (temp && temp != node) {            
            return true;
        }
        bool left = false, right = false;
        if (node->left) {
            left = find_target(node->left, val);
        }
        if (!left && node->right) {
            right = find_target(node->right, val);
        } 
        
        return (left || right);
    }
}

template <typename T>
bool BST<T>::find_target(const T& val) const {
    return find_target(root, val);
}


template <typename T>
int BST<T>::get_height(BTNode<T>* node) const {
    if (!node) {
        return 0;
    }
    int left = get_height(node->left);
    int right = get_height(node->right);
    
    return (left > right) ? left + 1 : right + 1;
}

template <typename T>
int BST<T>::get_height() const {
    return get_height(root);  
}