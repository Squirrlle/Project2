//
// Created by henry on 4/15/19.
//

#include "HashTable.h"
#include <vector>
#include <iostream>
using std::vector;

template <class K, class E>
void HashTable<K, E>::initialise(){
    for(int i = 0; i < (length - insertions); i++) {
        vector<HashNode<K, E> > e;
        table.push_back(e);
    }
}

template <class K, class E>
bool HashTable<K, E>::insert(const K &k, const E &e) {
    HashNode<K, E> b(k, e);
    for(int i = 0; i < table[hash(k)].size(); i++) {
        if (table[hash(k)][i].key == k) {
            table[hash(k)][i] = b;
            return false;
        }
    }
    table[hash(k)].push_back(b);
    if(length == ++insertions){
        length = (length * 2) + 1;
        initialise();

    }
    return true;
}

template <class K, class E>
void HashTable<K, E>::erase(const K &key) {
    for(int i = 0; i < table[hash(key)].size(); i++) {
        if (table[hash(key)][i].key == key) {
            table[hash(key)][i].element = NULL;
            table[hash(key)][i].key = NULL;
        }
    }
}

template <class K, class E>
E* HashTable<K, E>::find(const K &key) {
    for(int i = 0; i < table[hash(key)].size(); i++) {
        if (table[hash(key)][i].key == key) {
            return &table[hash(key)][i].element;
        }
    }
    return nullptr;
}