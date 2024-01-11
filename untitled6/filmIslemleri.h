//
// Created by Zeki Furkan Durum on 11.01.2024.
//

#ifndef UNTITLED6_FILMISLEMLERI_H
#define UNTITLED6_FILMISLEMLERI_H

#include "veritabani.h"

void veritabaniOlustur(struct Veritabani *vt);
void filmEkle(struct Veritabani *vt);
void filmListele(struct Veritabani vt);
void filmDuzenle(struct Veritabani *vt);
void filmSil(struct Veritabani *vt);
void filmAra(struct Veritabani vt);
void filmYonetmeneGoreListele(struct Veritabani vt);
void filmYilaGoreListele(struct Veritabani vt);
void filmAraTur(struct Veritabani vt);
void cevirici(char *str);


#endif //UNTITLED6_FILMISLEMLERI_H
