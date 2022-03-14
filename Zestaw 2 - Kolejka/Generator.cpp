#include <iostream>
#include <stdlib.h>
#include <time.h>

#define OPERACJE 1000000

using namespace std;

int main () {
	
	srand(time(NULL)); // ustawiamy ziarno generatora losowego
	
	int n = rand() % OPERACJE; // losujemy ilość operacji
	cout << n << endl; // pierwszy wiersz to ilośc operacji
	
	for (int i = 0; i < n; i++) { // wypisujemy OPERACJE losowych danych w podanym formacie
		switch (rand() % 3) {
			case 0:
				cout << "A" << " " << rand() % 1000000 << endl; // wstaw na stos wartość X
				break;
			case 1:
				cout << "D" << endl; // zdejmij ze stosu
				break;
			case 2:
				cout << "S" << endl; // wypisz ilość elementów stosu
				break;
		}
	}
	
}