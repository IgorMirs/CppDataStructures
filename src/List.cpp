#include "../inc/List.h"

template<typename T>
List<T>::List() {
    init();
}


template<typename T>
List<T>::~List() {
    clear();
    delete head;
    delete tail;
}

template<typename T>
void List<T>::push_back(const T& value) {
    Node<T>* n = new Node<T>(value);
    n->prev = tail->prev;
    n->next = tail;
    tail->prev->next = n;
    tail->prev = n;

    theSize++; 
}

template<typename T>
void List<T>::clear() {
    while(!empty()) {
        pop_front();
    }
}

template <typename T>
void List<T>::push_front(const T& value) {
    Node<T>* n = new Node<T>(value);
    n->prev = head;
    n->next = head->next;
    head->next->prev = n;
    head->next = n;

    theSize++; 
}

template<typename T>
int List<T>::size() const {
    return theSize;
}

template<typename T>
void List<T>::pop_back() {
    if (!empty()) {
        Node<T>* to_delete = tail->prev;
        tail->prev = to_delete->prev;
        tail->prev->next = tail;
        delete to_delete;
        theSize--;

    }
}

template<typename T>
void List<T>::pop_front() {
    if (!empty()) {
        Node<T>* to_delete = head->next;
        head->next = to_delete->next;
        head->next->prev = head;
        delete to_delete;
        theSize--;
    }
}

template<typename T>
T& List<T>::front() {
    if (!empty()) {
        return head->next->data;
    }
    else {
        throw "Empty list";
    }
}

template<typename T>
T& List<T>::back() {
    if (!empty()) {
        return tail->prev->data;
    }
    else {
        throw "Empty list";
    }
}

template<typename T>
bool List<T>::empty() const {
    return (size() == 0);
}

template<typename T>
void List<T>::print() const {
    std::cout << "{ ";
    Node<T>* cur = head->next;
    while (cur != tail) {
        std::cout << cur->data; 
        if (cur->next != tail) {
            std::cout << " -> ";
        }
        cur = cur->next;
    }
    std::cout << " }\n";
}


template<typename T>
void List<T>::init() {
    theSize = 0;
    head = new Node<int>(0);
    tail = new Node<int>(0);
    head->next = tail;
    tail->prev = head;
}

template<typename T>
void List<T>::insert(unsigned pos, const T& value) {
    if (size() < pos) {
        throw "Cannot insert";
    }
    else {
        unsigned cur_pos = 0;
        Node<T>* cur = head->next;
        while (cur_pos != pos) {
            cur = cur->next;
            cur_pos++;
        }
        Node<T>* new_node = new Node<T>(value, cur, cur->prev);
        new_node->prev->next = new_node;
        cur->prev = new_node;
        theSize++;
    }
}

template<typename T>
void List<T>::erase(unsigned pos) {
    if (size() < pos) {
        throw "Cannot erase";
    }
    else {
        Node<T>* to_delete = find(pos);
        if (to_delete) {
            puts("here");
            to_delete->next->prev = to_delete->prev;
            to_delete->prev->next = to_delete->next;
            delete to_delete;
            theSize--;
        }
    }
}

template<typename T>
Node<T>* List<T>::find(unsigned pos) {
    if (pos >= size()) {
        puts("E");
        return nullptr;
    }
    else {
        unsigned cur_pos = 0;
        Node<T>* cur = head->next;
        while (cur_pos != pos) {
            cur = cur->next;
            cur_pos++;
        }
        return cur;
    }
}