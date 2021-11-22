template<int capacity>
class CursorList {
	
	public:
	
	struct Node {
		int value; // Element przechowywany przez węzeł listy
		int next; // Indeks kolejnego węzła
	};
	
	CursorList () {
		for (int i = capacity; i >= 0; i--) {
			nodes[i].next = i + 1;
		}
		spare = 0;
		head = 0;
		tail = 0;
		_size = 0;
	}
	
	~CursorList () {}
	
	void push_front(int x) { // Dołącza element na początek listy
		if (size() == capacity)
			return;
		
		int temp = head;
		head = spare;
		nodes[head].value = x;
		spare = nodes[spare].next;
		nodes[head].next = temp;
		
		_size++;
	}
	
	int pop_front() { // Usuwa i zwraca element z początku listy
		
		int temp = head;
		head = nodes[head].next;
		nodes[temp].next = spare;
		spare = temp;
		
		_size--;
		return nodes[temp].value;
	}
	
	void push_back(int x) { // Dołącza element na koniec listy
	
		int temp = tail;
		tail = spare;
		nodes[tail].value = x;
		spare = nodes[spare].next;
		nodes[temp].next = tail;
		
		_size++;
	}
	
	int pop_back() { // Usuwa i zwraca element z końca listy
		
		int temp = head;
		for (int i = 0; i < size() - 2; i++) {
			temp = nodes[temp].next;
		}
		
		nodes[tail].next = spare;
		spare = tail;
		tail = temp;
		
		_size--;
		return nodes[spare].value;
	}
	
	int size() { // Zwraca liczbę elementów w liście
		return _size;
	}
	
	bool empty () { // Zwraca true gdy lista jest pusta
		if (size() > 0)
			return false;
		return true;
	}
	
	void clear() { // Czyści listę
		while (size() > 0)
			pop_front();
	}
	
	int find(int x) { // Zwraca pozycję pierwszego elementu o wartości x
		
		int node = head;
		for (int i = 0; i < size(); i++) {
			if (nodes[node].value == x)
				return i;
			node = nodes[node].next;
		}
		
		return -1;
	}
	
	int erase(int i) { // Usuwa i zwraca element na pozycji i
		
		int temp = head;
		
		for (; i > 1; i--) {
			temp = nodes[temp].next;
		}
		
		int spare_old = spare;
		spare = nodes[temp].next;
		nodes[temp].next = nodes[nodes[temp].next].next;
		nodes[spare].next = spare_old;
		
		_size--;
		return nodes[spare].value;
	}
	
	void insert(int i, int x) { // Wstawia element x przed pozycję i
		
		int temp = head;
		
		for (; i > 1; i--) {
			temp = nodes[temp].next;
		}
		
		
		
		_size++;
	}
	
	int remove(int x) { // Usuwa wystąpienia x i zwraca ich liczbę
		
		int count = 0;
		
		int temp = head;
		for (int i = 0; i < size() - 1; i++) {
			
			temp = nodes[temp].next;
			if (nodes[nodes[temp].next].value != x)
				continue;
			
			int spare_old = spare;
			spare = nodes[temp].next;
			nodes[temp].next = nodes[nodes[temp].next].next;
			nodes[spare].next = spare_old;
			
			_size--;
			i--;
			count++;
		}
		
		return count;
	}
	
	bool replace (int x, int y) { // zamienia pierwsze wystąpienie elementu x na element y
		
		int search = find(x);
		if (search != -1) {
			nodes[search].value = y;
			return true;
		}
		
		return false;
	}
	
	void WypiszListe () {
		
		std::cout << "head: " << head << std::endl;
		std::cout << "tail: " << tail << std::endl;
		std::cout << "size: " << _size << std::endl;
		std::cout << "spare: " << spare << std::endl;
		
		int element = head;
		for (int i = 0; i < size(); i++) {
			std::cout << i << " (" << nodes[element].value << ")" << std::endl;
			element = nodes[element].next;
		}
		
		std::cout << "============================" << std::endl;
		
		for (int i = 0; i < size() + 5; i++) {
			std::cout << i << " - (" << nodes[i].value << ") => " << nodes[i].next << std::endl;
		}
		
	}
	
	private:
	
	Node nodes[capacity]; // Tablica węzłów
	
	int head; // Indeks pierwszego węzła
	int tail; // Indeks ostatniego węzła
	int _size; // Rozmiar listy
	int spare; // Indeks pierwszego nieużytego elementu tablicy
};