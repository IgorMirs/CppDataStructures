#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <typename T>
class List {
public:
    List();
    void push_back(const T&);
    void push_front(const T&);
    int size() const; //1
    bool empty() const; //2
    void pop_back(); //3
    void pop_front(); //4
    T& front(); //5


    void print() const;

private:
    void init();
    int theSize;
    Node<T>* tail;
    Node<T>* head;
};


#endif