# Zestaw 2 - Kolejka

## Kolejka

> Kolejka (ang. queue) to nastepna podstawowa struktura danych, która implementuje zbiory dynamiczne. Elementy sa usuwane z kolejki w kolejnosci od najwczesniej dodanego (strategia first-in, first-out - FIFO).

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

Operacje maja miec złozonosc O(1). Złozonosc obliczeniowa programów powinna byc optymalna dla danej implementacji.

W przypadku wystapienia błedu niedomiaru lub przepełnienia operacje powinny wyrzucac wyjatek `std::out_of_range`.

Dla prostoty, cała implementacja klasy moze znajdowac sie w jednym pliku nagłówkowym. Taka konstrukcja jest konieczna w przypadku szablonów klas. Pliki zródłowe musza miec podana nazwe, a programy wykonywalne musza miec rozszerzenie .x.

## Zadanie 1. Implementacja tablicowa kolejki (ArrayQueue.hpp)

Napisac klase Queue, która implementuje kolejke w oparciu o bufor cykliczny. Dodac konstruktor, który jako argument przyjmuje rozmiar tablicy. Nie uzywac klasy `std::vector`.

## Zadanie 2. Implementacja wskaznikowa kolejki (LinkedQueue.hpp)

Napisac implementacje wskaznikowa kolejki.

## Zadanie 3. Kolejka (Queue.cpp)

Program Queue.x ma wczytac ze standardowego wejscia dane wg ponizszego formatu wygenerowane przez program opisany w zadaniu Generator z Zestawu 1. Wynik działania odpowiednich operacji na kolejce wypisac na standardowe wyjscie. Kolejka przechowuje elementy typu int.

### Format danych

W pierwszej linii podana jest liczba n  106 wskazujaca na liczbe operacji do
wykonania oraz n linii polecen. Operacje moga byc nastepujacego typu:

- A x - wstaw do kolejki liczbe 0  x  106
- D - pobierz element z kolejki i go wypisz, jesli kolejka jest pusta wypisz “EMPTY”
- S - wypisz liczbe elementów w kolejce

> Uwaga: Programy musza wczytywac dane wejsciowe ze standardowego wejscia i wypisac rezultat na standardowe wyjscie.

## Zadanie 4. Sortowanie pozycyjne (Radix.cpp)

Zaimplementuj algorytm sortowania pozycyjnego przy uzyciu (tablicy) dziesieciu kolejek. Nalezy uzyc własnej implementacji kolejki. Napisac funkcje void radix(std::vector<int>& v), która sortuje wektor v. Załozyc, ze liczby sa nieujemne i mniejsze od 109. Funkcja main wczytuje dane do wektora std::vector<int> (patrz wskazówki w Materiałach), wywołuje funkcje radix i wypisuje elementy posortowanego wektora przy uzyciu petli for-each:

```cpp
for(const auto& i : v)
	std::cout << i << std::endl;
```

## Pytania

- Opisz trzy sposoby obsługi cyklicznosci bufora.
- Omów przykłady zastosowania kolejki?
- Co oznaczaja akronimy LIFO i FIFO?

## Dodatkowe punkty

Dodatkowe punkty (po 1 pkt) mozna zdobyc za:

- Napisanie szablonu klas
- Wykorzystanie referencji do r-wartosci, semantyki przenoszenia, uniwersalnych referencji, doskonałego przekazywanie.
- Napisanie testera