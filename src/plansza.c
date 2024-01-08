#include "plansza.h"


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

int main(int argc, char **argv) {
    const int GRID_M = argc > 1 ? atoi(argv[1]) : 50;
    const int GRID_N = argc > 2 ? atoi(argv[2]) : 50;
    
    Plansza plansza;
    Mrowka mrowka = { GRID_M / 2, GRID_N / 2, NORTH};
    int iteracje = argc > 3 ? atoi(argv[3]) : 50;

    stworz_plansze(&plansza, GRID_M, GRID_N);

    for (int step = 0; step < iteracje; step++) {
        wypisz_plansze(&plansza, mrowka);
        zmien_kolor(&plansza, &mrowka);
    }

    return 0;
}