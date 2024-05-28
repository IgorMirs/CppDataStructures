#include "HashMap.h"

#include <iostream>
#include <bitset>
#include <functional>

template<typename K, typename V>
HashMap<K,V>::HashMap(unsigned capacity) : n(0) {
    int size = nextPrime(capacity);
    for(int i = 0; i < size; i++) {
        data.push_back(nullptr);
    }
    K key;
    V value;
    dummy = new HashNode<K, V>(key, value);
    // set_dummy();
}

template<typename K, typename V>
HashMap<K,V>::~HashMap() {
    clear();
    delete dummy;
}

template<typename K, typename V>
void HashMap<K,V>::clear() {
    for(int i = 0; i < data.size(); i++) {
        if (data[i] && data[i] != dummy) {
            delete data[i];
        }
    }
}

template<typename K, typename V>
bool HashMap<K,V>::empty() const {
    return (size() == 0);
}

template<typename K, typename V>
bool HashMap<K,V>::full() const {
    return (size() == data.size());
}

template<typename K, typename V>
int HashMap<K,V>::size() const {
    return n;
}

template<typename K, typename V>
void HashMap<K,V>::insert(const K& key, const V& value) {
    if (full()) {
        throw std::string("Insert: hash table is full");
    }
    //get hash
    int index = hash(key);

    //look for empty space
    while(data[index] && data[index] != dummy && data[index]->key != key) {
        index = (index + 1) % data.size();
    }

    data[index] = new HashNode(key, value); //insert the new node
    n++; //increment the size
}

template<typename K, typename V>
void HashMap<K,V>::display() const {
    for (int i = 0; i < data.size(); i++) {
        std::cout << i;
        if (!data[i]) {
            std::cout << " ---\n";
        }
        else if (data[i] == dummy) {
            std::cout << " deleted\n";
        }
        else {
            std::cout << " {" << data[i]->key << "; " << data[i]->value << "}\n";
        }
    }
}

template<typename K, typename V>
V HashMap<K,V>::search(const K& key) const {
    int index = search_index(key);

    if (index != -1) {
        return data[index]->value;
    }

    return V();
}

template<typename K, typename V>
void HashMap<K,V>::remove(const K& key) {
    int index = hash(key);
    int counter = 0;
    while (data[index] && data[index] != dummy) {
        if (counter++ > data.size()) {
            return;
        }
        if (data[index]->key == key) {
            delete data[index];
            data[index] = dummy;
            n--;
            return;
        }
        index = (index + 1) % data.size();
    }
}


/***
 * 
 * PRIVATE METHODS
 * 
*/

template<typename K, typename V>
int HashMap<K,V>::nextPrime(int n) const {
    while (1) {
        bool isPrime = true;
        for(int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                isPrime = false;
                n++;
                break;
            }
        }
        if (isPrime) {
            return n;
        }
    }
}

template<typename K, typename V>
int HashMap<K,V>::hash(const K& key) const {
    std::hash<K> hash_value;
    return hash_value(key) % data.size();
}

template<typename K, typename V>
void HashMap<K,V>::set_dummy() {
    int bits = sizeof(dummy->key) * 8;
    // for(int i = 0; i < bits; i++) {
    //     std::cout << (int)1 << i << std::endl;
    //     dummy->key |= (int)1 << i;
    // }
    // std::cout << sizeof(dummy->key) << std::endl;
    std::bitset<100> x(dummy->key);
    std::cout << x << '\n';
}

template<typename K, typename V>
int HashMap<K,V>::search_index(const K& key) const {
    int counter = 0;
    int index = hash(key);

    while (data[index]) { 
        if (counter++ >= data.size()) {
            return -1;
        }

        if (data[index]->key == key) {
            return index;
        }

        index = (index + 1) % data.size();
    }

    return -1;
}

