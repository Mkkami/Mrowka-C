#include "mrowka.h"

void na_lewo(Mrowka *mrowka) {
    mrowka->direction = (mrowka->direction + 3) % 4;
}

void na_prawo(Mrowka *mrowka) {
    mrowka->direction = (mrowka->direction + 1) % 4;
}

void idz_przod(Plansza *plansza, Mrowka *mrowka) {
    switch (mrowka->direction) {
        case NORTH: mrowka->x = (mrowka->x - 1 + plansza->GRID_M) % plansza->GRID_M; break;
        case EAST:  mrowka->y = (mrowka->y + 1) % plansza->GRID_N; break;
        case SOUTH: mrowka->x = (mrowka->x + 1) % plansza->GRID_M; break;
        case WEST:  mrowka->y = (mrowka->y - 1 + plansza->GRID_N) % plansza->GRID_N; break;
    }
}