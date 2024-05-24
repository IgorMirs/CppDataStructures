#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
//#include <algorithm>

//using std::min;

template <typename T>
class MinHeap {
public:
    MinHeap();
    MinHeap(std::vector<T>);
    void insert(const T& val);
    void print() const;
    T delete_min();
    int get_height();

private:
    std::vector<T> data;
    void swap(T& v1, T& v2) {
        T tmp = v1;
        v1 = v2;
        v2 = tmp;
    }

    int min_index(int i1, int i2);

    void percolate_down(int i);
    // to heapify a tree
    void heapify();
};



template <typename T>
MinHeap<T>::MinHeap() {
    
}

template <typename T>
MinHeap<T>::MinHeap(std::vector<T> v): data(v){
    heapify();
}

template <typename T>
void MinHeap<T>::insert(const T& val) {
    data.push_back(val);
    int n = data.size() - 1;
    //percolate UP
    while (data[n] < data[(n - 1)/2]) {
        swap(data[n], data[(n - 1)/2]);
        n = (n - 1) / 2;       
    }
}

template <typename T>
void MinHeap<T>::print() const {
    int cur_level = 0;
    int new_level = 1;
    for (int i = 0; i < data.size(); i++) {
        std::cout << std::setw((int)ceil(log2(data.size())) - i) << data[i] << ' ';
        cur_level++;
        if (cur_level == new_level) {
            std::cout << '\n';
            new_level *= 2;
            cur_level = 0;
        }
    }
    std::cout << std::endl;
}

template <typename T>
T MinHeap<T>::delete_min() {
    if(data.empty()) {
        throw std::string("delete_min: Empty MinHeap");
    }

    T res = data[0];
    data[0] = data[data.size() - 1]; //set the last element as the root
    data.pop_back(); //delete the last element

    //percolate down
    percolate_down(0);   

    return res;
}

template <typename T>
int MinHeap<T>::min_index(int i1, int i2) {
    if (i1 >= data.size() || i2 >= data.size()) {
        throw std::string("min_index: incorrect index\n");
    }

    return (data[i1] < data[i2]) ? i1 : i2;
}

template <typename T>
void MinHeap<T>::percolate_down(int i) {
    if (data.size() <= 1 || i >= data.size()) {
        return;
    }
    else {
        int index = i;
        int new_index = index;
        do {
            if (index * 2 + 1 >= data.size()) { //no kids
                break;
            }
            if (index * 2 + 2 < data.size()) { //has 2 kids
                new_index = min_index(index * 2 + 1, index * 2 + 2);
            }
            else if (index * 2 + 1 < data.size()) { //has 1 kid
                new_index = min_index(index, index * 2 + 1);
            }

            if (data[new_index] < data[index]) {
                swap(data[index], data[new_index]);
                index = new_index;
            }
            else {
                break;
            }
        } while (1);
    }
}


template <typename T>
void MinHeap<T>::heapify() {
    for (int i = (data.size() / 2) - 1; i >= 0; i--) {
        percolate_down(i);
    }
}