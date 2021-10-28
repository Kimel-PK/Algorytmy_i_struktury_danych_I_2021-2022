# Zestaw 2 - Kolejka

## Kolejka

> Kolejka (ang. queue) to nastepna podstawowa struktura danych, która implementuje zbiory dynamiczne. Elementy są usuwane z kolejki w kolejności od najwcześniej dodanego (strategia first-in, first-out - FIFO).

## Interfejs

```cpp
class Queue {
    Queue(); // Konstruktor domyslny
    void push(int x); // Wstawia element x do kolejki (takze enqueue)
    int pop(); // Usuwa element z kolejki i zwraca jego wartosc (dequeue)
    int size(); // Zwraca liczbe elementów w kolejce
    bool empty(); // Sprawdza czy kolejka jest pusta
};
```

### Uwagi

Operacje mają mieć złożoność O(1). Złożoność obliczeniowa programów powinna być optymalna dla danej implementacji.

W przypadku wystapienia błedu niedomiaru lub przepełnienia operacje powinny wyrzucac wyjątek `std::out_of_range`.

Dla prostoty, cała implementacja klasy może znajdować się w jednym pliku nagłówkowym. Taka konstrukcja jest konieczna w przypadku szablonów klas. Pliki źródłowe muszą mieć podaną nazwę, a programy wykonywalne muszą mieć rozszerzenie `.x`.

## Zadanie 1. Implementacja tablicowa kolejki (ArrayQueue.hpp)

Napisać klasę `Queue`, która implementuje kolejkę w oparciu o bufor cykliczny. Dodać konstruktor, który jako argument przyjmuje rozmiar tablicy. Nie używać klasy `std::vector`.

## Zadanie 2. Implementacja wskaźnikowa kolejki (LinkedQueue.hpp)

Napisać implementację wskaźnikową kolejki.

## Zadanie 3. Kolejka (Queue.cpp)

Program `Queue.x` ma wczytać ze standardowego wejścia dane wg poniższego formatu wygenerowane przez program opisany w zadaniu Generator z Zestawu 1. Wynik działania odpowiednich operacji na kolejce wypisać na standardowe wyjście. Kolejka przechowuje elementy typu int.

### Format danych

W pierwszej linii podana jest liczba n ≤ 10⁶ wskazujaca na liczbe operacji do
wykonania oraz n linii polecen. Operacje moga byc nastepujacego typu:

- A x - wstaw do kolejki liczbe 0 ≤ x ≤ 10⁶
- D - pobierz element z kolejki i go wypisz, jeśli kolejka jest pusta wypisz "EMPTY"
- S - wypisz liczbe elementów w kolejce

> Uwaga: Programy muszą wczytywać dane wejściowe ze standardowego wejścia i wypisać rezultat na standardowe wyjście.

## Zadanie 4. Sortowanie pozycyjne (Radix.cpp)

Zaimplementuj algorytm sortowania pozycyjnego przy użyciu (tablicy) dziesieciu kolejek. Należy użyć własnej implementacji kolejki. Napisać funkcję `void radix(std::vector<int>& v)`, która sortuje wektor v. Założyć, że liczby sa nieujemne i mniejsze od 10⁹. Funkcja `main` wczytuje dane do wektora `std::vector<int>`, wywołuje funkcje radix i wypisuje elementy posortowanego wektora przy użyciu pętli `for-each`:

```cpp
for(const auto& i : v)
    std::cout << i << std::endl;
```

## Pytania

- Opisz trzy sposoby obsługi cyklicznosci bufora.
- Omów przykłady zastosowania kolejki.
- Co oznaczaja akronimy LIFO i FIFO?

## Dodatkowe punkty

Dodatkowe punkty (po 1 pkt) można zdobyć za:

- Napisanie szablonu klas
- Wykorzystanie referencji do r-wartości, semantyki przenoszenia, uniwersalnych referencji, doskonałego przekazywania.
- Napisanie testera
