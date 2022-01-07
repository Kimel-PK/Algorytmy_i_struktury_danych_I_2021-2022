#include <iostream>
#include <vector>
#include "BinaryTree.hpp"

using namespace std;

int main () {
	
	int wejscie_int;
	BinaryTree drzewo;
	
	int operacje; // ilośc liczb do wczytania
	cin >> operacje;
	
	for (; operacje > 0; operacje--) { // czytaj aż skończy się wejście
		cin >> wejscie_int;
		drzewo.insert (wejscie_int);
	}
	
	cout << drzewo.size() << " " << drzewo.depth() << " " << drzewo.minimum() << " " << drzewo.maximum() << endl;
	drzewo.preorder();
	for (int i = 1; i < 10; i++) {
		if (drzewo.search(i) != nullptr) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	
}