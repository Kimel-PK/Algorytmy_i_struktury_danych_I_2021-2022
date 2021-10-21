template<class T, int N>
class Stack {
    public:
    
    Stack () {
		stos = new T[N];
    }
    
    ~Stack () {
        delete [] stos;
    }
    
    template<class U> // Uniwersalne referencje
    void push(U&& x) { // Wstawia element x na stos
        if (dlugosc == N) {
            throw std::out_of_range ("Push on full stack");
        }
        stos[dlugosc++] = x;
    }
    
    T pop() { // Usuwa element ze stosu i zwraca jego wartość
        if (empty()) { // stos jest pusty
            throw std::out_of_range ("Read from empty stack");
        }
        return stos[--dlugosc];
    }
    
    T& top() { // Zwraca referencję do najmłodszego elementu
		if (empty()) {
            throw std::out_of_range ("Read from empty stack");
        }
        return stos[dlugosc - 1];
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
    T* stos;
    int dlugosc = 0;
};