#include <map>
#include "WordsList.hpp"

// !! usunąć to
using namespace std;

class Trie {
	
	public:
	class TrieNode {
		
		private:
		
		TrieNode* parent = nullptr;
		TrieNode** nodes = new TrieNode*[8];
		
		public:
		
		WordsList words;
		
		TrieNode () {
			for (int i = 0; i < 8; i++)
				nodes[i] = nullptr;
		}
		
		TrieNode* GetParent() {
			return parent;
		}
		
		TrieNode* GetChild(int i) {
			return nodes [i];
		}
		
		TrieNode* CreateChild (int i) {
			nodes[i] = new TrieNode();
			return nodes[i];
		}
		
		void AddWord (std::string word, int frequency = 0) {
			words.AddWord (WordsList::Word (word, frequency));
		}
		
	};
	
	private:
	TrieNode* root = nullptr;
	
	const std::map<char, int> CharToT9Number = {
		{'a', 0},
		{'b', 0},
		{'c', 0},
		{'d', 1},
		{'e', 1},
		{'f', 1},
		{'g', 2},
		{'h', 2},
		{'i', 2},
		{'j', 3},
		{'k', 3},
		{'l', 3},
		{'m', 4},
		{'n', 4},
		{'o', 4},
		{'p', 5},
		{'r', 5},
		{'s', 5},
		{'t', 6},
		{'u', 6},
		{'w', 7},
		{'y', 8},
		{'z', 8}
	};
	
	public:
	
	Trie () {
		root = new TrieNode ();
	}
	
	void Add (std::string word, int frequency = 0) {
		
		cout << "Dodawanie nowego słowa" << endl;
		
		TrieNode* node = root;
		
		for (int i = 0; i < (int)word.size (); i++) {
			
			int T9_number = CharToT9Number.at (word.at(i));
			
			if (node->GetChild (T9_number) == nullptr) {
				node = node->CreateChild (T9_number);
			} else {
				node = node->GetChild (T9_number);
			}
		}
		
		node->AddWord (word, frequency);
		
		cout << "Dodano nowe słowo" << endl;
	}
	
	TrieNode* Start () {
		return root;
	}
	
	TrieNode* Prev (TrieNode* node) {
		return node->GetParent();
	}
	
	TrieNode* Next (TrieNode* node, int number) {
		return node->GetChild (number - 2);
	}
	
	WordsList::WordNode* GetWords (TrieNode* node) {
		cout << "Pobierz początek listy słów" << endl;
		return node->words.GetFirstWord();
	}
	
};