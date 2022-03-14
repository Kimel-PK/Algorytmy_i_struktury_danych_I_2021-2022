template<class T, int N>
class Stack {
	public:
	
	struct Node {
		T wartosc;
		Node* wskaznik;
	};
	
	Stack () {}
	
	~Stack () {
		while (!empty()) {
			pop();
		}
	}
	
	template<class U> // Uniwersalne referencje
	void push(U&& x) { // Wstawia element x na stos
		
		// stos jest pełny
		if (size() == N) {
			throw std::out_of_range ("Push on full stack");
		}
		
		Node* temp = new Node;
		temp->wartosc = x;
		temp->wskaznik = stos;
		stos = temp;
		dlugosc++;
		
	} 
	
	T pop() { // Usuwa element ze stosu i zwraca jego wartość
		
		if (empty()) { // stos jest pusty
			throw std::out_of_range ("Read from empty stack");
		}
		
		T wynik = stos->wartosc; // !! kopiowanie elementu a nie przypisanie wartości
		Node* poprzedni = stos->wskaznik;
		delete stos;
		stos = poprzedni;
		dlugosc--;
		return wynik;
	}
	
	T& top() { // Zwraca referencję do najmłodszego elementu
		return &stos->wartosc;
	}
	
	int size() { // Zwraca liczbę elementów na stosie
		return dlugosc;
	}
	
	bool empty() { // Sprawdza czy stos jest pusty
		if (dlugosc == 0) {
			return true;
		} else {
			return false;
		}
	}
	
	private:
	Node* stos;
	int dlugosc = 0;
};