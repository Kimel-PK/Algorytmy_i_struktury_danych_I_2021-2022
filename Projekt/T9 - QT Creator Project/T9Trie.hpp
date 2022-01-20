#include <map>
#include "WordsList.hpp"

class T9Trie {
	
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

        ~TrieNode () {
            delete nodes;
        }
		
		TrieNode* GetParent() {
			return parent;
		}
		
		TrieNode* GetChild(int i) {
			return nodes [i];
		}
		
		TrieNode* CreateChild (int i) {
			nodes[i] = new TrieNode();
            nodes[i]->parent = this;
			return nodes[i];
		}
		
		void AddWord (std::string word, int frequency = 0) {
			words.AddWord (WordsList::Word (word, frequency));
		}
		
	};
	
	private:
	TrieNode* root = nullptr;
    TrieNode* current_node = root;
    WordsList::WordNode* current_word;

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
        {'q', 5},
		{'r', 5},
		{'s', 5},
		{'t', 6},
		{'u', 6},
        {'v', 6},
		{'w', 7},
        {'x', 7},
        {'y', 7},
        {'z', 7}
	};
	
	public:
	
    T9Trie () {
		root = new TrieNode ();
	}

    private:
    void T9TrieDestructor (TrieNode* node) {
        if (node != nullptr) {
            T9TrieDestructor (node->GetChild(0));
            T9TrieDestructor (node->GetChild(1));
            T9TrieDestructor (node->GetChild(2));
            T9TrieDestructor (node->GetChild(3));
            T9TrieDestructor (node->GetChild(4));
            T9TrieDestructor (node->GetChild(5));
            T9TrieDestructor (node->GetChild(6));
            T9TrieDestructor (node->GetChild(7));
            delete node;
        }
    }

    public:
    ~T9Trie () {
        T9TrieDestructor (root);
    }
	
	void Add (std::string word, int frequency = 0) {

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
	}
	
    void Reset () {
        current_node = root;
        current_word = root->words.GetFirstWord();
	}
	
    void Prev () {
        if (current_node != root) {
            current_node = current_node->GetParent();
            if (current_node->words.Size() > 0 || current_node == root) {
                current_word = current_node->words.GetFirstWord();
            }
        }
	}
	
    void Next (int number) {
        if (current_node->GetChild (number) != nullptr) {
            current_node = current_node->GetChild (number);
            if (current_node->words.Size() > 0) {
                current_word = current_node->words.GetFirstWord();
            }
        }
        current_node->words.ShowList();
	}
	
    std::string GetWord () {
        return current_word->value.word;
    }

    void NextWord () {
        if (current_word->next->value.word == "")
            current_word = current_word->next;
        current_word = current_word->next;
    }

    void Find (std::string word) {
        Reset();
        for (int i = 0; i < (int)word.size(); i++) {
            Next (CharToT9Number.at(word.at(i)));
        }
        while (GetWord() != word) {
            NextWord();
        }
    }
	
};
