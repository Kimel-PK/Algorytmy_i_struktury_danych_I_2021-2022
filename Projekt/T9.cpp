#include <iostream>
#include "Trie.hpp"
#include "WordsList.hpp"

using namespace std;

/*
	Klawiatura telefonu
	1 - .,
	2 - aąbcć
	3 - deęf
	4 - gh
	5 - ijk
	6 - lłmnńoó
	7 - prsś
	8 - tuw
	9 - zżź
	0 - spacja
	# - zmaż znak
	* - następne słowo

*/

int main (int argc, char const *argv[]) {
	
	Trie T9;
	T9.Add("slowo");
	
	// rozpocznij wyszukiwanie
	Trie::TrieNode* T9_search = T9.Start();
	T9_search = T9.Next (T9_search, 7);
	T9_search = T9.Next (T9_search, 5);
	T9_search = T9.Next (T9_search, 6);
	T9_search = T9.Next (T9_search, 9);
	T9_search = T9.Next (T9_search, 6);
	
	WordsList::WordNode* slowa = T9.GetWords (T9_search);
	
	cout << "test" << endl;
	
	cout << slowa->value.word << endl;
	
	/*
	if (T9_search != nullptr) {
		WordsList::WordNode* znalezione_słowa = T9.GetWords (T9_search);
		
		cout << znalezione_słowa->value.frequency << endl;
	}
	*/
	
	// odczytaj listę podstawowych słów z pliku
	
	// dodaj listę podstawowych słów do drzewa
	
	// uruchom interfejs graficzny
	
	return 0;
}