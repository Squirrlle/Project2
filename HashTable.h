//
// Created by henry on 4/15/19.
//

#ifndef PROJECT2_HASHTABLE_H
#define PROJECT2_HASHTABLE_H

#include <vector>
#include <iostream>
using std::vector;

template  <typename  K, typename E>
class HashNode{

public:
    E element;
    K key;

    HashNode(K key, E element){
        this->element = element;
        this->key = key;
    }
};

template  <typename  K, typename E>
class HashTable {
public:

    HashTable(){}

    inline int size(){}

    E * find(K key){}

    void erase(K key){}

    bool insert(K key, E element){}

    void clear(){}

private:

    K key;
    E element;
    int length;

};


#endif //PROJECT2_HASHTABLE_H
