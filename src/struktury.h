#ifndef _STRUCT_H
#define _STRUCT_H

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

#endif