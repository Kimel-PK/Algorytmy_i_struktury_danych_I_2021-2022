#include <iostream>
#include <vector>

using namespace std;

template <class T> void sort(std::vector<T>& v) {
	
	int range_min;
	int range_max;
	
	if (v.size() != 0) {
		range_min = v[0];
		range_max = v[0];
	}
	
	for(int i = 1; i < v.size(); i++) {
		if (v[i] < range_min)
			range_min = v[i];
		if (v[i] > range_max)
			range_max = v[i];
	}
	
	int size = range_max - range_min + 1;
	int count[size];
	
	for(int i = 0; i < size; i++) {
		count[i] = 0;
	}
	
	for(T number : v) {
		count[number - range_min]++;
	}
	for(int i = 1; i < size; i++) {
		count[i] += count[i-1];
	}
	
	T v_sorted_arr[v.size()];
	for(int i = 0; i < v.size(); i++) {
		v_sorted_arr[count[v[i] - range_min] - 1] = v[i];
		count[v[i] - range_min]--;
	}
	
	vector<T> v_sorted;
	for (int i = 0; i < v.size(); i++) {
		v_sorted.push_back (v_sorted_arr[i]);
	}
	
	v = v_sorted;
	
}


int main () {
	
	int wejscie_int;
	vector<int> liczby;
	
	while (cin >> wejscie_int) { // czytaj aż skończy się wejście
		liczby.push_back (wejscie_int);
	}
	
	sort<int> (liczby);
	
	for(const auto& i : liczby)
		std::cout << i << std::endl;
	
}