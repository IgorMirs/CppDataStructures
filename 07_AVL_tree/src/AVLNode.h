#ifndef AVNODE_H
#define AVNODE_H

template <typename T>
class AVLNode {
public:
    AVLNode(const T& val = T(), AVLNode<T>* l = nullptr, AVLNode<T>* r = nullptr) :
        data(val), left(l), right(r), height(1) {}

    T data;
    int height;
    AVLNode<T>* left;
    AVLNode<T>* right;
};

#endif