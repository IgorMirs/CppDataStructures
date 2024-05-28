#ifndef HASH_NODE_H
#define HASH_NODE_H

template<typename K, typename V>
class HashNode {
public:
    HashNode(const K& key, const V& value) : key(key), value(value) {}

    K key;
    V value;
};

#endif