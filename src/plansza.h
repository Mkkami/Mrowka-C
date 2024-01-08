#ifndef _PLANSZA_H
#define _PLANSZA_H

#include <stdio.h>
#include <stdlib.h>

enum Kierunek {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

enum Kolor {
    WHITE,
    BLACK,
};

typedef struct Mrowka {
    int x;
    int y;
    enum Kierunek direction;
} Mrowka;

typedef struct Plansza {
    int GRID_M;
    int GRID_N;
    enum Kolor **dane;
} Plansza;

void stworz_plansze(Plansza *plansza, int GRID_M, int GRID_N);

void allocate_plansza(Plansza *plansza);

void wypisz_plansze(Plansza *plansza, Mrowka mrowka);

void zmien_kolor(Plansza *plansza, Mrowka *mrowka);

void na_lewo(Mrowka * mrowka);

void na_prawo(Mrowka * mrowka);

void idz_przod(Plansza *plansza, Mrowka *mrowka);


#endif
