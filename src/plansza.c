#include "plansza.h"
#include "mrowka.h"


void stworz_plansze(Plansza *plansza, int GRID_M, int GRID_N) {
    plansza->GRID_M = GRID_M;
    plansza->GRID_N = GRID_N;

    allocate_plansza(plansza);

    for (int i = 0; i < plansza->GRID_M; i++) {
        for (int j = 0; j < plansza->GRID_N; j++)
            plansza->dane[i][j] = WHITE;
    }
}

void allocate_plansza(Plansza *plansza) {
    plansza->dane = malloc(plansza->GRID_M * sizeof(enum Kolor*));
    for (int i = 0; i < plansza->GRID_M; i++) {
        plansza->dane[i] = malloc(plansza->GRID_N * sizeof(enum Kolor));
    }
}

void wypisz_plansze(Plansza *plansza, Mrowka mrowka) {
    for (int i = 0; i < plansza->GRID_M; i++) {
        for (int j = 0; j < plansza->GRID_N; j++) {
            if (mrowka.x == i && mrowka.y == j) {
                switch (mrowka.direction) {
                    case NORTH: printf("▲|"); break;
                    case EAST:  printf("▶|"); break;
                    case SOUTH: printf("▼|"); break;
                    case WEST:  printf("◀|"); break;
                
                    
                }
            } else {
                printf(plansza->dane[i][j] == WHITE ? " |": "█|");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 2*plansza->GRID_N; i++) {
        printf("─");
    }
    printf("\n");
}


void zmien_kolor(Plansza *plansza, Mrowka *mrowka) {
    if (plansza->dane[mrowka->x][mrowka->y] == WHITE) {
        na_prawo(mrowka);
        plansza->dane[mrowka->x][mrowka->y] = BLACK;
    } else {
        na_lewo(mrowka);
        plansza->dane[mrowka->x][mrowka->y] = WHITE;
    }

    idz_przod(plansza, mrowka);
}

