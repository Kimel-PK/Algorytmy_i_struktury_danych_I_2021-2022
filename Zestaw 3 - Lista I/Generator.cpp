#include <iostream>
#include <stdlib.h>
#include <time.h>

#define OPERACJE 1000

using namespace std;

int main () {
    
    srand(time(NULL)); // ustawiamy ziarno generatora losowego
    
    int n = rand() % OPERACJE; // losujemy ilość operacji
    cout << n << endl; // pierwszy wiersz to ilość operacji
    
    for (int i = 0; i < n; i++) { // wypisujemy OPERACJE losowych danych w podanym formacie
        switch (rand() % 6) {
            case 0:
                cout << "F" << " " << rand() % 1000 << endl; // wstaw x na początek listy
                break;
			case 1:
				cout << "B" << " " << rand() % 1000 << endl; // wstaw x na koniec listy
				break;
			case 2:
				cout << "f" << endl; // usuń z listy pierwszy element i wypisz go
				break;
            case 3:
                cout << "b" << endl; // usuń z listy ostatni element i wypisz go
                break;
            case 4:
                cout << "R" << " " << rand() % 1000 << " " << rand() % 1000 << endl; // zastąp element x przez element y
                break;
            case 5:
                cout << "S" << endl; // wypisz rozmiar listy
                break;
        }
    }
    
}