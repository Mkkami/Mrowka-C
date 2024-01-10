#ifndef _MROWKA_H
#define _MROWKA_H

#include "struktury.h"

void na_lewo(Mrowka * mrowka);

void na_prawo(Mrowka * mrowka);

void idz_przod(Plansza *plansza, Mrowka *mrowka);

enum Kierunek str_to_enum(const char *str);

#endif