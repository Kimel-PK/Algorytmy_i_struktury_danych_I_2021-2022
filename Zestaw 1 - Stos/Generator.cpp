#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main () {
    
    srand(time(NULL)); // ustawiamy ziarno generatora losowego
    
    int n = rand() % 100;
    cout << n << endl;
    
    for (int i = 0; i < n; i++) {   
        switch (rand() % 3) {
            case 0:
                cout << "A" << " " << rand() % 1000000 << endl;
                break;
			case 1:
				cout << "D" << endl;
				break;
			case 2:
				cout << "S" << endl;
				break;
        }
    }
    
}