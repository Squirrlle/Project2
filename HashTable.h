//
// Created by henry on 4/15/19.
//

#ifndef PROJECT2_HASHTABLE_H
#define PROJECT2_HASHTABLE_H

#include <iostream>
#include <vector>
using namespace std;

template<class K, class E>
struct HashNode {
	K key;
	E element;
	HashNode(const K &k, const E &e) : element(e), key(k) {}
};

template<class T> struct myHash {
};

template<> struct myHash<string> {
	static size_t hashFunction(const string& s) {
		return hash<string>()(s);
	}
};

template<> struct myHash<int> {
	static size_t hashFunction(const int m) {
		return hash<int>()(m);
	}
};

template<class K, class E, class HashGenerator = myHash<K> >
class HashTable {
	public:

		vector<vector<HashNode<K, E>>> table;
		HashTable() {
			length = 1;
			for(int i = 0; i < length; i++) {
				vector<HashNode<K, E> > e;
				table.push_back(e);
			}
		}

		bool empty(){
			return table.empty();
		}

		void intitalise(){
			for(int i = 0; i < (length - insertions); i++) {
				vector<HashNode<K, E> > e;
				table.push_back(e);
			}
		}

		bool insert(const K &k, const E &e) {
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
				intitalise();

			}
			return true;
		}

		int size(){
			return length;
		}

		E* find(const K &key) {
			for(int i = 0; i < table[hash(key)].size(); i++) {
				if (table[hash(key)][i].key == key) {
					return &table[hash(key)][i].element;
				}
			}
			return nullptr;
		}

		void erase(const K &key){
			for(int i = 0; i < table[hash(key)].size(); i++) {
				if (table[hash(key)][i].key == key) {
					table[hash(key)][i].element = NULL;
					table[hash(key)][i].key = NULL;
				}
			}
		}

		void clear(){
			table.clear();
		}

		size_t hash(const K &k) {
			return HashGenerator::hashFunction(k) % table.size();
		}

	private:

		int length;
		int insertions = 0;

};


#endif //PROJECT2_HASHTABLE_H
