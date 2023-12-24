#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
public:
    Node(const T& d = T(), Node* n = nullptr, Node* p = nullptr);


    Node* next;
    Node* prev;
    T data;
};

#endif

