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

template<class K, class E>
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

		inline bool empty(){
			return table.empty();
		}

		void initialise();

		bool insert(const K &k, const E &e);

		inline int size(){
			return length;
		}

		E* find(const K &key);

		void erase(const K &key);

		inline void clear(){
			table.clear();
		}

		inline size_t hash(const K &k) {
			return k % table.size();
		}

	private:

		int length;
		int insertions = 0;

};


#endif //PROJECT2_HASHTABLE_H
