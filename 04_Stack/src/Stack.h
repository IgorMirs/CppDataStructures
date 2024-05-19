#ifndef STACK_H
#define STACK_H

namespace StackArray {
    template <typename T>
    class Stack {
    public:
        Stack(int capacity = 10);
        ~Stack();

        void push(const T& val);
        void pop();
        const T& top() const;
        bool empty() const;
        bool full() const;

    private:
        T* data; //array of stack elements
        int capacity; //stack capacity
        int t; //index of the top of the stack
    };
}

namespace StackList {
    template <typename T>
    class Stack {
    public:
        Stack();
        ~Stack();

        void push(const T& val);
        void pop();
        const T& top() const;
        bool empty() const;

    private:
        template <typename T2>
        class Node {
            public:
                T data;
                Node(const T& val) : data(val), prev(nullptr), next(nullptr) {};
                Node<T2>* next;
                Node<T2>* prev;
        };
        Node<T>* front;
        Node<T>* rear;
    };
}

#endif