//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef VERITABANI_H
#define VERITABANI_H

struct Film {
    char ad[50];
    char yonetmen[50];
    int yil;
    char tur[50];
};

struct Veritabani {
    struct Film *filmler;
    int filmSayisi;
};

#endif // VERITABANI_H
