#include "LinkedList.hpp"

#define BUCKETS 100
#define LIST_SIZE 1000000

template <class K, class V>
class Dict {
	using Pair = std::pair<K, V>;
	
	private:
	
	int _size = 0;
	List<Pair, LIST_SIZE> dictionary[BUCKETS];
	Pair def;
	
	unsigned int Hash (std::string key) {
		
		unsigned int hash = 7;
		for (int i = 0; i < (int)key.size(); i++) {
			hash = hash * 31 + key.at(i);
		}
		
		return hash % BUCKETS;
	}
	
	public:
	
	Dict () { // Konstruktor
		
	}
	
	void clear () { // Czyści słownik
		for (int i = 0; i < BUCKETS; i++) {
			dictionary[i].Clear();
		}
	}
	
	bool insert (const Pair& p) { // Dodaje parę klucz-wartość do słownika
		
		int hash = Hash(p.first);
		
		if (!find (p.first)) {
			
			dictionary[hash].push_back(p);
			
			_size++;
			return true;
		}
		
		for (typename List<Pair, LIST_SIZE>::Iterator i = dictionary[hash].begin(); i != dictionary[hash].end(); i++) {
			if (p.first == i->value.first) {
				i->value.second = p.second;
				return false;
			}
		}
		
		return false;
	}
	
	bool find (const K& k) { // Sprawdza czy słownik zawiera klucz
		
		int hash = Hash(k);
		
		for (typename List<Pair, LIST_SIZE>::Iterator i = dictionary[hash].begin(); i != dictionary[hash].end(); i++) {
			if (k == i->value.first)
				return true;
		}
		
		return false;
	}
	
	V& operator[] (const K& k) { // Zwraca wartość dla klucza
		
		int hash = Hash(k);
		
		for (typename List<Pair, LIST_SIZE>::Iterator i = dictionary[hash].begin(); i != dictionary[hash].end(); i++) {
			if (k == i->value.first)
				return i->value.second;
		}
		
		def.first = k;
		insert (def);
		
		return def.second;
	}
	
	bool erase (const K& k) { // Usuwa parę o danym kluczu
		
		int hash = Hash(k);
		
		for (typename List<Pair, LIST_SIZE>::Iterator i = dictionary[hash].begin(), n = 0; i != dictionary[hash].end(); i++, n++) {
			if (k == i->value.first) {
				dictionary[hash].erase (n);
				_size--;
				return true;
			}
		}
		
		return false;
	}
	
	int size () { // Zwraca liczbę par
		return _size;
	}
	
	bool empty () { // Sprawdza czy słownik jest pusty
		if (_size == 0)
			return true;
		else
			return false;
	}
	
	void buckets () { // Wypisuje informację o słowniku
		int shortest = LIST_SIZE;
		int longest = 0;
		
		for (int i = 0; i < BUCKETS; i++) {
			if (dictionary[i].size() > longest) {
				longest = dictionary[i].size();
			}
			if (dictionary[i].size() < shortest) {
				shortest = dictionary[i].size();
			}
		}
		
		std::cout << "# " << _size << " " << BUCKETS << " " << shortest << " " << longest << std::endl;
	}
	
};