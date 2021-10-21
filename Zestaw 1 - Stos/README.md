# Zestaw 1 - Stos

## Stos

> Stos (ang. stack) to podstawowa struktura danych (abstrakcyjny typ danych), która implementuje zbiory dynamiczne. Elementy sa usuwane ze stosu w kolejnosci od najpózniej dodanego (strategia last-in, first-out - LIFO).

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

Operacje maja miec złozonosc O(1). Złozonosc obliczeniowa programów powinna byc optymalna dla danej implementacji.

Wprzypadku wystapienia błędu niedomiaru lub przepełnienia operacje powinny wyrzucac wyjatek `std::out_of_range`.

### Uwagi

Pliki źródłowe muszą mieć podaną nazwę, a programy wykonywalne musza mieć rozszerzenie .x.

## Implementacja tablicowa stosu (ArrayStack.hpp)

Napisac implementację tablicowa stosu zgodnie z podanym interfejsem. Prosze nie uzywac klasy `std::vector`.

## Implementacja wskaznikowa stosu (LinkedStack.hpp)

Napisać implementację wskaznikowa stosu zgodnie z podanym interfejsem.

## Stos (Stack.cpp)

Program Stack.x ma wczytac ze standardowego wejscia dane wg ponizszego formatu wygenerowane przez program opisany w zadaniu Generator. Wynik działania odpowiednich operacji na stosie wypisac na standardowe wyjscie. Stos przechowuje elementy typu int. Załozyc, ze na stosie moze sie naraz znajdowac maksymalnie 10⁶ elementów. Program musi przechodzic testy.

### Format danych:

W pierwszej linii podana jest liczba n  10⁶ wskazujaca na liczbe operacji do
wykonania oraz n linii polecen. Operacje moga byc nastepujacego typu:
- A x - połóz na stos lub wstaw do kolejki liczbe 0  x  10⁶
- D - zdejmij/pobierz element z stosu/kolejki i gowypisz, jesli stos/kolejka jest pustawypisz “EMPTY”
- S - wypisz liczbe elementów na stosie lub w kolejce

> Uwaga: Programy musza wczytywac dane wejsciowe ze standardowego wejscia i wypisac rezultat na standardowe wyjscie.

## Generator (Generator.cpp)
Napisac program Generator.x, który generuje dane wejsciowe dla programu Stack.x. Dane powinny byc generowane losowo (inne przy kazdym uruchomieniu) i musza byc zgodne z powyzszym formatem.

## Odwrotna notacja polska (ONP.cpp)

Napisz program, który za pomoca stosu zamienia wyrazenie arytmetyczne w zapisie klasycznym na odwrotna notacje polska.

- W wyrazeniu wystepuja jedynie nawiasy okragłe ( ), operatory binarne + - * / i dodatnie liczby całkowite. Kazdy z w.w. elementów jest oddzielony spacja.
- Kazdewyrazenie ma składnie nawias_otwierajacy lewy_argument operator prawy_argument nawias_zamykajacy. Kazda z operacji wraz z argumentami objeta jest nawiasem, w zwiazku z czym mozna pominac kolejnosc wykonywania działan.

Przykładowe dane wejsciowe i wyjsciowe:
```
( 11 + ( ( ( ( 1 + 2 ) * ( 4 - 3 ) ) + ( 4 / 2 ) ) * ( 8 - 6 ) ) )

11 1 2 + 4 3 - * 4 2 / + 8 6 - * +
```

## Pytania

- Omów przykłady zastosowania stosu?
- Dlaczego operacja pop() z std::stack nie zwraca wartosci elementu?
- Dlaczego operacja pop() z std::stack nie zwraca referencji do elementu?

## Dodatkowe punkty

Dodatkowe punkty (po 1 pkt) mozna zdobyc za:

- Napisanie szablonu klas
- Wykorzystanie referencji do r-wartosci, semantyki przenoszenia, uniwersalnych referencji, doskonałego
przekazywanie.
- Napisanie testera

Napisac szablon klas wg ponizszego schematu, który implementuje stos przechowujacy obiekty typu T w oparciu o tablice o rozmiarze N.

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