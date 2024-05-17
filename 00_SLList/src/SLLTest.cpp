#include "SLLNode.h"
#include "SLList.h"
#include "SLList.cpp"

#include <iostream>

int main() {
    SLList<double> l;

 
    l.push_front(5.5);
    l.push_back(4.4);

    l.print();

    return 0;
}