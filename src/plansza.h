#ifndef _PLANSZA_H
#define _PLANSZA_H

#include "struktury.h"

#define LINE_VERTICAL │
#define LINE_HORIZONTAL ─
#define LINE_DOWN_RIGHT ┌
#define LINE_DOWN_LEFT ┐
#define LINE_UP_RIGHT └
#define LINE_UP_LEFT ┘


void stworz_plansze(Plansza *plansza, int GRID_M, int GRID_N);

void allocate_plansza(Plansza *plansza);

void wypisz_plansze(Plansza *plansza, Mrowka mrowka, FILE *file);

void zmien_kolor(Plansza *plansza, Mrowka *mrowka);

void wczytaj_plansze(Plansza *plansza, Mrowka *mrowka, FILE *in);

#endif
