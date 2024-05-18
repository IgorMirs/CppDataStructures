#ifndef QUEUE_H
#define QUEUE_H

#include "DLList.h"

template <typename T>
class Queue {
public:
    Queue();

    ~Queue();

    Queue(const Queue<T>& other);

    Queue<T>& operator=(const Queue<T>& other);

    unsigned size() const;
    bool empty() const;

    void clear();
    void enqueue(const T& val);
    void dequeue();
    const T& front() const;
    void print() const;

private:
    DLList<T>* data;
};

#endif