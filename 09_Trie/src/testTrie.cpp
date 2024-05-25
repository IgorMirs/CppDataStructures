#include "Trie.h"

#include <vector>
#include <string>
#include <iostream>

std::string longestCommonPrefix(std::vector<std::string>& strs);

int main() {
    std::vector<std::string> words;
    Trie tr;

    words.push_back("hey");
    words.push_back("buy");
    words.push_back("hello");


    for (int i = 0; i < words.size(); i++)
		tr.insert(words[i]);

	// Search for different keys
	tr.search("hey")? std::cout << "Yes\n" : std::cout << "No\n";
	tr.search("how")? std::cout << "Yes\n" : std::cout << "No\n";


    return 0;
}

// std::string longestCommonPrefix(std::vector<std::string>& strs) {
//     for (int i = 0; i < strs.size(); i++) {

//     }
// }