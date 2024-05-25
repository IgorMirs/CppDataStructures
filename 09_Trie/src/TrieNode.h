#ifndef TRIENODE_H
#define TRIENODE_H

#define ALPHABET_SIZE 26

class TrieNode {
public:
    TrieNode() {
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }

        endOfWord = false;
    }

    TrieNode* children[ALPHABET_SIZE];
    bool endOfWord;
};

#endif