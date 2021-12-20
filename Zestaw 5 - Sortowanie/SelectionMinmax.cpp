#include <iostream>
#include <vector>

using namespace std;

template <class T> void sort(std::vector<T>& v) {
	
	int min_pos;
	int max_pos;
	int max;
	T temp;
	
	for (int i = 0, n = v.size() - 1; i < n; i++, n--) {
		min_pos = i;
		max_pos = i;
		max = v[i];
		
		for (int j = i; j <= n; j++) {
			
			if (v[j] < v[min_pos]) {
				min_pos = j;
			}
			if (v[j] > v[max_pos]) {
				max_pos = j;
				max = v[j];
			}
		}
		
		temp = v[min_pos];
		v[min_pos] = v[i];
		v[i] = temp;
		
		if (v[min_pos] == max) {
			temp = v[min_pos];
			v[min_pos] = v[n];
			v[n] = temp;
		} else {
			temp = v[max_pos];
			v[max_pos] = v[n];
			v[n] = temp;
		}
		
	}
	
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