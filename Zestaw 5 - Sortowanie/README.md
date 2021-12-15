# Zestaw 5 - Sortowanie

## Zadanie 1. Implementacja prostych algorytmów sortowania

Zaimplementować poniższe proste algorytmy sortowania:

- Sortowanie bąbelkowe (`BubbleSort.cpp`, ang. bubble sort)
- Sortowanie przez wybieranie (`SelectionSort.cpp`, ang. selection sort)
- Sortowanie przez wstawianie (`InsertionSort.cpp`, ang. insertion sort)

Napisać szablon funkcji sortujący wektor v

```cpp
template <class T> void sort(std::vector<T>& v);
```

Funkcja main wczytuje dane wejściowe ze standardowego wejścia do wektora typu int (`std::vector<int>`), sortuje elementy wektora wywołując funkcję `sort<int>()` i wypisuje elementy posortowanego wektora na standardowe wyjście przy użyciu pętli `for-each`:

```cpp
for(const auto& i : v)
    std::cout << i << std::endl;
```

Na wejściu, w każdej linii znajduje się jedna liczba w postaci tekstowej. Na wyjściu, należy wypisać wczytane wartości w niemalejącej kolejności, po jednej liczbie w każdej linii. Proszę zapoznać się z dokumentem Wskazówki i elementy języka C++ (wczytywanie danych, poprawa wydajności, pomiar czasu wykonania).

### Czas sortowania

Zmierzyć czas działania wszystkich powyższych implementacji dla różnych rozmiarów danych wejściowych (mierzony czas powinien obejmować zakres od kilku sekund do kilku minut) i porównać wyniki.

Wyniki należy przedstawić na wykresie (w formie grafcznej, np. używając programów gnuplot, gnumeric, LibreOffice), wykres powinien przedstawiać czas sortowania w funkcji rozmiaru danych. Dopasować zależność teoretyczną czasu wykonania.

## Zadanie 2. Złożoność obliczeniowa

Zmodyfikować jedną wybraną implementację i dodać instrukcje zliczające dominujące operacje. Obliczyć złożoność obliczeniową pesymistyczną, średnią i optymistyczną oraz miarę wrażliwości pesymistycznej. Sprawdzić dla losowych danych i tablicy posortowanej, czy liczba wykonanych operacji dominujących zgadza się oszacowaniami.

## Zadanie 3. Generator (`Generator.cpp`)

Proszę napisać program, który przyjmuje dwa argumenty z linii komend - odpowiednio n i max - i wypisuje n (pseudo)losowych liczb z zakresu od 1 do max włącznie na standardowe wyjście.

### Przykład

```bash
./generator.x 10000 100000 > input_10k.txt
```

## Zadania dodatkowe

### A1 - Sortowanie przez zliczanie (`CountingSort.cpp`)

Zaimplementować sortowanie przez zliczanie (ang. counting sort). Założyć, że liczby są nieujemne i
mniejsze od 10⁶.

### A2

Zmodyfikować implementację algorytmu sortowania przez wybieranie tak, aby jednocześnie wybierać
minimum i maksimum (`SelectionMinmax.cpp`).

### A3

Zamiast szablonu funkcji postaci `template <class T> void sort(std::vector<T>& v)`, zaimplementować szablon funkcji z identycznym interfejsem jak funkcja biblioteczna `std::sort`,

```cpp
template <typename RandomAccessIterator>
void sort(RandomAccessIterator begin, RandomAccessIterator end);
```
