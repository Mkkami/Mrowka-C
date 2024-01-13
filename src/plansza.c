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
    for (int j = 0; j < plansza->GRID_N+2; j++) {
        fprintf(file, "-");
    }
    fprintf(file, "\n");

    for (int i = 0; i < plansza->GRID_M; i++) {     //wiersze
        fprintf(file, "|"); // lewa krawędź

        for (int j = 0; j < plansza->GRID_N; j++) { //kolumny
            if (mrowka.x == i && mrowka.y == j) {
                switch (mrowka.direction) {
                    case NORTH: fprintf(file, "N"); break;
                    case EAST:  fprintf(file, "E"); break;
                    case SOUTH: fprintf(file, "S"); break;
                    case WEST:  fprintf(file, "W"); break;
                }
            } else {
                fprintf(file, plansza->dane[i][j] == WHITE ? " ": "X");
            }
        }

        fprintf(file, "|\n"); // prawa krawędź
    }

    // Dolna ramka
    for (int j = 0; j < plansza->GRID_N + 2; j++) {
        fprintf(file, "-");
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

#include "string.h"

void wczytaj_plansze(Plansza *plansza, Mrowka *mrowka, FILE *in)
{
    char wczytanaPlansza[256][256];
    int M = 0, N = 0;

    char wiersz[256];
    while (fgets(wiersz, 256, in))
    {
        strcpy(wczytanaPlansza[M++], wiersz);
    }

    N = strlen(wczytanaPlansza[0]) - 3;
    M -= 2;

    stworz_plansze(plansza, M, N);

    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(wczytanaPlansza[i][j] == 'N')
            {
                mrowka->direction = NORTH;
                mrowka->x = i-1;
                mrowka->y = j-1;
            }
            else if(wczytanaPlansza[i][j] == 'E')
            {
                mrowka->direction = EAST;
                mrowka->x = i-1;
                mrowka->y = j-1;
            }
            else if(wczytanaPlansza[i][j] == 'S')
            {
                mrowka->direction = SOUTH;
                mrowka->x = i-1;
                mrowka->y = j-1;
            }
            else if(wczytanaPlansza[i][j] == 'W')
            {
                mrowka->direction = WEST;
                mrowka->x = i-1;
                mrowka->y = j-1;
            }
            else if(wczytanaPlansza[i][j] == ' ')
            {
                plansza->dane[i-1][j-1] = WHITE;
            }
            else if(wczytanaPlansza[i][j] == 'X')
            {
                plansza->dane[i-1][j-1] = BLACK;
            }
        }
    }

    //wypisz_plansze(plansza, *mrowka, stdout); --->Test
}

