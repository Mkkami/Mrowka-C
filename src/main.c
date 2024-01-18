#include "plansza.h"
#include "mrowka.h"
#include "random_gen.h"
#include <unistd.h> // getopt

int main(int argc, char **argv) {

    // poczatkowe wartosci
    int GRID_M = 50;
    int GRID_N = 50;
    int iteracje = 20;
    enum Kierunek init_direction = NORTH;
    double procent_random = 0.0;
    char *filename = NULL;
    char *out_folder = "wyniki";
    int IF_FILE = 0;

    int opt;
    while ((opt = getopt(argc, argv, "m:n:i:p:d:r:")) != -1) {
        switch (opt) {
            case 'm':
                GRID_M = atoi(optarg);
                break;
            case 'n':
                GRID_N = atoi(optarg);
                break;
            case 'i':
                iteracje = atoi(optarg);
                break;
            case 'p':
                filename = optarg;
                IF_FILE = 1;
                break;
            case 'd':
                init_direction = str_to_enum(optarg);
                break;
            case 'r':
                procent_random = atof(optarg);
                break;
            default:
                fprintf(stderr, "\t %s [-m wiersze] [-n kolumny] [-i iteracje] [-p nazwa_pliku] [-d kierunek_mrowki] [-r procent_wypelnienia]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    
    Plansza plansza;
    Mrowka mrowka = { GRID_M / 2, GRID_N / 2, init_direction};

    stworz_plansze(&plansza, GRID_M, GRID_N);

    if (procent_random > 0.0) {
        wypelnij_plansze(&plansza, procent_random);
    }

    char out_name[500];
    for (int step = 0; step < iteracje+1; step++) {
        switch (IF_FILE) {
            case 1:
                sprintf(out_name, "%s/%s_%d", out_folder, filename, step);

                FILE *file = fopen(out_name, "w");
                wypisz_plansze(&plansza, mrowka, file);
                zmien_kolor(&plansza, &mrowka);
                fclose(file);
                break;
            case 0:
                wypisz_plansze(&plansza, mrowka, stdout);
                zmien_kolor(&plansza, &mrowka);
                break;
        }

    }

    return 0;
}