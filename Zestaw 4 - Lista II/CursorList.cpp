#include <iostream>
#include <stdlib.h>
#include "CursorList.hpp"

#define ROZMIAR 1000

using namespace std;

int main (int argc, char *argv[]) {
	
	// /*
	
	CursorList<ROZMIAR> lista = CursorList<ROZMIAR>();
	
	lista.push_front (627);
	lista.push_front (993);
	lista.pop_back ();
	lista.pop_back ();
	lista.push_front (1);
	lista.push_back (627);
	lista.pop_front ();
	lista.pop_front ();
	lista.push_front (57);
	lista.push_front (69);
	lista.push_back (43);
	lista.push_back (15);
	lista.push_back (80);
	lista.replace (69, 96);
	lista.insert (0, 1);
	lista.insert (5, 5);
	// lista.pop_front();
	// lista.push_back (240);
	// lista.pop_back ();
	// lista.pop_front();
	// lista.push_front (480);
	// lista.pop_back ();
	// lista.replace (100, 324);
	// lista.replace (90, 224);
	// lista.replace (381, 558);
	// lista.replace (953, 797);
	// lista.push_front (117);
	// lista.replace (320, 24);
	// lista.push_back (197);
	
	lista.WypiszListe();
	
	/*
	
	char wejscie_char;
	int wejscie_int;
	int operacje;
	
	// pierwsza odczytana liczba to ilość operacji do wykonania
	cin >> operacje;
	
	CursorList<ROZMIAR> lista = CursorList<ROZMIAR>();
	
	int i = 2;
	for (;operacje > 0; operacje--) { // czytaj aż skończy się wejście
		
		cin >> wejscie_char;
		// cout << i << " - " << wejscie_char << endl;
		
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
		
		i++;
		
	}
	
	*/
	
}