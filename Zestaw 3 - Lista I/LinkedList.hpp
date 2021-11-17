template<class T, int capacity>
class List {
	
	public:
	
	struct Node {
		T value;
		Node* next;
		Node* prev;
	};
	
	List () {
		guard = new Node();
		guard->next = guard;
		guard->prev = guard;
		_size = 0;
	}
	
	~List () {
		while (!empty())
			pop_front();
		delete guard;
	}
	
	void push_front (T x) { // Dołącza element na początek listy
	
		Node* temp = new Node();
		temp->value = x;
		
		temp->next = guard->next;
		temp->prev = guard->next;
		guard->next->prev = temp;
		guard->next = temp;
		_size++;
		
	}
	
	T pop_front () { // Usuwa i zwraca element z początku listy
		
		T x = guard->next->value;
		Node* temp = guard->next;
		guard->next = temp->next;
		temp->next->prev = guard;
		
		_size--;
		delete temp;
		
		return x;
		
	}
	
	void push_back(T x) { // Dołącza element na koniec listy
		
		Node* temp = new Node();
		temp->value = x;
		
		temp->prev = guard->prev;
		temp->next = guard->next;
		guard->prev->next = temp;
		guard->prev = temp;
		_size++;
		
	}
	
	T pop_back() { // Usuwa i zwraca element z końca listy
		
		T x = guard->prev->value;
		Node* temp = guard->prev;
		guard->prev = temp->prev;
		temp->prev->next = guard;
		
		_size--;
		delete temp;
		
		return x;
		
	}
	
	int size() { // Zwraca liczbę elementów w liście
		return _size;
	}
	
	bool empty () { // Zwraca true gdy lista jest pusta
		if (_size == 0)
			return true;
		else
			return false;
	}
	
	void clear() { // Czyści listę
		while (guard->next != guard->prev) {
			pop_front();
		}
	}
	
	int find(T x) { // Zwraca pozycję pierwszego elementu o wartości x
		
		Node* search = guard->next;
		
		for (int i = 0; i < size(); i++) {
			if (search->value == x) {
				return i;
			}
			search = search->next;
		}
		
		return -1;
		
	}
	
	int erase(int i) { // Usuwa i zwraca element na pozycji i
		
		Node* temp = guard->next;
		
		for (; i > 0; i--) {
			temp = temp->next;
		}
		
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		
		T x = temp->value;
		
		_size--;
		delete temp;
		return x;
		
	}
	
	void insert(int i, T x) { // Wstawia element x przed pozycję i
		
		Node* temp = new Node();
		temp->value = x;
		
		Node* insert = guard;
		for (int n = 0; n < i; n++) {
			insert = insert->next;
		}
		
		temp->next = insert->next;
		temp->prev = insert->next;
		insert->next->prev = temp;
		insert->next = temp;
		_size++;
		
	}
	
	int remove(T x) { // Usuwa wystąpienia x i zwraca ich liczbę
		
		int count = 0;
		int i = -1;
		
		while ((i = find (x)) != -1) {
			erase(i);
			count++;
		}
		
		return count;
		
	}
	
	bool replace(T x, T y) {
		
		int i = find (x);
		if (i == -1)
			return false;
		erase (i);
		insert (i, y);
		
		return true;
	}
	
	void WypiszListe () {
		std::cout << "Wypisz liste" << std::endl;
		std::cout << "Rozmiar: " << _size << std::endl;
		Node* temp = guard->next;
		for (int i = 0; i < _size; i++) {
			std::cout << temp->value << std::endl;
			temp = temp->next;
		}
	}
	
	private:
	
	Node* guard;
	int _size;
	
};