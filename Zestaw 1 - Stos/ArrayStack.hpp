#include <stdexcept>

template<class T, int N>
class Stack {
    public:
    
    template<class U> // Uniwersalne referencje
    void push(U&& x) {
        if (dlugosc == N) {
            return;
        }
        stos[dlugosc++] = x;
    }
    
    T pop() {
        if (empty()) {
            throw std::out_of_range ("Read from empty stack");
        }
        return stos[--dlugosc];
    }
    
    T& top() {
        return &stos[dlugosc];
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
    T stos[N];
    int dlugosc;
};