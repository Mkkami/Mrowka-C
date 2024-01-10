#include "plansza.h"
#include "mrowka.h"
#include <unistd.h> // getopt

int main(int argc, char **argv) {

    // poczatkowe wartosci
    int GRID_M = 50;
    int GRID_N = 50;
    int iteracje = 20;
    char *out_folder = "wyniki";
    char *filename = "file";
    enum Kierunek init_direction = NORTH;

    int opt;
    while ((opt = getopt(argc, argv, "m:n:i:p:d:")) != -1) {
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
                break;
            case 'd':
                init_direction = str_to_enum(optarg);
                break;
            default:
                fprintf(stderr, "\t %s [-m wiersze] [-n kolumny] [-i iteracje] [-p nazwa_pliku] [-d kierunek_mrowki]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    
    Plansza plansza;
    Mrowka mrowka = { GRID_M / 2, GRID_N / 2, init_direction};

    stworz_plansze(&plansza, GRID_M, GRID_N);

    char out_name[500];
    for (int step = 1; step < iteracje+1; step++) {
        sprintf(out_name, "%s/%s_%d", out_folder, filename, step);

        FILE *file = fopen(out_name, "w");
        wypisz_plansze(&plansza, mrowka, file);
        zmien_kolor(&plansza, &mrowka);
        fclose(file);
    }

    return 0;
}