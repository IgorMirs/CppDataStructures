// #include "../hdrs/Node.h"
#include "Node.cpp"
#include "../inc/List.h"
#include "List.cpp"
#include <iostream>


int main() {
    List<int> l;
    // l.push_back(1);
    // l.push_back(2);
    // l.push_back(3);
    // l.push_front(4);
    // l.push_front(5);
    l.push_front(6);
    // l.print();

    l.insert(0, 100);
    l.erase(1);
    // l.insert(2, 100);
    l.print();

    List<int> d(l);
    d.print();
   
   
    List<int> f = d;
    f.print();

    puts("main end");
    return 0;
}