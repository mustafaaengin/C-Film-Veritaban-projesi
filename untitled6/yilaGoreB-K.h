//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_YILAGOREB_K_H
#define UNTITLED6_YILAGOREB_K_H
#include "veritabani.h"

int compareByReleaseYearDesc(const void *a, const void *b) {
    return ((struct Film *)b)->yil - ((struct Film *)a)->yil;
}


#endif //UNTITLED6_YILAGOREB_K_H
