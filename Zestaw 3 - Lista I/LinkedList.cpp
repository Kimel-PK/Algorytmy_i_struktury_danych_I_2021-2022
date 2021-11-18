#include <iostream>
#include <stdlib.h>
#include "LinkedList.hpp"

#define ROZMIAR 1000

using namespace std;

int main (int argc, char *argv[]) {
	
	char wejscie_char;
	int wejscie_int;
	int operacje;
	
	// pierwsza odczytana liczba to ilość operacji do wykonania
	cin >> operacje;
	
	List<int, ROZMIAR> lista = List<int, ROZMIAR>();
	
	for (;operacje > 0; operacje--) { // czytaj aż skończy się wejście
		
		cin >> wejscie_char;
		
		if (wejscie_char == 'F') { // wstaw na początek listy
			cin >> wejscie_int;
			if (lista.size() < ROZMIAR) {
				lista.push_front (wejscie_int);
			}
		} else if (wejscie_char == 'B') { // wstaw na koniec listy
			cin >> wejscie_int;
			if (lista.size() < ROZMIAR) {
				lista.push_back (wejscie_int);
			}
		} else if (wejscie_char == 'f') {
			if (lista.size() > 0)
				cout << lista.pop_front() << endl;
			else
				cout << "EMPTY" << endl;
		} else if (wejscie_char == 'b') {
			if (lista.size() > 0)
				cout << lista.pop_back() << endl;
			else
				cout << "EMPTY" << endl;
		} else if (wejscie_char == 'R') {
			cin >> wejscie_int;
			int dana;
			cin >> dana;
			if (lista.replace (wejscie_int, dana)) {
				cout << "TRUE" << endl;
			} else {
				cout << "FALSE" << endl;
			}
		} else if (wejscie_char == 'S') { // wypisz liczbę elementów
			cout << lista.size() << endl;
		}
		
	}
	
}