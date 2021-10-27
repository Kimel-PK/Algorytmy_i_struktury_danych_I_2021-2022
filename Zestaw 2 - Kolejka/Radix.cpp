#include <iostream>
#include <vector>
#include <math.h>
#include "ArrayQueue.hpp"

using namespace std;

void radix(vector<int>& v) {
	
	Queue<int, 110> kolejki[10];
	
	for (int i = 0; i < 3; i++) {
		
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			
			int liczba = *it;
			kolejki[(liczba / (int)pow (10, i)) % 10].push(liczba);
			
		}
		
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
	
	v.push_back (61);
	v.push_back (91);
	v.push_back (655);
	v.push_back (53);
	v.push_back (5);
	v.push_back (64);
	v.push_back (519);
	v.push_back (123);
	v.push_back (1);
	v.push_back (741);
	
	/*
	while (cin >> liczba) {
		v.push_back(liczba);
	}
	*/
	
	radix (v);
	
	for(const auto& i : v)
    	cout << i << endl;
	
}