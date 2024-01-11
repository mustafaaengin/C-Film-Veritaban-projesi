cmake_minimum_required(VERSION 3.26)
project(untitled6 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled6 main.c
        veritabani.h
        filmIslemleri.h
        dosya_Islemleri.h
        filmListele.h
        veritabaniOlusturma.h
        filmEkle.h
        filmKontrol.h
        filmDüzenle.h
        filmSil.h
        filmAra.h
        yönetmeneGöreListele.h
        ismeGöreA_Z.h
        ismeGöreZ-A.h
        yilaGoreK-B.h
        yilaGoreB-K.h
        filmYilaGoreListele.h
        tureGoreAra.h
        dosyayaYaz.h
        dosyadanOku.h
)
