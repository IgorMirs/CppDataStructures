#include "HashMap.h"
#include "HashMap.cpp"

bool has_duplicates(const std::vector<std::string>& v) {
    HashMap<std::string, int> map;

    for (const std::string& s : v) {
        if (map.search(s) == 1) {
            return true;
        }
        map.insert(s, 1);
    }

    return false;
}


int main() {
    HashMap<int, int> map;

    map.insert(111, 1);
    map.insert(222, 2);
    map.insert(333, 3);
    map.insert(10, 123);
    map.insert(20, 234);
    map.insert(30, 345);

    map.display();
    map.remove(30);
    map.display();
    std::cout << map.search(25);

    std::vector<std::string> v = {"hello", "bye", "hell", "bye"};
    // std::string s("abcdeaghj");
    std::cout << '\n' << has_duplicates(v);
    return 0;
}