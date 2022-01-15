#ifndef WORDSLIST_HPP
#define WORDSLIST_HPP

#include <iostream>

#define CAPACITY 1000

// !! usunąć to
using namespace std;

class WordsList {
	
	public:
	
	struct Word {
		
		std::string word;
		int frequency;
		
		Word (std::string _word = "", int _freq = 0) {
			word = _word;
			frequency = _freq;
		}
		
	};
	
	struct WordNode {
		Word value;
		WordNode* next;
		WordNode* prev;
	};
	
	WordsList () {
		guard = new WordNode();
		guard->next = guard;
		guard->prev = guard;
		_size = 0;
	}
	
	~WordsList () {
		while (!Empty()) {
			
			// pop front
			WordNode* temp = guard->next;
			guard->next = temp->next;
			temp->next->prev = guard;
			
			delete temp;
		}
		delete guard;
	}
	
	int Size () {
		return _size;
	}
	
	bool Empty () { // Zwraca true gdy lista jest pusta
		if (_size == 0)
			return true;
		else
			return false;
	}
	
	void AddWord (Word x) { // !! wstawić słowo w odpowiednie miejsce
		
		WordNode* temp = new WordNode();
		temp->value = x;
		
		WordNode* insert = guard;
		for (int n = 0; n < x.frequency; n++) {
			insert = insert->next;
		}
		
		temp->next = insert->next;
		temp->prev = insert;
		insert->next->prev = temp;
		insert->next = temp;
		_size++;
		
	}
	
	WordNode* GetFirstWord () {
		cout << "Pobieranie pierwszego słowa" << endl;
		cout << guard->next << endl;
		cout << guard->next->value.word << endl;
		return guard->next;
	}
	
	WordNode* GetNextWord (WordNode* node) {
		return node->next;
	}
	
	private:
	
	WordNode* guard;
	int _size;
	
};

#endif