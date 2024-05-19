#include "Stack.h"

#include <string>

using namespace StackArray;

template<typename T>
StackArray::Stack<T>::Stack(int capacity) {
    data = new T[capacity];
    this->capacity = capacity;
    t = -1;
}

template<typename T>
StackArray::Stack<T>::~Stack() {
    delete [] data;
}

template<typename T>
void StackArray::Stack<T>::push(const T& val) {
    if (!full()) {
        data[++t] = val;
    }
    else {
        throw std::string("Full stack");
    }
}

template<typename T>
void StackArray::Stack<T>::pop() {
    if (!empty()) {
        t--;
    }
    else {
        throw std::string("Empty stack");
    }
}

template<typename T>
const T& StackArray::Stack<T>::top() const {
    if (empty()) {
        throw std::string("Empty stack");        
    }
    else {
        return data[t];
    }
}
template<typename T>
bool Stack<T>::empty() const {
    return (t < 0);
}
template<typename T>
bool Stack<T>::full() const {
    return (t == capacity - 1);
}


///*************STACK LIST*****************

template<typename T>
StackList::Stack<T>::Stack() {
    front = rear = nullptr;
}

template<typename T>
StackList::Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
void StackList::Stack<T>::push(const T& val) {
    if (empty()) {
        front = rear = new Node<T>(val);
    }
    else {
        rear->next = new Node<T>(val);
        rear->next->prev = rear;
        rear = rear->next;
    }
}

template<typename T>
void StackList::Stack<T>::pop() {
    if (!empty()) {
        Node<T>* to_delete = rear;
        rear = rear->prev;
        delete to_delete;
        if (!rear) {
            front = nullptr;
        }
    }
    else {
        throw std::string("Empty stack");
    }
}

template<typename T>
const T& StackList::Stack<T>::top() const {
    if (empty()) {
        throw std::string("Empty stack");        
    }
    else {
        return rear->data;
    }
}

template<typename T>
bool StackList::Stack<T>::empty() const {
    return (front == nullptr);
}
