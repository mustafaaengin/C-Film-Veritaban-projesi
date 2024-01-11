//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_FILMEKLE_H
#define UNTITLED6_FILMEKLE_H


#include <printf.h>
#include <stdlib.h>
#include "filmKontrol.h"
#include "veritabani.h"


void filmEkle(struct Veritabani *vt) {
    // Yeni film eklemek için bellek ayır
    vt->filmler = (struct Film *)realloc(vt->filmler, (vt->filmSayisi + 1) * sizeof(struct Film));

    // Film bilgilerini kullanıcıdan al
    printf("Film adini girin: ");
    scanf("%s", vt->filmler[vt->filmSayisi].ad);
    printf("Yonetmen adini girin: ");
    scanf("%s", vt->filmler[vt->filmSayisi].yonetmen);

    int yil;
    while (1) {
        printf("Yilini girin: ");
        if (scanf("%d", &yil) != 1) {
            // Eğer kullanıcı bir tam sayı girişi yapmazsa
            printf("Hata: Lutfen gecerli bir yil girin.\n");
            // Bufferı temizle
            while (getchar() != '\n');
        } else {
            // Geçerli bir tam sayı girişi yapıldı, döngüden çık
            break;
        }
    }
    vt->filmler[vt->filmSayisi].yil = yil;

    printf("Turunu girin: ");
    scanf("%s", vt->filmler[vt->filmSayisi].tur);

    // Check for duplicate films
    if (filmKontrol(*vt, vt->filmler[vt->filmSayisi])) {
        // If duplicate, remove the last added film and inform the user
        vt->filmler = (struct Film *)realloc(vt->filmler, vt->filmSayisi * sizeof(struct Film));
        printf("Hata: Ayni film, yonetmen ve yil bilgileriyle daha once eklenmis.\n");
    } else {
        // Film sayısını artır
        vt->filmSayisi++;
        printf("Film basariyla eklendi.\n");
    }
}

#endif //UNTITLED6_FILMEKLE_H
