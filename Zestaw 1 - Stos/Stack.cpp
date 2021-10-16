#include <iostream>
#include <stdlib.h>
#include "ArrayStack.hpp"

#define ROZMIAR 1000000

using namespace std;

int main (int argc, char *argv[]) {
    
    cout << "Stack.exe działa" << endl;
    
    char wejscie_char;
    int wejscie_int;
    
    // pierwsza odczytana liczba to ilość operacji do wykonania, ignorujemy tą wartość
    cin >> wejscie_int;
    
    Stack<int, ROZMIAR> stos;
    
    while (cin >> wejscie_char) {
        cout << wejscie_char;
        
        if (wejscie_char == 'A') { // wrzuć na stos
            cin >> wejscie_int;
            stos.push (wejscie_int);
        } else if (wejscie_char == 'D') { // zdejmij ze stosu
            if (!stos.empty())
                cout << stos.pop() << endl;
            else
                cout << "EMPTY" << endl;
        } else if (wejscie_char == 'S') { // wypisz liczbę elementów
            cout << stos.size() << endl;
        }
    }
    
};