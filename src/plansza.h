#ifndef _PLANSZA_H
#define _PLANSZA_H

#include "struktury.h"


void stworz_plansze(Plansza *plansza, int GRID_M, int GRID_N);

void allocate_plansza(Plansza *plansza);

void wypisz_plansze(Plansza *plansza, Mrowka mrowka);

void zmien_kolor(Plansza *plansza, Mrowka *mrowka);


#endif
