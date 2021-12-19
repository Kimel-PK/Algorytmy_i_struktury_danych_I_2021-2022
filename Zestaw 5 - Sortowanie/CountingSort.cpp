#include <iostream>
#include <vector>

using namespace std;

template <class T> void sort(std::vector<T>& v) {
	
	
	
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