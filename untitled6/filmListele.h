//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_FILMLISTELE_H
#define UNTITLED6_FILMLISTELE_H

#include <printf.h>
#include "veritabani.h"

void filmListele(struct Veritabani vt) {
    printf("\n----- Filmler -----\n");
    for (int i = 0; i < vt.filmSayisi; i++) {
        printf("%d. Film\n", i + 1);
        printf("Ad: %s\n", vt.filmler[i].ad);
        printf("Yonetmen: %s\n", vt.filmler[i].yonetmen);
        printf("Yil: %d\n", vt.filmler[i].yil);
        printf("Tur: %s\n", vt.filmler[i].tur);
        printf("---------------------\n");
    }
}
#endif //UNTITLED6_FILMLISTELE_H
