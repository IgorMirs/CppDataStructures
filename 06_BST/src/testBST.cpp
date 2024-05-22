#include "BST.h"
#include "BST.cpp"


int main() {
    // BST<int>* tree = new BST<int>;
    // tree->insert(42);
    // tree->insert(34);
    // tree->insert(9);
    // tree->insert(77);
    // tree->insert(66);

    // BST<int>* tree2 = new BST<int>(*tree);
    // delete tree;
    
    // tree2->print();
    // std::cout << "find_target(84) = " << tree2->find_target(84) << std::endl;
    // std::cout << "find_target(43) = " << tree2->find_target(43) << std::endl;
    // std::cout << "find_target(76) = " << tree2->find_target(76) << std::endl;
    // std::cout << "find_target(143) = " << tree2->find_target(143) << std::endl;
    // std::cout << "find_target(45) = " << tree2->find_target(45) << std::endl;

    // std::cout << "Tree's height is " << tree2->get_height() << std::endl;


    // delete tree2;

    BST<int> t1;
    t1.insert(10);
    BST<int> t2 = t1;


    return 0;
}