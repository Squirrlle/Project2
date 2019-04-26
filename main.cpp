#include <iostream>
#include "HashTable.cpp"
using std::cout;
using std::endl;

int main() {

	HashTable<int, int> t;



	for(int i = 0; i < 10; ++i){
		t.insert(i, i*3);
	}
	
	for(int x = 0; x < 10; ++x){
		cout << "Key: " << x << " element: " << *t.find(x) << endl;
	}
	cout << "Size: " << t.size() << endl;
	t.erase(3);
	cout << endl;
	for(int x = 0; x < 10; ++x){
		if(t.find(x) != nullptr){
			cout << "Key: " << x << " element: " << *t.find(x) << endl;
		}
		else{
			cout << "nllptr found" << endl;
		}
	}
	cout << t.find(3) << endl;
	t.clear();
	if(t.empty()){
		cout << "t is now empty" << endl;
	}

		return 0;
}
