#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <typename T>
class List {
public:
    List();
    ~List(); //8

    void push_back(const T&);
    void push_front(const T&); //to implement in class
    int size() const; //1
    bool empty() const; //2
    void pop_back(); //3
    void pop_front(); //4 to implement in class
    T& front(); //5
    T& back(); //6 to implement in class
    void clear(); //7

    void insert(unsigned pos, const T& value); //9
    void erase(unsigned pos); //10

    void print() const;

private:
    void init();
    Node<T>* find(unsigned pos); //9
    int theSize;
    Node<T>* tail;
    Node<T>* head;
};


#endif