#ifndef TRIE_H
#define TRIE_H

#include <string>
#include "TrieNode.h"

class Trie {
public:
    Trie();
    bool empty() const;
    void insert(const std::string& word);
    bool search(const std::string& word) const;

private:
    TrieNode* root;
};

Trie::Trie(): root(nullptr) { }

bool Trie::empty() const {
    return (root == nullptr);
}

void Trie::insert(const std::string& word) {
    if (empty()) {
        root = new TrieNode();
    }
    TrieNode* cur = root;

    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (!cur->children[index]) {
            cur->children[index] = new TrieNode();
        }

        cur = cur->children[index];
    }
    cur->endOfWord = true;
}

bool Trie::search(const std::string& word) const {
    if (empty()) {
        return false;
    }
    TrieNode* cur = root;

    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (!cur->children[index]) {
            return false;
        }

        cur = cur->children[index];
    }
    
    return (cur->endOfWord);
}   


#endif