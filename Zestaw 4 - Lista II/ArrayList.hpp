template<int capacity>
class ArrayList {
	
	public:
	
	void push_front(int x) { // Dołącza element na początek listy
		if (size == capacity)
			return;
			
		rewrite(0);
		array[0] = x;
	}
	
    int pop_front() { // Usuwa i zwraca element z początku listy
		
	}
	
    void push_back(int x) { // Dołącza element na koniec listy
		if (size == capacity)
			return;
		
		array[size] = x;
	}
	
    int pop_back() { // Usuwa i zwraca element z końca listy
		return array[size--];
	}
	
    int size() { // Zwraca liczbę elementów w liście
		return size;
	}
	
    bool empty() { // Zwraca true gdy lista jest pusta
		if (size > 0)
			return false;
		return true;
	}
	
    void clear() { // Czyści listę
		size = 0;
	}
	
    int find(int x) { // Zwraca pozycję pierwszego elementu o wartości x
	}
	
    int erase(int i) { // Usuwa i zwraca element na pozycji i
	}
	
    void insert(int i, int x) { // Wstawia element x przed pozycję i
		rewrite (i);
		array[i] = x;
	}
	
    int remove(int x) { // Usuwa wystąpienia x i zwraca ich liczbę
	}
	
	bool replace (int x, int y) { // zamienia pierwsze wystąpienie elementu x na element y
	}
	
	void rewrite (int hole, int hole_size) {
		
	}
	
	private:
	
	int array[capacity];
	int size; // Rozmiar listy
	
};