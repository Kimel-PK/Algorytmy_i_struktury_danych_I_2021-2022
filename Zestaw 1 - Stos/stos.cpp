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

#include <stdio.h>
#include <stdlib.h>

using namespace std;

template<class T, int N>
class Stack {
    public:
    template<class U>
    
    Stack (int capacity) {
        data[] = (int[])malloc (capacity * sizeof(int));
    }
    
    void push(U&& x) {
        data[length++] = x;
    }
    
    T pop() {
        return data[--length];
    }
    
    T& top() {
        return &data[length];
    }
    
    int size() {
        return length;
    }
    
    bool empty() {
        if (length == 0) {
            printf ("EMPTY");
        }
    }
    
    private:
    int length;
    int data[];
};

int main () {
    
    Stack stack(10);
    
}