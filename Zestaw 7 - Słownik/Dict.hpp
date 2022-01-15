template <class K, class V>
class Dict {
	using Pair = std::pair<K, V>;
	
	private:
	
	int _size = 0;
	
	public:
	
	Dict () { // Konstruktor
		
	}
	
	void clear () { // Czyści słownik
		
	}
	
	bool insert (const Pair& p) { // Dodaje parę klucz-wartość do słownika
		
		return false;
	}
	
	bool find (const K& k) { // Sprawdza czy słownik zawiera klucz
		
		return false;
	}
	
	V& operator[] (const K& k) { // Zwraca wartość dla klucza
		
		return nullptr;
	}
	
	bool erase (const K& k) { // Usuwa parę od danym kluczu
		
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
	
	void buckets () { // Wypisuje informację o słowniku (patrz poniżej)
		
	}
	
};