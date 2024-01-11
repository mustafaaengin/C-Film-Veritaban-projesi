//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_DOSYAYAYAZ_H
#define UNTITLED6_DOSYAYAYAZ_H

#include <stdio.h>
#include "veritabani.h"

void dosyayaYaz(struct Veritabani vt, const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    for (int i = 0; i < vt.filmSayisi; i++) {
        fprintf(dosya, "%s;%s;%d;%s\n", vt.filmler[i].ad, vt.filmler[i].yonetmen, vt.filmler[i].yil, vt.filmler[i].tur);
    }

    fclose(dosya);
}

#endif //UNTITLED6_DOSYAYAYAZ_H
