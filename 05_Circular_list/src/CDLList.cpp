#include "CDLList.h"
#include <iostream>

template<typename T>
CDLList<T>::CDLList() {
    tail = nullptr;
    listSize = 0;
}

template<typename T>
CDLList<T>::CDLList(const CDLList<T>& other) {
    tail = new DLLNode<T>; //sentinel tail node
    listSize = 0;
    DLLNode<T>* cur = other.tail->next;
    int i = 0;
    while (i < other.size()) {
        push_back(cur->data);
        cur = cur->next;
        i++;
    }
}

template<typename T>
CDLList<T>& CDLList<T>::operator=(const CDLList<T>& other) {
    clear();
    DLLNode<T>* cur = other.tail->next;
    int i = 0;
    while (i < other.size()) {
        push_back(cur->data);
        cur = cur->next;
        i++;
    }

    return *this;
}

template<typename T>
CDLList<T>::~CDLList() {
    //remove all nodes 
    clear();
}

template<typename T>
unsigned CDLList<T>::size() const {
    return listSize;
}

template<typename T>
bool CDLList<T>::empty() const {
    return (listSize == 0);
}

template<typename T>
void CDLList<T>::push_front(const T& value) {
    if (empty()) {
        tail = new DLLNode<T>(value);
        tail->next = tail->prev = tail;
    }
    else {
        tail->next = new DLLNode<T>(value, tail, tail->next);
        tail->next->next->prev = tail->next;
    }
    //increment the size
    listSize++;
}

template<typename T>
void CDLList<T>::print() const {
    //iterate through the linked list 
    DLLNode<T>* cur = tail->next;
    int i = 0;
    while(i < size()) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
        i++;
    }
    std::cout << "/\n";
}


template<typename T>
void CDLList<T>::print_backwards() const {
    //iterate through the linked list 
    DLLNode<T>* cur = tail;
    int i = 0;
    while(i < size()) {
        std::cout << cur->data << " -> ";
        cur = cur->prev;
        i++;
    }
    std::cout << "/\n";
}

template<typename T>
void CDLList<T>::push_back(const T& value) {
    if (empty()) {
        tail = new DLLNode<T>(value);
        tail->next = tail->prev = tail;
    }
    else {
        tail->next = new DLLNode<T>(value, tail, tail->next);
        tail = tail->next;
        tail->next->prev = tail;

    }
    listSize++; //update size
}

template<typename T>
void CDLList<T>::pop_front() {
    if (!empty()) {
        DLLNode<T>* to_delete = tail->next;
        if (size() != 1) {
            tail->next = tail->next->next;
            tail->next->prev = tail;
        }
        else {
            tail = nullptr;
        }
        listSize--;
        delete to_delete;
    }
}

template<typename T>
void CDLList<T>::pop_back() {
    if (!empty()) {
        DLLNode<T>* to_delete = tail;
        if (size() != 1) {
            tail->prev->next = tail->next;
            tail->next->prev = tail->prev;
            tail = tail->prev;
        }
        else {
            tail = nullptr;
        }
        listSize--;
        delete to_delete;
    }
}

template<typename T>
void CDLList<T>::clear() {
    while(!empty()) {
        pop_front();
    }
}
