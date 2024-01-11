//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_ISMEGÖREZ_A_H
#define UNTITLED6_ISMEGÖREZ_A_H

#include <string.h>
#include "veritabani.h"

int compareByFilmNameDesc(const void *a, const void *b) {
    return strcmp(((struct Film *)b)->ad, ((struct Film *)a)->ad);
}


#endif //UNTITLED6_ISMEGÖREZ_A_H
