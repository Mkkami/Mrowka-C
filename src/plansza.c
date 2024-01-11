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

void wypisz_plansze(Plansza *plansza, Mrowka mrowka, FILE *file) {
    // Górna ramka
    fprintf(file, "┌");
    for (int j = 0; j < plansza->GRID_N; j++) {
        fprintf(file, "─");
    }
    fprintf(file, "┐\n");

    for (int i = 0; i < plansza->GRID_M; i++) {     //wiersze
        fprintf(file, "│"); // lewa krawędź

        for (int j = 0; j < plansza->GRID_N; j++) { //kolumny
            if (mrowka.x == i && mrowka.y == j) {
                switch (mrowka.direction) {
                    case NORTH: fprintf(file, "▲"); break;
                    case EAST:  fprintf(file, "▶"); break;
                    case SOUTH: fprintf(file, "▼"); break;
                    case WEST:  fprintf(file, "◀"); break;
                }
            } else {
                fprintf(file, plansza->dane[i][j] == WHITE ? " ": "█");
            }
        }

        fprintf(file, "│\n"); // prawa krawędź
    }

    // Dolna ramka
    fprintf(file, "└");
    for (int j = 0; j < plansza->GRID_N; j++) {
        fprintf(file, "─");
    }
    fprintf(file, "┘\n");

    fprintf(file, "\n");
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

