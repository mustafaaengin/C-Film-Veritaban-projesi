//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_FILMARA_H
#define UNTITLED6_FILMARA_H


#include <string.h>
#include <stdio.h>
#include "filmIslemleri.h"
#include "veritabani.h"


void filmAra(struct Veritabani vt) {
    // Eğer veritabanında hiç film yoksa bilgi ver ve fonksiyondan çık
    if (vt.filmSayisi == 0) {
        printf("Aranacak film bulunmamaktadir.\n");
        return;
    }

    // Kullanıcıdan aranacak film adını al
    char aranan[50];
    printf("Aranacak film adini girin: ");
    scanf("%s", aranan);

    // Arama sorgusunu küçük harfe çevir
    cevirici(aranan);

    // Film adını ara (büyük-küçük harf duyarsız)
    int bulunan = 0;
    for (int i = 0; i < vt.filmSayisi; i++) {
        // Film adını karşılaştırma için küçük harfe çevir
        char filmAdLowerCase[50];
        strcpy(filmAdLowerCase, vt.filmler[i].ad);
        cevirici(filmAdLowerCase);

        // Eğer film adı arananla eşleşirse bilgileri ekrana yazdır ve döngüden çık
        if (strcmp(filmAdLowerCase, aranan) == 0) {
            printf("Film bulundu:\n");
            printf("Ad: %s\n", vt.filmler[i].ad);
            printf("Yonetmen: %s\n", vt.filmler[i].yonetmen);
            printf("Yil: %d\n", vt.filmler[i].yil);
            bulunan = 1;
            break;
        }
    }

    // Eğer film bulunamadıysa bilgi ver
    if (!bulunan) {
        printf("Film bulunamadi.\n");
    }
}

#endif //UNTITLED6_FILMARA_H
