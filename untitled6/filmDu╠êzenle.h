//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_FILMDÜZENLE_H
#define UNTITLED6_FILMDÜZENLE_H

#include <stdio.h>
#include "veritabani.h"

void filmDuzenle(struct Veritabani *vt) {
    if (vt->filmSayisi == 0) {
        printf("Duzenlenecek film bulunmamaktadir.\n");
        return;
    }

    int indeks;
    printf("Duzenlemek istediginiz film indeksini girin (1-%d): ", vt->filmSayisi);
    scanf("%d", &indeks);

    // Kullanıcının girdiği indeksin geçerli olup olmadığını kontrol et
    if (indeks < 1 || indeks > vt->filmSayisi) {
        printf("Gecersiz film indeksi. Tekrar deneyin.\n");
        return;
    }

    // Film bilgilerini güncelle
    printf("Yeni film adini girin: ");
    scanf("%s", vt->filmler[indeks - 1].ad);
    printf("Yeni yonetmen adini girin: ");
    scanf("%s", vt->filmler[indeks - 1].yonetmen);
    printf("Yeni yilini girin: ");
    scanf("%d", &vt->filmler[indeks - 1].yil);

    // Prompt for the new genre
    printf("Yeni turunu girin: ");
    scanf("%s", vt->filmler[indeks - 1].tur);

    printf("Film basariyla duzenlendi.\n");
}
#endif //UNTITLED6_FILMDÜZENLE_H
