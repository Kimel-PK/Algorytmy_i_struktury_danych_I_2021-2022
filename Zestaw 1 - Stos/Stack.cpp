#include <iostream>
#include <stdlib.h>
#include "ArrayStack.hpp"

#define ROZMIAR 1000000

using namespace std;

int main (int argc, char *argv[]) {
	
	char wejscie_char;
	int wejscie_int;
	int operacje;
	
	// pierwsza odczytana liczba to ilość operacji do wykonania
	cin >> operacje;
	
	Stack<int, ROZMIAR>* stos = new Stack<int, ROZMIAR>;
	
	for (;operacje > 0; operacje--) { // czytaj aż skończy się wejście
		
		cin >> wejscie_char;
		
		if (wejscie_char == 'A') { // wrzuć na stos
			if (stos->size() < ROZMIAR) {
				cin >> wejscie_int;
				stos->push (wejscie_int);
			}
		} else if (wejscie_char == 'D') { // zdejmij ze stosu
			if (!stos->empty())
				cout << stos->pop() << endl;
			else
				cout << "EMPTY" << endl;
		} else if (wejscie_char == 'S') { // wypisz liczbę elementów
			cout << stos->size() << endl;
		}
	}
	
	delete stos;
	
};