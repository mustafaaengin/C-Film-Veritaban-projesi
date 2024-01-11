//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_FILMYILAGORELISTELE_H
#define UNTITLED6_FILMYILAGORELISTELE_H


#include <stdio.h>
#include "veritabani.h"

void filmYilaGoreListele(struct Veritabani vt) {
    if (vt.filmSayisi == 0) {
        printf("Listelenecek film bulunmamaktadir.\n");
        return;
    }

    int arananYil;
    printf("Listelenecek filmlerin yilini girin: ");
    scanf("%d", &arananYil);

    int bulunan = 0;
    for (int i = 0; i < vt.filmSayisi; i++) {
        if (vt.filmler[i].yil == arananYil) {
            printf("Film bulundu:\n");
            printf("Ad: %s\n", vt.filmler[i].ad);
            printf("Yonetmen: %s\n", vt.filmler[i].yonetmen);
            printf("Yil: %d\n", vt.filmler[i].yil);
            bulunan = 1;
            printf("------------------------------\n");
        }
    }
    if (!bulunan) {
        printf("Girilen yila ait film bulunamadi.\n");
    }
}

#endif //UNTITLED6_FILMYILAGORELISTELE_H
