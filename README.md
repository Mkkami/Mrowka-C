# Mrówka Langtona C

# Opis zadania 

### Program

Proszę zaimplementować program obliczający kolejne etapy mrówki Langtona i zapisujący je do pliku lub w przypadku, gdy nie podamy nazwy pliku, na standardowe wyjście.

Program powinien przyjmować następujące parametry:

* Liczbę wierszy planszy m

* Liczbę kolumn planszy n

* Liczbę iteracji i

* Przedrostek plików wynikowych name (pełna nazwa tworzonych plików powinna mieć strukturę file_nriteracji)

* Początkowy kierunek mrówki

Ponadto program powinien umożliwiać:

* opcjonalne wczytanie mapy z naniesionymi już „czarnymi” polami i aktualną pozycją mrówki

* opcjonalne wygenerowanie w programie mapy z losowo ustawionymi „czarnymi” polami/ przeszkodami wg procentowego zapełnienia planszy podanego przez użytkownika

### Zasady Mrówki

Mrówka chodzi po dwuwymiarowej siatce. Może poruszać się w jednym z 4-ech kierunków (góra, dół, lewo, prawo), zgodnie z następującymi zasadami:

* Mrówka znajduje się w komórce białej, wykonuje: obrót o 90 stopni w prawo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu

* Mrówka znajduje się w komórce czarnej, wykonuje: obrót o 90 stopni w lewo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu

### Funkcje
* Symulacja Mrówki Langtona na planszy.
* Możliwość dostosowania:
* * rozmiaru siatki, 
* * liczby iteracji, 
* * nazwy pliku wyjściowego, 
* * początkowego kierunku mrówki
* * procentowego wypełnienia planszy czarnym kolorem

## Instalacja
>Wymagania:
> * Kompilator GCC
> * Środowisko Unix
```bash
git clone git@github.com:Mkkami/Mrowka-C.git
cd Mrowka-C
make
```
## Korzystanie
```bash
/bin/mrowka -m <liczba_wierszy> -n <liczba_kolumn> -i <iteracje> -p <plik_wyjsciowy> -d <poczatkowy_kierunek> -r <procent_wypelnienia>
```
> -m : Liczba wierszy planszy.
> -n : Liczba kolumn planszy.
> -i : Liczba iteracji (kroków) mrówki.
> -p : Nazwa pliku wyjściowego. (_nazwa_\_niteracji)
> -d : Początkowy kierunek mrówki (**N**, **S**, **W**, **E**).
> -r : Procent wypełnienia planszy ( **0.0**-**100.0**)

Przykład:
```
./src/mrowka -m 50 -n 50 -i 100 -p plik -d N -r 25
```


## Struktura programu

Kod programu znajduje się w folderze _src_. Podział modułów:
* **main.c** - Główna funkcja, przetwarzane są tu dane wejściowe od użytkownika, odpowiada za sterowanie programem.
* **mrowka.c** i **mrowka.h** - definicja i implementacja funkcji odpowiadających za ruch mrówki.
* **plansza.c** i **plansza.h** - definicja i implementacja funkcji odpowiadających za zmiany na planszy.
* **random_gen.c** i **random_gen.h** - definicja i implementacja funkcji do losowego generowania planszy.
## Podstawowe Funkcje i Struktury
### Mrowka
```c
typedef struct Mrowka {
	int x;
	int y;
	enum Kierunek direction;
} Mrowka;
```
> * na_lewo(Mrowka *mrowka) - obraca mrówkę w lewo
> * na_prawo(Mrowka *mrowka) - obraca mrówkę w prawo
> * idz_przod(Plansza *plansza, Mrowka *mrowka) - Przesuwa mrówkę do przodu zgodnie z jej kierunkiem
> * enum Kierunek str_to_enum(const char *str) - Zamienia string na enum reprezentujący kierunek.

### Plansza
```c
typedef struct Plansza {
	int GRID_M;
	int GRID_N;
	enum Kolor **dane;
} Plansza;
```

> * stworz_plansze(Plansza *plansza, int GRID_M, int GRID_N) - tworzy planszę o określonych wymiarach.
> * allocate_plansza(Plansza *plansza) - alokuje pamięć dla planszy.
> * wypisz_plansze(Plansza *plansza, Mrowka mrowka, FILE *file) - wypisuje planszę i mrówkę do pliku
> * zmien_kolor(Plansza *plansza, Mrowka *mrowka) - zmienia kolor pola, na którym znajduje się mrówka i przesuwa ją do przodu.

### Random gen
> * zmien_na_czarne(Plansza *plansza) - zmienia wszystkie pola planszy na czarne.
> * wypelnij_losowe(Plansza *plansza, int ile) - wypełnia losowo wybrane pola na planszy.
> * wypelnij_plansze(Plansza *plansza, double procent) - wypełnia planszę w zależności od podanego procentu

## Przykładowe wykonanie
```bash
bin/mrowka -m 25 -n 25 -i 100 -p plik -d E
```
To polecenie uruchomi Mrówkę Langtona na planszy o rozmiarze 25x25 i zrobi 100 kroków, zaczynając w stronę wschodu. Wyniki symulacji zostaną zapisane do folderu _wyniki_, a każde przejście zostane zapisane w oddzielnym pliku o nazwie plik_[niteracji].
### Wynik ostatniego przejścia mrówki:
```plaintext
┌─────────────────────────┐
│                         │
│                         │
│                         │
│                         │
│                         │
│                         │
│                         │
│                         │
│                         │
│          ██             │
│         █  █            │
│        █   ██ █         │
│        █ ███ ▶ █        │
│         █      █        │
│            █  █         │
│             ██          │
│                         │
│                         │
│                         │
│                         │
│                         │
│                         │
│                         │
│                         │
│                         │
└─────────────────────────┘
```

## Przykładowa generacja losowych pól
```bash
bin/mrowka -m 25 -n 25 -i 10 -p plik -d N -r 25
```
### Początkowa pozycja mrówki i plansza:
```plaintext
┌─────────────────────────┐
│    █ █          █ █     │
│██ █      ██    █ █      │
│   █     ███   █ ██      │
│ █   █   █  █          █ │
│ █     ██     █         █│
│ █     ██            █   │
│█    █    █ ███     █   █│
│    █       █     █     █│
│           ██     █   █ █│
│  █ █ █ █  █ █  █  █    █│
│   █      ██            █│
│██   █ █   █         █ █ │
│██ ██ █ █ ██△ █ █      ██│
│ █  ██     █   █    ███  │
│█     █        ███ █  █  │
│   ██      ███    █   █ █│
│ █    █    █    █        │
│   █       █       ███   │
│   ██                 █ █│
│█             █  █ █ █  █│
│    █    █ █ █ █    ██  █│
│  █ █ █  ██     █ ██     │
│  ███   █     █     █  █ │
│  █            █   █  █  │
│      █  █ ██       █  █ │
└─────────────────────────┘
```
### Przykład przejścia mrówki na drugi koniec planszy
```bash
bin/mrowka -m 50 -n 50 -i 10000 -p plik -d N
```
> Uwaga: Mrówka wykonuje 10000 przejść. Stworzenie plików może zająć dużo czasu!
```plaintext
┌──────────────────────────────────────────────────┐
│                                                  │
│                                                  │
│                                                  │
│                 ██  ████████████  ██             │
│                █  ████          █  ██            │
│               ███   ██            ██ █           │
│               █ █  █         █  █    █           │
│           ██  ██ █ █         ███       █         │
│        ███ █  █   █     █     ██ ██  ███         │
│         █ █  ███  ██ ████ ██   █ █  █ ██  ██     │
│         █ ███ ██  █ ██  ███ █ █     ███   ███    │
│       █     █   █████ █ █  ████  █   ███ █ █ █   │
│      ███ ██   █ ████  ██ ██ ██████ █ ███ █   █   │
│      █ ███ █ ██ █ █ ██ ██ ██ █   █████ ███ ██    │
│          █ █   █ ██ ███   █   █ █  ████    █ ██  │
│       ██▲█         ██ ██   █  ██     ██ █     ██ │
│       █ ██ █ █ ██ ███  █  ██     █   ███ ██  ██ █│
│         █ █ ██   ██ ██   ███  █    █  ██ ████   █│
│        ████  █ █  █ █ ████ ██  █ ██ ███  █     █ │
│█       █ ██ ██    █  █ ███  █      ███ ██ █  █  █│
│ █       ██   █ ██ █ ██  ██  █████ ████  ████ ██  │
│  █       ██ █  █ ███ █ █ ██      ██   █ █ █    █ │
│  █         ███  ██ █   ██       ████ ████   █    │
│ █          █   ██  ███████████ █  ████  █    █   │
│██             █ ████  ██  █████████  █  ██    █  │
│█ █        ██  █ ██   ██ ██ ███ ███   █  █ ██  ███│
│  █       █  █ ██████ ██ █ ██ █ █    ███ ███   ██ │
│ █       █     █████ █ █████     █ █  ██ █    ██  │
│ █       █     █ ██ █████ ██  █ █   █  █  ██ █  █ │
│██       █    █   ████ █  █████ ██   ██████████   │
│         █ ██   ██   █  █   ████  █   ██ ████ ██  │
│          █████ █  ██   ██ █   █    █ █  █  █  █ █│
│           ██  ██ █ █ █    ██ ██ █ █ ██  █  ██  ██│
│                 █  █    █ ████████ █ █ ██  ████ █│
│                 █  █   █       ██ ██   █  █  ██ █│
│                  █  █  █      █  ██  ██   ██ ████│
│█                  ██   █       ██  ██    █   █ ██│
│█                       █ ██  ████    ████ ███ ███│
│ █                       ██  ████    ██  █ ██ █ █ │
│███                       ██    ██    ██ ███ ██ ██│
│███                                      █ ██ █  █│
│ ██                                          ██ ██│
│                                             ██   │
│███ █                                      █ ██  █│
│  ███                                     █  █ ███│
│█  █                                      █ ██ █  │
│ ██                                        ██     │
│                                            ██    │
│                                                  │
│                                                  │
└──────────────────────────────────────────────────┘
```
## Wnioski
Mrówka Langtona, pomimo prostych zasad, wykazuje złożone i nieprzewidywalne zachowanie, tworząc fascynujące wzory. Implementacja programu demonstruje modularność i klarowność, co ułatwia zrozumienie i rozwijanie projektu.