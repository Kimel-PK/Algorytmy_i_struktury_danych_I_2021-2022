#include <stdexcept>

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
    void push(U&& x) {
        if (dlugosc == N) {
            throw std::out_of_range ("Push on full stack");
        }
        stos[dlugosc++] = x;
    }
    
    T pop() {
        if (empty()) { // stos jest pusty
            throw std::out_of_range ("Read from empty stack");
        }
        return stos[--dlugosc];
    }
    
    T& top() {
		if (empty()) {
            throw std::out_of_range ("Read from empty stack");
        }
        return stos[dlugosc - 1];
    }
    
    int size() {
        return dlugosc;
    }
    
    bool empty() {
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