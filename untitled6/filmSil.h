//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_FILMSIL_H
#define UNTITLED6_FILMSIL_H


#include <stdlib.h>
#include <stdio.h>
#include "filmKontrol.h"
#include "veritabani.h"


void filmSil(struct Veritabani *vt) {
    if (vt->filmSayisi == 0) {
        printf("Silinecek film bulunmamaktadir.\n");
        return;
    }

    int indeks;
    printf("Silmek istediginiz film indeksini girin (1-%d): ", vt->filmSayisi);
    scanf("%d", &indeks);

    // Kullanıcının girdiği indeksin geçerli olup olmadığını kontrol et
    if (indeks < 1 || indeks > vt->filmSayisi) {
        printf("Gecersiz film indeksi. Tekrar deneyin.\n");
        return;
    }

    // Silinecek filmi bulunduğu indeksin üzerine taşı
    for (int i = indeks - 1; i < vt->filmSayisi - 1; i++) {
        strcpy(vt->filmler[i].ad, vt->filmler[i + 1].ad);
        strcpy(vt->filmler[i].yonetmen, vt->filmler[i + 1].yonetmen);
        vt->filmler[i].yil = vt->filmler[i + 1].yil;
    }

    // Bellekte ayrılan alanı azalt
    vt->filmler = (struct Film *)realloc(vt->filmler, (vt->filmSayisi - 1) * sizeof(struct Film));

    // Film sayısını azalt
    vt->filmSayisi--;

    printf("Film basariyla silindi.\n");
}

#endif //UNTITLED6_FILMSIL_H
