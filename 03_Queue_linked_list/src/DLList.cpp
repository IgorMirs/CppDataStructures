#include "DLList.h"
#include <iostream>

template<typename T>
DLList<T>::DLList() {
    head = new DLLNode<T>; //sentinel header node
    tail = new DLLNode<T>; //sentinel tail node
    head->next = tail;
    tail->prev = head;
    listSize = 0;
}

template<typename T>
DLList<T>::DLList(const DLList<T>& other) {
    head = new DLLNode<T>; //sentinel header node
    tail = new DLLNode<T>; //sentinel tail node
    head->next = tail;
    tail->prev = head;
    listSize = 0;
    DLLNode<T>* cur = other.head->next;
    while (cur != tail) {
        push_back(cur->data);
        cur = cur->next;
    }
}

template<typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& other) {
    clear();
    DLLNode<T>* cur = other.head->next;
    while (cur != other.tail) {
        push_back(cur->data);
        cur = cur->next;
    }


    return *this;
}

template<typename T>
DLList<T>::~DLList() {
    //remove all nodes 
    clear();
    //delete sentinel nodes
    delete head;
    delete tail;
}

template<typename T>
unsigned DLList<T>::size() const {
    return listSize;
}

template<typename T>
bool DLList<T>::empty() const {
    return (listSize == 0);
}

template<typename T>
void DLList<T>::push_front(const T& value) {
    head->next = new DLLNode<T>(value, head, head->next);
    head->next->next->prev = head->next;
    //increment the size
    listSize++;
}

template<typename T>
void DLList<T>::print() const {
    //iterate through the linked list 
    DLLNode<T>* cur = head->next;

    while(cur != tail) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    }
    std::cout << "/\n";
}


template<typename T>
void DLList<T>::print_backwards() const {
    //iterate through the linked list 
    DLLNode<T>* cur = tail->prev;

    while(cur != head) {
        std::cout << cur->data << " -> ";
        cur = cur->prev;
    }
    std::cout << "/\n";
}

template<typename T>
void DLList<T>::push_back(const T& value) {
    tail->prev = new DLLNode<T>(value, tail->prev, tail);
    tail->prev->prev->next = tail->prev;
    listSize++; //update size
}

template<typename T>
void DLList<T>::pop_front() {
    if (!empty()) {
        DLLNode<T>* to_delete = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        listSize--;
        delete to_delete;
    }
}

template<typename T>
void DLList<T>::pop_back() {
    if (!empty()) {
        DLLNode<T>* to_delete = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;

        listSize--;
        delete to_delete;
    }
}

template<typename T>
void DLList<T>::clear() {
    while(!empty()) {
        pop_front();
    }
}

template<typename T>
const T& DLList<T>::front() {
    if (empty()) {
        throw std::string("Empty list");
    }
    else {
        return head->next->data;
    }
}
