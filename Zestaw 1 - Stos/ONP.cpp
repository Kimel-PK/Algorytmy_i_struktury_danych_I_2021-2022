#include <stdio.h>
#include <string>
#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

int PriorytetOperatora (char znak) {
	if (znak == '(' || znak == ')') {
		return 0;
	} else if (znak == '=') {
		return 1;
	} else if (znak == '-' || znak == '+') {
		return 2;
	} else if (znak == '*' || znak == '/') {
		return 3;
	} else if (znak == '^') {
		return 4;
	} else {
		throw out_of_range ("Nieznany operator");
	}
}

int main (int argc, char *argv[]) {
    
    string wejscie;
    string wyjscie;
    bool cyfra = false;
	
    getline(cin, wejscie);
    
	Stack<char, 20> stos;
	
	for (char znak : wejscie) {
		
		if (znak == ' ') { // program czyta cyfry, spacja jest wstawiana dopiero na koniec liczby
			if (cyfra == true) {
				wyjscie += " ";
				cyfra = false;
			}
			continue;
		}
		
		if (znak > 47 && znak < 58) { // znak jest cyfrą
            wyjscie += znak; // wrzuć na wyjście
			cyfra = true;
        } else { // znak jest operatorem
			if (znak == '(') {
				stos.push (znak);
			} else if (znak == ')') {
				while (stos.top() != '(') {
					wyjscie += stos.pop();
					wyjscie += " ";
				}
				stos.pop();
			} else if (stos.size() > 0 && PriorytetOperatora (znak) > PriorytetOperatora (stos.top())) { // jeśli priorytet jest wyższy niż na stosie
				stos.push (znak); // wrzuć na stos
			} else {
				while (stos.size() > 0 && PriorytetOperatora (znak) <= PriorytetOperatora (stos.top())) { // priotytet jest niższy
					wyjscie += stos.pop(); // zrzucaj ze stosu aż będzie
					wyjscie += " ";
				}
				stos.push (znak);
			}
		}
        
	}
	
	while (stos.size() > 0) {
		wyjscie += stos.pop();
		wyjscie += " ";
	}
	
	cout << wyjscie << endl;
    
}