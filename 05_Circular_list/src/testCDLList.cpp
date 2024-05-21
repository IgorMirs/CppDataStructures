#include "CDLList.h"
#include "CDLList.cpp"

int main() {

    CDLList<int> list;

    list.push_back(1);
    list.push_back(2);
    CDLList<int> list2(list);
    list.pop_front();

    list.print();
    list2.print_backwards();

    return 0;
}