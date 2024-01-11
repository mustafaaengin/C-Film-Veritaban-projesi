#include <stdio.h>
#include <stdlib.h>
#include "dosya_Islemleri.h"
#include "filmListele.h"
#include "dosyadanOku.h"
#include "dosyayaYaz.h"
#include "filmAra.h"
#include "filmDüzenle.h"
#include "filmEkle.h"
#include "filmIslemleri.h"
#include "filmSil.h"
#include "filmYilaGoreListele.h"
#include "ismeGöreA_Z.h"
#include "ismeGöreZ-A.h"
#include "tureGoreAra.h"
#include "veritabaniOlusturma.h"
#include "yilaGoreK-B.h"
#include "yilaGoreB-K.h"
#include "yönetmeneGöreListele.h"





int main() {
    struct Veritabani vt;
    vt.filmler = NULL;
    vt.filmSayisi = 0;

    char dosyaAdi[100];
    int onay = 0;

    for (int i = 0; i<1;i++ ) {
        printf("Lutfen dosyanızın adini girin yoksa oluşturmak istediğiniz dosyanın adını girin: ");
        scanf("%s", dosyaAdi);
        for (int k = 0; k<1;k++) {
            // Dosya adını onaylat
            printf("Girdiginiz dosya adi: %s\n", dosyaAdi);
            printf("Emin misiniz? (1:Evet / 2: Hayır): ");
            scanf("%d", &onay);

            if(onay == 1){
                i++;
                k++;
            }
            if (onay == 2) {
                printf("Dosya adi tekrar istenecek.\n");
                onay = 0;
                i--;
            } else {
                k--;
            }
        }
    }


    // Dosyadan okuma
    dosyadanOku(&vt, dosyaAdi);

    veritabaniOlustur(&vt);

    int secim;
    do {
        printf("\n----- Menu -----\n");
        printf("1. Film Ekle\n");
        printf("2. Filmleri Listele\n");
        printf("3. Film Duzenle\n");
        printf("4. Film Ara\n");
        printf("5. Film Sil\n");
        printf("6. Yonetmene Gore Filmleri Listele\n");
        printf("7. Yila Gore Filmleri Listele\n");
        printf("8. türüne Gore Filmleri Listele\n");
        printf("9. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                filmEkle(&vt);
                break;
            case 2:
                filmListele(vt);
                break;
            case 3:
                filmDuzenle(&vt);
                break;
            case 4:
                filmAra(vt);
                break;
            case 5:
                filmSil(&vt);
                break;
            case 6:
                filmYonetmeneGoreListele(vt);
                break;
            case 7:
                filmYilaGoreListele(vt);
                break;
            case 8:
                filmAraTur(vt);
                break;
            case 9:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } while (secim != 9);

    dosyayaYaz(vt, dosyaAdi);

    // Bellek temizleme
    free(vt.filmler);

    return 0;
}

void cevirici(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // ASCII'de büyük harfi küçüğe dönüştürmek için 32 ekler
        }
        i++;
    }
}

