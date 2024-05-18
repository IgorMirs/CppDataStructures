#ifndef DLLIST_H
#define DLLIST_H

#include "DLLNode.h"

template <typename T>
class DLList {
public:
    //no-arg constructor
    DLList();

    //destructor
    ~DLList();

    //copy constructor
    DLList(const DLList<T>& other);

    DLList<T>& operator=(const DLList<T>& other);

    //methods
    unsigned size() const; //returns the size of the list
    bool empty() const; //return true if the list is empty
    void push_front(const T& val); //insert at the beginning of the list
    void push_back(const T& val); //insert at the end of the list
    void print() const; //prints the content of the list
    void print_backwards() const; //prints the content of the list backwards

    void pop_front(); //removes the first element
    void pop_back(); //removes the last element
    void clear(); //removes all elements from the list

    const T& front(); //returns the first element in the list

private:
    DLLNode<T>* head; //the first node in the linked list
    DLLNode<T>* tail; //the last node in the linked list
    unsigned listSize; //the size of the list
};

#endif