// onp.cpp
// stack.cpp

// przykładowe operacje
/*

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
    
    Stack<int, 8> stos;
    
    stos.push (5);
    cout << stos.size() << endl;
    stos.pop();
    
};