#ifndef BST_H
#define BST_H

#include "BTNode.h"
#include <string>

template <typename T>
class BST {
public:
    BST();
    ~BST();
    //BST(const BST<T>& other);

    bool empty() const;

    void insert(const T& val);

    void preorder() const;
    void inorder() const; //implement
    void postorder() const; //implement

    void print() const;
    
    const T& get_min() const; //returns the minimum value in BST
    const T& get_max() const; //returns the maximum value in BST

    BTNode<T>* search(const T& val) const; //returns the pointer to the node with data == val (nullptr if no such node)

    BTNode<T>* search_parent(const T& val) const;

    int get_height() const; 


    void delete_node(const T& val);


    bool find_target(const T& val) const;

private:
    BTNode<T>* root;
    void preorder(BTNode<T>* node) const;
    void inorder(BTNode<T>* node) const;
    void postorder(BTNode<T>* node) const;

    void print(const std::string& prefix, const BTNode<T>* node, bool isRight) const;

    void delete_leaf(BTNode<T>* node_to_delete, BTNode<T>* node_to_delete_parent);
    void delete_one_child(BTNode<T>* node_to_delete, BTNode<T>* node_to_delete_parent);
    const T& get_min(BTNode<T>* node) const;

    bool find_target(BTNode<T>* node, const T& val) const;

    BTNode<T>* copy_helper(BTNode<T>* node);

    int get_height(BTNode<T>* node) const; 
};

#endif