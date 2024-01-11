//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_DOSYADANOKU_H
#define UNTITLED6_DOSYADANOKU_H

#include <stdio.h>
#include <stdlib.h>
#include "veritabani.h"

void dosyadanOku(struct Veritabani *vt, const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi. Yeni bir dosya olusturulacak.\n");
        return;
    }

    while (!feof(dosya)) {
        // Yeni film eklemek için bellek ayır
        vt->filmler = (struct Film *)realloc(vt->filmler, (vt->filmSayisi + 1) * sizeof(struct Film));

        fscanf(dosya, "%[^;];%[^;];%d;%[^\n]\n", vt->filmler[vt->filmSayisi].ad, vt->filmler[vt->filmSayisi].yonetmen, &vt->filmler[vt->filmSayisi].yil, vt->filmler[vt->filmSayisi].tur);

        // Film sayısını artır
        vt->filmSayisi++;
    }

    fclose(dosya);
}
#endif //UNTITLED6_DOSYADANOKU_H
