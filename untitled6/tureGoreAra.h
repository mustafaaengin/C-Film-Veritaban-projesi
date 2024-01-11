//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_TUREGOREARA_H
#define UNTITLED6_TUREGOREARA_H


#include <stdio.h>
#include "filmIslemleri.h"
#include "filmAra.h"
#include "veritabani.h"

// Türüne göre filmleri listeleyen fonksiyon
void filmAraTur(struct Veritabani vt) {
    // Eğer veritabanında hiç film yoksa bilgi ver ve fonksiyondan çık
    if (vt.filmSayisi == 0) {
        printf("Aranacak film bulunmamaktadir.\n");
        return;
    }

    // Kullanıcıdan aranacak film türünü al
    char arananTur[50];
    printf("Aranacak film turunu girin: ");
    scanf("%s", arananTur);

    // Arama sorgusunu küçük harfe çevir
    cevirici(arananTur);

    // Filmleri tür adına göre listeleyin (büyük-küçük harf duyarsız)
    int bulunan = 0;
    for (int i = 0; i < vt.filmSayisi; i++) {
        // Filmin tür adını karşılaştırma için küçük harfe çevir
        char filmTurLowerCase[50];
        strcpy(filmTurLowerCase, vt.filmler[i].tur);
        cevirici(filmTurLowerCase);

        // Eğer film türü arananla eşleşirse bilgileri ekrana yazdır
        if (strcmp(filmTurLowerCase, arananTur) == 0) {
            printf("Film bulundu:\n");
            printf("Ad: %s\n", vt.filmler[i].ad);
            printf("Yonetmen: %s\n", vt.filmler[i].yonetmen);
            printf("Yil: %d\n", vt.filmler[i].yil);
            printf("Tur: %s\n", vt.filmler[i].tur);
            bulunan = 1;
            printf("------------------------------\n");
        }
    }

    // Eğer film bulunamadıysa bilgi ver
    if (!bulunan) {
        printf("Girilen türe ait film bulunamadi.\n");
    }
}

#endif //UNTITLED6_TUREGOREARA_H
