#include "Queue.h"

template<typename T>
Queue<T>::Queue() {
    data = new DLList<T>();
}

template<typename T>
Queue<T>::~Queue() {
    delete data;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) {
   data = new DLList<T>();
   *data = *other.data;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    delete data;
    data = new DLList<T>();
    *data = *other.data;

    return *this;
}

template<typename T>
unsigned Queue<T>::size() const {
    return data->size();
}

template<typename T>
bool Queue<T>::empty() const {
    return data->empty();
}

template<typename T>
void Queue<T>::enqueue(const T& val) {
    data->push_back(val);
}

template<typename T>
void Queue<T>::clear() {
    data->clear();
}

template<typename T>
void Queue<T>::dequeue() {
    data->pop_front();
}

template<typename T>
void Queue<T>::print() const {
    data->print_backwards();
}



template<typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        puts("HERE");
        throw std::string("Empty queue");
    }
    else {
        return data->front();
    }
}