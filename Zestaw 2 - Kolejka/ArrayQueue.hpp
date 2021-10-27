template<class T, int N>
class Queue {
	
	public:
	
	Queue() { // Konstruktor domyslny
		kolejka = new T[N];
	}
	
	~Queue () {
		delete [] kolejka;
	}
	
	template<class U> // Uniwersalne referencje
	void push(U&& x) { // Wstawia element x do kolejki (takze enqueue)
		if (dlugosc == N) {
			throw std::out_of_range ("Push on full queue");
		}
		kolejka[buforKoncowy] = x;
		buforKoncowy++;
		buforKoncowy %= N;
		dlugosc++;
	}
	
	T pop() { // Usuwa element z kolejki i zwraca jego wartosc (dequeue)
		if (empty()) { // stos jest pusty
			throw std::out_of_range ("Read from empty queue");
		}
		buforPoczatkowy++;
		buforPoczatkowy %= N;
		dlugosc--;
		return kolejka[buforPoczatkowy];
	}
	
	int size() { // Zwraca liczbe elementów w kolejce
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
	T* kolejka;
	int dlugosc = 0;
	int buforPoczatkowy = -1;
	int buforKoncowy = 0;
};