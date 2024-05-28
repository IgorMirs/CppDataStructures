#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <vector>
#include "HashNode.h"

template <typename K, typename V>
class HashMap {
public:
    HashMap(unsigned capacity = 100);
    ~HashMap();

    bool empty() const;
    bool full() const;
    int size() const;

    void insert(const K& key, const V& value);
    void remove(const K& key);
    void clear();

    V search(const K& key) const;


    void display() const;
private:
    std::vector<HashNode<K,V>*> data;
    int n;

    int nextPrime(int n) const;
    int hash(const K& key) const;
    int search_index(const K& key) const;

    HashNode<K, V>* dummy;

    void set_dummy();
};

#endif