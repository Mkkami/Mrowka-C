#include "plansza.h"
#include "mrowka.h"

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