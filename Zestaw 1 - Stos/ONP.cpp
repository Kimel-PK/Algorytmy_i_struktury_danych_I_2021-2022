#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include "ArrayStack.hpp"

using namespace std;

int main (int argc, char *argv[]) {
	
	string wejscie;
	string wyjscie;
	bool cyfra = false;
	
	map<char, int> priorytetOperatora {
		{'(', 0},
		{')', 0},
		{'=', 1},
		{'-', 2},
		{'+', 2},
		{'*', 3},
		{'/', 3},
		{'^', 4},
	};
	
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
			} else if (stos.size() > 0 && priorytetOperatora [znak] > priorytetOperatora [stos.top()]) { // jeśli priorytet jest wyższy niż na stosie
				stos.push (znak); // wrzuć na stos
			} else {
				while (stos.size() > 0 && priorytetOperatora [znak] <= priorytetOperatora [stos.top()]) { // priotytet jest niższy
					wyjscie += stos.pop(); // zrzucaj ze stosu aż priorytet będzie wyższy
					wyjscie += " ";
				}
				stos.push (znak);
			}
		}
		
	}
	
	while (stos.size() > 0) {
		wyjscie += "x";
		wyjscie += stos.pop();
	}
	
	if (wyjscie[wyjscie.size() - 1] == ' ') {
		wyjscie = wyjscie.substr (0, wyjscie.size() - 1);
	}
	
	cout << wyjscie << endl;
	
}