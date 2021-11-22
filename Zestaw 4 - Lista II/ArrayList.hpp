template<int capacity>
class ArrayList {
	
	public:
	
	ArrayList () {
		_size = 0;
	}
	
	void push_front(int x) { // Dołącza element na początek listy
		if (size() == capacity)
			throw std::out_of_range("Add to full list");
		
		rewrite(0, 1);
		array[0] = x;
	}
	
    int pop_front() { // Usuwa i zwraca element z początku listy
		if (empty())
			throw std::out_of_range("Pop from empty list");
		
		int result = array[0];
		
		rewrite (0, -1);
		return result;
	}
	
    void push_back(int x) { // Dołącza element na koniec listy
		if (size() == capacity)
			throw std::out_of_range("Add to full list");
		
		array[_size++] = x;
	}
	
    int pop_back() { // Usuwa i zwraca element z końca listy
		if (empty())
			throw std::out_of_range("Pop from empty list");
		
		return array[--_size];
	}
	
    int size() { // Zwraca liczbę elementów w liście
		return _size;
	}
	
    bool empty() { // Zwraca true gdy lista jest pusta
		if (size() > 0)
			return false;
		return true;
	}
	
    void clear() { // Czyści listę
		_size = 0;
	}
	
    int find(int x) { // Zwraca pozycję pierwszego elementu o wartości x
		
		for (int i = 0; i < size(); i++)
			if (array[i] == x)
				return i;
		
		return -1;
	}
	
    int erase(int i) { // Usuwa i zwraca element na pozycji i
		
		if (empty())
			throw std::out_of_range("Erase from empty list");
		
		int result = array[i];
		rewrite(i, -1);
		
		return result;
	}
	
    void insert(int i, int x) { // Wstawia element x przed pozycję i
		
		if (size() + 1 >= capacity)
			throw std::out_of_range("Insert to full list");
		
		rewrite (i, 1);
		array[i] = x;
	}
	
    int remove(int x) { // Usuwa wystąpienia x i zwraca ich liczbę
		
		int count = 0;
		
		for (int i = 0; i < size(); i++) {
			
			if (count != 0) {
				array[i - count] = array[i];
			}
			
			if (array[i] == x) {
				count++;
			}
			
		}
		
		_size = _size - count;
		
		return count;
	}
	
	bool replace (int x, int y) { // zamienia pierwsze wystąpienie elementu x na element y
		
		int search = find (x);
		
		if (search != -1) {
			array[search] = y;
			return true;
		}
		
		return false;
	}
	
	private:
	
	void rewrite (int hole, int hole_size) { // przepisuje tablicę wstawiając do środka dziurę lub usuwającą dany element
		
		if (size() + hole_size > capacity)
			throw std::out_of_range("Out of array bounds while rewriting list");
		
		if (hole_size > 0) {
			for (int i = size() - 1 + hole_size; i > hole; i--) {
				array[i] = array[i - hole_size];
			}
		} else {
			for (int i = hole; i < size() + hole_size; i++) {
				array[i] = array[i - hole_size];
			}
		}
		
		_size += hole_size;
		
	}
	
	int array[capacity];
	int _size; // ilość elementów w liście
	
};