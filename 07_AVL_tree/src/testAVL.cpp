#include "AVLTree.h"
#include "AVLTree.cpp"



int main() {
    AVLTree<int> tree;

    for (int i = 0; i < 45; i++) {
        tree.insert(i);
    }

    
    tree.print();
    for (int i = 44; i >= 0; i--) {
        tree.remove(i);
        printf("--------------------\n%d\n--------------------\n", i);
        tree.print();
    }

    return 0;
}