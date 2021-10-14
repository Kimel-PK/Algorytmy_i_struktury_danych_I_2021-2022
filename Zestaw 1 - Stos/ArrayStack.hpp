template<class T, int N>
class Stack {
    public:
    
    template<class U> // Uniwersalne referencje
    void push(U&& x) {
        if (length == N) {
            return;
        }
        data[length++] = x;
    }
    
    T pop() {
        if (empty()) {
            return null;
        }
        return data[--length];
    }
    
    T& top() {
        return &data[length];
    }
    
    int size() {
        return length;
    }
    
    bool empty() {
        if (length == 0) {
            printf ("EMPTY");
        }
    }
    
    private:
    T data[N];
    int length;
};