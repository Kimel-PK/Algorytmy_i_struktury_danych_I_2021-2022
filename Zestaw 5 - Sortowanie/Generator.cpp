#include <iostream>
#include <time.h>

using namespace std;

int main (int argc, char *argv[]) {
	
	int n = atoi (argv[1]);
	int los_max = atoi (argv[2]);
	
	for (int i = 0; i < n; i++) {
		cout << rand() % los_max << endl;
	}
	
}