#include <iostream>
#include <stdlib.h>
#include "ArrayQueue.hpp"

#define ROZMIAR 1000000

using namespace std;

int main (int argc, char *argv[]) {
	
	char wejscie_char;
	int wejscie_int;
	int operacje;
	
	// pierwsza odczytana liczba to ilość operacji do wykonania
	cin >> operacje;
	
	Queue<int, ROZMIAR>* kolejka = new Queue<int, ROZMIAR>;
	
	for (;operacje > 0; operacje--) { // czytaj aż skończy się wejście
		
		cin >> wejscie_char;
		
		if (wejscie_char == 'A') { // wrzuć do kolejki
			if (kolejka->size() < ROZMIAR) {
				cin >> wejscie_int;
				kolejka->push (wejscie_int);
			}
		} else if (wejscie_char == 'D') { // wyjmij z kolejki
			if (!kolejka->empty()) {
				cout << kolejka->pop() << endl;
			} else {
				cout << "EMPTY" << endl;
			}
		} else if (wejscie_char == 'S') { // wypisz liczbę elementów
			cout << kolejka->size() << endl;
		}
		
	}
	
	delete kolejka;
	
};