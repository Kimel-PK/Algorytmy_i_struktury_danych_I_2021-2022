#include <iostream>
#include <stdlib.h>
#include "ArrayList.hpp"

#define ROZMIAR 1000

using namespace std;

int main (int argc, char *argv[]) {
	
	/*
	
	ArrayList<ROZMIAR> lista = ArrayList<ROZMIAR>();
	
	lista.push_front(69);
	lista.push_front(1);
	lista.push_front(2);
	lista.push_front(69);
	lista.push_front(69);
	lista.push_front(3);
	lista.push_front(4);
	lista.push_front(5);
	lista.push_front(69);
	lista.push_front(6);
	lista.push_front(7);
	lista.push_front(69);
	lista.push_front(69);
	lista.push_front(69);
	lista.push_front(8);
	lista.push_front(9);
	lista.push_front(69);
	lista.push_front(10);
	lista.push_front(69);
	
	cout << "remove " << lista.remove(69) << endl;
	
	lista.WypiszListe();
	
	*/
	
	char wejscie_char;
	int wejscie_int;
	int operacje;
	
	// pierwsza odczytana liczba to ilość operacji do wykonania
	cin >> operacje;
	
	ArrayList<ROZMIAR> lista = ArrayList<ROZMIAR>();
	
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
		} else if (wejscie_char == 'f') { // usuń z początku listy
			if (lista.size() > 0)
				cout << lista.pop_front() << endl;
			else
				cout << "EMPTY" << endl;
		} else if (wejscie_char == 'b') { // usuń z końca listy
			if (lista.size() > 0)
				cout << lista.pop_back() << endl;
			else
				cout << "EMPTY" << endl;
		} else if (wejscie_char == 'R') { // znajdź i zamień element
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