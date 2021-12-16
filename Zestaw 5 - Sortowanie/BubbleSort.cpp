#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <class T> void sort(std::vector<T>& v) {
	
	T temp;
	
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < i; j++) {
			
			if (v[i] < v[j]) {
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
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