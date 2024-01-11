//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_YÖNETMENEGÖRELISTELE_H
#define UNTITLED6_YÖNETMENEGÖRELISTELE_H


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "filmIslemleri.h"
#include "veritabani.h"

// Yönetmene göre filmleri listeleyen fonksiyon
void filmYonetmeneGoreListele(struct Veritabani vt) {
    // Eğer veritabanında hiç film yoksa bilgi ver ve fonksiyondan çık
    if (vt.filmSayisi == 0) {
        printf("Listelenecek film bulunmamaktadir.\n");
        return;
    }

    // Kullanıcıdan listelenecek filmlerin yönetmenini al
    char arananYonetmen[50];
    printf("Listelenecek filmlerin yonetmenini girin: ");
    scanf("%s", arananYonetmen);

    // Arama sorgusunu küçük harfe çevir
    cevirici(arananYonetmen);

    int siraSecim;
    printf("Sıralama secenegi:\n");
    printf("1. A'dan Z'ye\n");
    printf("2. Z'den A'ya\n");
    printf("3. Yila Gore Kucukten Buyuge\n");
    printf("4. Yila Gore Buyukten Kucuge\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &siraSecim);

    // Filmleri yönetmen adına göre ve seçilen sıralama ölçütüne göre listeleyin
    switch (siraSecim) {
        case 1:
            qsort(vt.filmler, vt.filmSayisi, sizeof(struct Film), compareByFilmNameAsc);
            break;
        case 2:
            qsort(vt.filmler, vt.filmSayisi, sizeof(struct Film), compareByFilmNameDesc);
            break;
        case 3:
            qsort(vt.filmler, vt.filmSayisi, sizeof(struct Film), compareByReleaseYearAsc);
            break;
        case 4:
            qsort(vt.filmler, vt.filmSayisi, sizeof(struct Film), compareByReleaseYearDesc);
            break;
        default:
            printf("Gecersiz sıralama secimi. Varsayilan olarak A'dan Z'ye sıralanacak.\n");
            qsort(vt.filmler, vt.filmSayisi, sizeof(struct Film), compareByFilmNameAsc);
    }

    int bulunan = 0;
    for (int i = 0; i < vt.filmSayisi; i++) {
        // Filmin yönetmen adını karşılaştırma için küçük harfe çevir
        char yonetmenLowerCase[50];
        strcpy(yonetmenLowerCase, vt.filmler[i].yonetmen);
        cevirici(yonetmenLowerCase);

        // Eğer film yönetmeni arananla eşleşirse bilgileri ekrana yazdır
        if (strcmp(yonetmenLowerCase, arananYonetmen) == 0) {
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
        printf("Girilen yonetmene ait film bulunamadi.\n");
    }
}
#endif //UNTITLED6_YÖNETMENEGÖRELISTELE_H
