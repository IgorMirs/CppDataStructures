#include "Stack.h"
#include "Stack.cpp"
#include <vector>
#include <iostream>

using namespace StackArray;

template <typename T>
void reverse_vec(std::vector<T>& v) {
    StackList::Stack<T> st;
    for(int i : v) {
        st.push(i);
    }
    for(int i = 0; i < v.size(); i++) {
        v[i] = st.top();
        st.pop();
    }
}

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for(int i : v) {
        std::cout << i << " "; 
    }
    std::cout << '\n';

    reverse_vec(v);
    for(int i : v) {
        std::cout << i << " "; 
    }
    std::cout << '\n';

    return 0;
}