#include "binaryHeap.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

template <typename T>
void heap_sort(std::vector<T>& v) {
    MinHeap<T> *h = new MinHeap<T>(v);

    // // Create a heap from the array of values.
    // for (int i = 0; i < v.size(); i++) {
    //     h->insert(v[i]);
    // }

    // Remove these values from the heap one by one and store them back in the
    // original array.
    for (int i = 0; i < v.size(); i++) {
        v[i] = h->delete_min();
    }

    delete h;
}


int main() {
    srand(time(0));
    MinHeap<int> h;
    for (int i = 0; i < 20; i++) {
        h.insert(rand() % 20);
    }

    h.print();
    
    for (int i = 0; i < 20; i++) {
        std::cout << h.delete_min() << std::endl;
        //h.print();
    }
    
    std::vector<int> v;
    for (int i = 0; i < 20; i++) {
        v.push_back(rand() % 20);
    }
    heap_sort(v);
    for (int i = 0; i < 20; i++) {
        std::cout << v[i] << ' ';
    }

    // h.insert(5);
    // h.print();
    // h.insert(4);
    // h.print();
    // h.insert(2);
    // h.print();
    // h.insert(8);
    // h.print();
    // h.insert(13);
    // h.print();
    // h.insert(7);
    // h.print();
    // h.insert(6);
    // h.print();

    // std::cout << h.delete_min() << std::endl;
    // h.print();
    // std::cout << h.delete_min() << std::endl;
    // h.print();
    // std::cout << h.delete_min() << std::endl;
    // h.print();
    // std::cout << h.delete_min() << std::endl;
    // h.print();
    // std::cout << h.delete_min() << std::endl;
    // h.print();


    return 0;
}