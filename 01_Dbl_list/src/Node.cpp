#include "Node.h"

template <typename T>
Node<T>::Node(const T& d, Node* n, Node* p) {
    data = d;
    next = n;
    prev = p;
}
