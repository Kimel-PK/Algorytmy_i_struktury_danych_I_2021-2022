#ifndef WORDSLIST_HPP
#define WORDSLIST_HPP

#include <iostream>

#define CAPACITY 10000

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
	};
	
	WordsList () {
		guard = new WordNode();
		guard->next = guard;
		_size = 0;
	}
	
	~WordsList () {
        while (!Empty()) {

            WordNode* temp = guard->next;
            guard->next = guard->next->next;

            delete temp;
            _size--;
		}
		delete guard;
	}
	
	int Size () {
		return _size;
	}
	
    bool Empty () {
		if (_size == 0)
			return true;
		else
			return false;
	}
	
    void AddWord (Word x) {
		
		WordNode* temp = new WordNode();
		temp->value = x;
		
        WordNode* insert = guard->next;
        for (int i = 0; x.frequency < insert->next->value.frequency && i < Size(); i++) {
			insert = insert->next;
		}
		
		temp->next = insert->next;
		insert->next = temp;
		_size++;
		
	}

    WordNode* GetFirstWord () {
        return guard->next;
	}

    void ShowList () {
        std::cout << "Słowa w obecnym węźle" << std::endl;
        WordNode* node = guard->next;
        while (node != guard) {
            std::cout << node->value.word << " - " << node->value.frequency << std::endl;
            node = node->next;
        }
    }

	private:

	WordNode* guard;
	int _size;
	
};

#endif
