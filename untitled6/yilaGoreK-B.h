//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_YILAGOREK_B_H
#define UNTITLED6_YILAGOREK_B_H
#include "veritabani.h"

int compareByReleaseYearAsc(const void *a, const void *b) {
    return ((struct Film *)a)->yil - ((struct Film *)b)->yil;
}
#endif //UNTITLED6_YILAGOREK_B_H
