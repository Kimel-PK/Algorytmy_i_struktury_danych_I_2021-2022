template<class T, int N>
class List {
	
	public:
	
	struct Node {
		T value;
		Node* next;
	};
	
	List (int N) {
		capacity = N;
	}
	
	void push_front (T x) { // Dołącza element na początek listy
		T temp;
		temp->value = forward::x;
		temp->next = head;
		head = temp;
	}
	
	T pop_front (T x) { // Usuwa i zwraca element z początku listy
		
	}
	
	void push_back(T x) { // Dołącza element na koniec listy
		
	}
	
	T pop_back() { // Usuwa i zwraca element z końca listy
	
	}
	
	int size() { // Zwraca liczbę elementów w liście
		return size;
	}
	
	bool empty () { // Zwraca true gdy lista jest pusta
		if (size == 0)
			return true;
		else
			return false;
	}
	
	void clear() { // Czyści listę
		while (pierwszy.next != nullptr) {
			pop_front();
		}
		
	}
	
	int find(T x) { // Zwraca pozycję pierwszego elementu o wartości x
		
		// zacznij od pierwszego
		// idź do przodu aż znajdziesz element
		// jeśli koniec listy zwróć nie wiem co
		
	}
	
	int erase(int i) { // Usuwa i zwraca element na pozycji i
		
		// usuń element na pozycji
		// następny musi wskazywać na poprzedni
		// poprzedni musi wskazywać na następny
		
	}
	
	void insert(int i, T x) { // Wstawia element x przed pozycję i
		
		
		
	}
	
	int remove(T x) { // Usuwa wystąpienia x i zwraca ich liczbę
		
	}
	
	private:
	
	Node* head;
	Node guard;
	Node* tail;
	int size;
	int capacity;
	
};