#include <iostream>
#include <vector>
#include <math.h>
#include "ArrayQueue.hpp"

#define ROZMIAR 1000000

using namespace std;

void radix(vector<int>& v) {
	
	Queue<int, ROZMIAR> kolejki[10];
	bool koniec = false;
	
	for (int i = 0; !koniec; i++) {
		
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			int liczba = *it;
			kolejki[(liczba / (int)pow (10, i)) % 10].push(liczba);
		}
		
		if (kolejki[0].size() == (int)v.size())
			koniec = true;
		
		v.clear();
		
		for (int j = 0; j < 10; j++) {
			while (!kolejki[j].empty()) {
				v.push_back (kolejki[j].pop());
			}
		}
		
	}
	
}

int main () {
	
	int liczba;
	vector<int> v;
	
	while (cin >> liczba) {
		v.push_back(liczba);
	}
	
	radix (v);
	
	for(const auto& i : v)
    	cout << i << endl;
	
}