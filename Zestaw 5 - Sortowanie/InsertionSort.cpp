#include <iostream>
#include <vector>
// #include <chrono>

using namespace std;

template <class T> void sort(std::vector<T>& v) {
	
	int comparisons = 0;
	
	vector<T> v_sorted;
	T temp;
	
	temp = v.back();
	v.pop_back();
	v_sorted.push_back (temp);
	
	while (v.size() != 0) {
	    
		temp = v.back();
		v.pop_back();
		
		bool found = false;
		for (int i = 0; i < (int)v_sorted.size() && !found; i++) {
			comparisons++;
			if (temp < v_sorted[i]) {
				v_sorted.insert (v_sorted.begin() + i, temp);
				found = true;
			}
		}
		if (!found) {
			v_sorted.push_back (temp);
		}
	}
	
	cerr << "Comparison operations: " << comparisons << endl;
	
	v = v_sorted;
	
}

int main () {
	
	int wejscie_int;
	vector<int> liczby;
	
	while (cin >> wejscie_int) { // czytaj aż skończy się wejście
		liczby.push_back (wejscie_int);
	}
	
	// auto start = chrono::high_resolution_clock::now();
	sort<int> (liczby);
	// auto end = chrono::high_resolution_clock::now();
	
	// chrono::duration<double> elapsed = end - start;
	// cout << " " << elapsed.count() << endl;
	
	for(const auto& i : liczby)
		std::cout << i << std::endl;
	
}