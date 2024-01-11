#include "random_gen.h"

void zmien_na_czarne(Plansza *plansza) {
    for (int i = 0; i < plansza->GRID_M; ++i) {
        for (int j = 0; j < plansza->GRID_N; ++j) {
            plansza->dane[i][j] = BLACK;
        }
    }
}


void wypelnij_losowe(Plansza *plansza, int ile, int inny_kolor) {
    srand(time(NULL));

    int pozostale = plansza->GRID_M * plansza->GRID_N;
    int wypelnione = 0;

    while (wypelnione < ile && wypelnione < pozostale) {
        int rand_x = rand() % plansza->GRID_M;
        int rand_y = rand() % plansza->GRID_N;

        switch(inny_kolor) {
            case 0:       
                if (plansza->dane[rand_x][rand_y] == WHITE) {
                    plansza->dane[rand_x][rand_y] = BLACK;
                    wypelnione++;
                }
            case 1:
                if (plansza->dane[rand_x][rand_y] == BLACK) {
                        plansza->dane[rand_x][rand_y] = WHITE;
                        wypelnione++;
                }
        }
    }
}


void wypelnij_plansze(Plansza *plansza, double procent) {
    if (procent < 0.0 || procent > 100.0) {
        fprintf(stderr, "Zly procent! - %lf\n", procent);
        exit(EXIT_FAILURE);
    }

    int ile_komorek = plansza->GRID_M * plansza->GRID_N;
    int inny_kolor = 0;

    if (procent == 100.0) {
        zmien_na_czarne(plansza);
    } else {
        if (procent > 50.0) {
            zmien_na_czarne(plansza);
            procent = 100.0 - procent;
        }
        int wypelnione = (int)(procent / 100.0 * ile_komorek);
        printf("wypelnione: %d\n", wypelnione);
        wypelnij_losowe(plansza, wypelnione, inny_kolor);
    } 
}