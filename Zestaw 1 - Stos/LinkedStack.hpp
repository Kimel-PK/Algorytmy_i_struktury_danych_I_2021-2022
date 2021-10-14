template<class T, int N>
class Stack {
    public:
    
    template<class T>
    struct Costam {
        T value;
        Costam* wskaznik;
    }
    
    template<class U> // Uniwersalne referencje
    void push(U&& x) { // Wstawia element x na stos
        
        if (size() == N)
            return;
        
        stos[length++] = x;
        
    } 
    
    T pop() { // Usuwa element ze stosu i zwraca jego wartość
        
    }
    
    T& top() { // Zwraca referencję do najmłodszego elementu
        return data[length];
    }
    
    int size() { // Zwraca liczbę elementów na stosie
        return length;
    }
    
    bool empty() { // Sprawdza czy stos jest pusty
        if (length == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    private:
    T data[N];
    int length;
};