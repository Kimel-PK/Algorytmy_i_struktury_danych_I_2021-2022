template<class T, int N>
class Stack {
    public:
    
    template<class U>
    struct Node {
        U wartosc;
        Node* wskaznik;
    };
    
    Stack () {
		stos = new T[N];
    }
    
    template<class U> // Uniwersalne referencje
    void push(U&& x) { // Wstawia element x na stos
        
        // stos jest pełny
        if (size() == N)
            return;
        
        stos[dlugosc++] = x;
        
    } 
    
    T pop() { // Usuwa element ze stosu i zwraca jego wartość
        
        // !! stos jest pusty
        if (empty())
            return;
            
        T wynik = top()->wartosc; // !! kopiowanie elementu a nie przypisanie wartości
        delete top;
        return wynik;
    }
    
    T& top() { // Zwraca referencję do najmłodszego elementu
        return &stos[dlugosc];
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
    int dlugosc;
};