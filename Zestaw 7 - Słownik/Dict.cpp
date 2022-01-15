#include <iostream>
#include <fstream>
#include "Dict.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	
	Dict<string, string> słownik;
	
	string wejscie_string;
	string wejscie_string2;
	
	ifstream plik;
	plik.open (argv[1], fstream::in);
	
	while (plik >> wejscie_string) {
		plik >> wejscie_string2;
		słownik.insert (make_pair(wejscie_string, wejscie_string2));
	}
	
	while (cin >> wejscie_string) {
		if (słownik.find (wejscie_string))
			cout << słownik[wejscie_string] << endl;
		else
			cout << "-" << endl;
	}
	
	plik.close();
}