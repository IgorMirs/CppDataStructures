#include "SLList.h"
#include <iostream>

template <typename T>
SLList<T>::SLList() {
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

template <typename T>
unsigned SLList<T>::size() const {
    return listSize;
}

template <typename T>
bool SLList<T>::empty() const {
    return (listSize == 0);
}

template <typename T>
void SLList<T>::push_front(const T& val) {
    head = new SLLNode<T>(val, head);

    //increment the list size
    listSize++;

    if (listSize == 1) {
        tail = head;
    }
}

template <typename T>
void SLList<T>::push_back(const T& val) {
    if (empty()) {
        head = new SLLNode<T>(val);
        tail = head;
    }
    else {
        tail->next = new SLLNode<T>(val); //add the node to the end
        tail = tail->next; //move the tail
    }

    //increment the list size
    listSize++;
}

template <typename T>
void SLList<T>::print() const {
    std::cout << "{ ";
    SLLNode<T>* cur = head;
    while (cur) {
        std::cout << cur->data; 
        if (cur->next) {
            std::cout << " -> ";
        }
        cur = cur->next;
    }
    std::cout << " }\n";
}