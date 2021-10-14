#include <stdio.h>
#include <string>
#include <ArrayStack.hpp>

using namespace std;

// 2-(a*3-(4+a*c-b))
// 
// -(a*3-(4+a*c-b))			            2
// (a*3-(4+a*c-b))		    -	        2
// a*3-(4+a*c-b))		    -(	        2
// *3-(4+a*c-b))  	    	-(	        2 a
// 3-(4+a*c-b))	    	    -(*     	2 a
// -(4+a*c-b))		        -(*	        2 a 3
// (4+a*c-b))		        -(-     	2 a 3 *
// 4+a*c-b))		        -(-(    	2 a 3 *
// +a*c-b))		            -(-(	    2 a 3 * 4
// a*c-b))		            -(-(+	    2 a 3 * 4
// *c-b))		            -(-(+	    2 a 3* 4 a
// c-b))		            -(-(+*  	2 a 3 * 4 a
// -b))		                -(-(+*  	2 a 3 * 4 a c
// b))		                -(-(-	    2 a 3 * 4 a c * +
// ))		                -(-(-   	2 a 3 * 4 a c * + b
// )		                -(-	        2 a 3 * 4 a c * + b -
// 		                    -	        2 a 3 * 4 a c * + b - -
// 		                    	        2 a 3 * 4 a c * + b - - -

int main (int argc, char *argv[]) {
    
    string wejscie;
    string result = (char*)malloc (); // wyjście nie może być większe niż wejście
	
	Stack<int, 20> stack;
	
    for (int i = 0; i < wejscie.length(); i++) {
        
        if (stoi(string(1, wejscie[i])) == 0) { // znak jest liczbą
            // wrzuć na wyjście
        } else if (wejscie[i] == '(') { // znak jest operatorem innym niż zakończenie nawiasu
            // wrzuć na stos
        } else if (wejscie[i] == ')') { // znak jest końcem nawiasu
            while (stack.top() != ')') {
                
            }
        }
        
    }
    
    // (11 + ((((1 + 2) * (4 - 3)) + (4 / 2)) * (8 - 6)))
    
    // 
    
    // weź pierwszy element stringa
    // jeśli to liczba
        // wypisz do wyjścia
    // jeśli operator
        // wrzuć operator na stos
    // jeśli nawias zamykający
        // zrzuć ze stosu wszystkie operatory aż do "("
    
    // 12+34+*
    
}