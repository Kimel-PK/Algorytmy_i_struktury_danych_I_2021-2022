#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <class T> void sort(std::vector<T>& v) {
	
	int min_pos;
	T temp;
	
	for (int i = 0; i < (int)v.size(); i++) {
		min_pos = i;
		for (int j = i; j < (int)v.size(); j++) {
			
			if (v[j] < v[min_pos]) {
				min_pos = j;
			}
		}
		temp = v[min_pos];
		v[min_pos] = v[i];
		v[i] = temp;
	}
}

int main () {
	
	int wejscie_int;
	vector<int> liczby;
	
	while (cin >> wejscie_int) { // czytaj aż skończy się wejście
		liczby.push_back (wejscie_int);
	}
	
	auto start = chrono::high_resolution_clock::now();
	sort<int> (liczby);
	auto end = chrono::high_resolution_clock::now();
	
	chrono::duration<double> elapsed = end - start;
	cout << " " << elapsed.count() << endl;
	
	/*
	for(const auto& i : liczby)
		std::cout << i << std::endl;
	*/
	
}