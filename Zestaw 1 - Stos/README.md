# Zestaw 1 - Stos

## Stos

> Stos (ang. stack) to podstawowa struktura danych (abstrakcyjny typ danych), która implementuje zbiory dynamiczne. Elementy sa usuwane ze stosu w kolejnosci od najpóźniej dodanego (strategia last-in, first-out - LIFO).

### Interfejs

```cpp
class Stack {
    Stack(int capacity); // Konstruktor. Argumentem jest rozmiar tablicy.
    void push(int x); // Wstawia element na stos
    int pop(); // Usuwa element ze stosu i zwraca jego wartosc
    int size(); // Zwraca liczbe elementów na stosie
    bool empty(); // Sprawdza czy stos jest pusty
};
```

Operacje mają mieć złożoność O(1). Złożoność obliczeniowa programów powinna być optymalna dla danej implementacji.

W przypadku wystapienia błędu niedomiaru lub przepełnienia operacje powinny wyrzucać wyjatek `std::out_of_range`.

### Uwagi

Pliki źródłowe muszą mieć podaną nazwę, a programy wykonywalne muszą mieć rozszerzenie .x.

## Implementacja tablicowa stosu (ArrayStack.hpp)

Napisać implementację tablicową stosu zgodnie z podanym interfejsem. Proszę nie używać klasy `std::vector`.

## Implementacja wskaźnikowa stosu (LinkedStack.hpp)

Napisać implementację wskaźnikową stosu zgodnie z podanym interfejsem.

## Stos (Stack.cpp)

Program `Stack.x` ma wczytać ze standardowego wejścia dane wg poniższego formatu wygenerowane przez program opisany w zadaniu Generator. Wynik działania odpowiednich operacji na stosie wypisać na standardowe wyjście. Stos przechowuje elementy typu int. Założyć, że na stosie moze sie naraz znajdowac maksymalnie 10⁶ elementów. Program musi przechodzic testy.

### Format danych:

W pierwszej linii podana jest liczba n ≤ 10⁶ wskazująca na liczbę operacji do wykonania oraz n linii poleceń. Operacje mogą być następujacego typu:
- A x - połóż na stos lub wstaw do kolejki liczbe 0 ≤ x ≤ 10⁶
- D - zdejmij/pobierz element z stosu/kolejki i go wypisz, jesśli stos/kolejka jest pusta wypisz "EMPTY"
- S - wypisz liczbę elementów na stosie lub w kolejce

> Uwaga: Programy muszą wczytywać dane wejściowe ze standardowego wejścia i wypisać rezultat na standardowe wyjście.

## Generator (Generator.cpp)
Napisać program `Generator.x`, który generuje dane wejściowe dla programu `Stack.x`. Dane powinny być generowane losowo (inne przy każdym uruchomieniu) i muszą być zgodne z powyższym formatem.

## Odwrotna notacja polska (ONP.cpp)

Napisz program, który za pomoca stosu zamienia wyrażenie arytmetyczne w zapisie klasycznym na odwrotną notacje polską.

- W wyrażeniu wystepują jedynie nawiasy okragłe ( ), operatory binarne + - * / i dodatnie liczby całkowite. Każdy z w.w. elementów jest oddzielony spacja.
- Każde wyrażenie ma składnie nawias_otwierajacy lewy_argument operator prawy_argument nawias_zamykajacy. Każda z operacji wraz z argumentami objęta jest nawiasem, w związku z czym można pominąć kolejność wykonywania działań.

Przykładowe dane wejściowe i wyjściowe:
```text
( 11 + ( ( ( ( 1 + 2 ) * ( 4 - 3 ) ) + ( 4 / 2 ) ) * ( 8 - 6 ) ) )

11 1 2 + 4 3 - * 4 2 / + 8 6 - * +
```

## Pytania

- Omów przykłady zastosowania stosu?
- Dlaczego operacja pop() z std::stack nie zwraca wartości elementu?
- Dlaczego operacja pop() z std::stack nie zwraca referencji do elementu?

## Dodatkowe punkty

Dodatkowe punkty (po 1 pkt) można zdobyć za:

- Napisanie szablonu klas
- Wykorzystanie referencji do r-wartości, semantyki przenoszenia, uniwersalnych referencji, doskonałego przekazywania.
- Napisanie testera

Napisać szablon klas wg poniższego schematu, który implementuje stos przechowujacy obiekty typu T w oparciu o tablice o rozmiarze N.

```cpp
template<class T, int N>
class Stack {
    template<class U> // Uniwersalne referencje
    void push(U&& x); // Wstawia element x na stos
    T pop(); // Usuwa element ze stosu i zwraca jego wartosc
    T& top(); // Zwraca referencje do najmłodszego elementu
    int size(); // Zwraca liczbe elementów na stosie
    bool empty(); // Sprawdza czy stos jest pusty
};
```
