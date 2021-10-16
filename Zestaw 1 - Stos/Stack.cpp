/*

przykładowe operacje

wejście:

5
A 12
D
S
D
A 34
D

wyjście:

12
0
EMPTY
34

*/

#include <iostream>
#include <stdlib.h>
#include "ArrayStack.hpp"

using namespace std;

int main (int argc, char *argv[]) {
    
    int rozmiarStosu;
    cin >> rozmiarStosu;
    Stack<int, rozmiarStosu> stos;
    
    char wejscie;
    
    while (cin >> wejscie) {
        cout << wejscie;
        
        if (wejscie == 'A') { // wrzuć na stos
            
        } else if (wejscie == 'D') { // zdejmij ze stosu
            if (!stos.empty())
                cout << stos.pop() << endl;
            else
                cout << "EMPTY" << endl;
        } else if (wejscie == 'S') { // wypisz liczbę elementów
            cout << stos.size();
        }
    }
    
    /*
    
    
    
    stos.push (5);
    cout << stos.size() << endl;
    stos.pop();
    
    */
    
};