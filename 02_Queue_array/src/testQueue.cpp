#include "Queue.h"
#include "Queue.cpp"

#include <iostream>

int main() {
    Queue<int> q;

    std::cout << q.empty() << std::endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    Queue<int> q2(q);
    q.dequeue();
    q.dequeue();

    Queue<int> q3;
    q3 = q;


    q.print();
    q2.print();

    return 0;
}