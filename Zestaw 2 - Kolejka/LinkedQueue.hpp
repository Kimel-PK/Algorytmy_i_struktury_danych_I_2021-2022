template<class T, int N>
class Queue {
	public:
	
	struct Node {
		T wartosc;
		Node* wskaznik;
	};
	
	Queue () {}
	
	~Queue () {
		while (!empty()) {
			pop();
		}
	}
	
	template<class U> // Uniwersalne referencje
	void push(U&& x) { // Wstawia element x do kolejki (takze enqueue)
		
		// stos jest pełny
		if (size() == N) {
			throw std::out_of_range ("Push on full stack");
		}
		
		Node* temp = new Node;
		if (dlugosc > 0)
			ostatni->wskaznik = temp;
		temp->wartosc = x;
		ostatni = temp;
		
		if (dlugosc == 0)
			pierwszy = ostatni;
		
		dlugosc++;
		
	} 
	
	T pop() { // Usuwa element ze stosu i zwraca jego wartość
		
		if (empty()) { // stos jest pusty
			throw std::out_of_range ("Read from empty stack");
		}
		
		T wynik = pierwszy->wartosc;
		Node* temp = pierwszy->wskaznik;
		delete pierwszy;
		pierwszy = temp;
		dlugosc--;
		return wynik;
		
	}
	
	int size() { // Zwraca liczbę elementów na stosie
		return dlugosc;
	}
	
	bool empty() { // Sprawdza czy kolejka jest pusta
		if (dlugosc == 0) {
			return true;
		} else {
			return false;
		}
	}
	
	private:
	Node* pierwszy;
	Node* ostatni;
	int dlugosc = 0;
};