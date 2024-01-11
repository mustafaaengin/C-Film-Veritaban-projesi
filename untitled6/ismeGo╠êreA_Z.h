//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_ISMEGÖREA_Z_H
#define UNTITLED6_ISMEGÖREA_Z_H

#include <string.h>
#include "veritabani.h"

int compareByFilmNameAsc(const void *a, const void *b) {
    return strcmp(((struct Film *)a)->ad, ((struct Film *)b)->ad);
}

#endif //UNTITLED6_ISMEGÖREA_Z_H
