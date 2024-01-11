//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_FILMKONTROL_H
#define UNTITLED6_FILMKONTROL_H


#include <string.h>
#include "veritabani.h"

int filmKontrol(struct Veritabani vt, struct Film newFilm) {
    // Fonksiyon, veritabanında aynı film bilgilerine sahip başka bir film varsa 1, aksi halde 0 döndürür.

    for (int i = 0; i < vt.filmSayisi; i++) {
        if (strcmp(vt.filmler[i].ad, newFilm.ad) == 0 &&
            strcmp(vt.filmler[i].yonetmen, newFilm.yonetmen) == 0 &&
            vt.filmler[i].yil == newFilm.yil) {
            return 1; // Aynı film bulundu
        }
    }
    return 0; // Aynı film bulunamadı
}

#endif //UNTITLED6_FILMKONTROL_H
