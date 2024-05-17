#ifndef SLLIST_H
#define SLLIST_H

#include "SLLNode.h"

template <typename T>
class SLList {
public:
    //no-arg constructor
    SLList();


    //methods
    unsigned size() const; //returns the size of the list
    bool empty() const; //return true if the list is empty
    void push_front(const T& val); //insert at the beginning of the list
    void print() const; //prints the content of the list

    void push_back(const T& val); //insert at the end of the list


private:
    SLLNode<T>* head; //the first node in the linked list
    SLLNode<T>* tail; //the last node in the linked list
    unsigned listSize; //the size of the list
};

#endif