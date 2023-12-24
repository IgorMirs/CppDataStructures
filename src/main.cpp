// #include "../hdrs/Node.h"
#include "Node.cpp"
#include "List.h"
#include "List.cpp"
#include <iostream>


int main() {
    List<int> l;
    std::cout << l.empty() << std::endl;
    l.push_back(1);
    l.pop_back();
    std::cout << l.empty() << std::endl;
    l.push_back(2);
    l.push_back(3);
    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    l.front() = 100;
    std::cout << l.front() << std::endl;

  //  l.pop_front();
    l.print();

    std::cout << '\n' << l.size();

    return 0;
}