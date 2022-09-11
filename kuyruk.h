#ifndef VERIYAPILARIODEV2_KUYRUK_H
#define VERIYAPILARIODEV2_KUYRUK_H
#include <iostream>
using namespace std;

struct Dugum{
    int veri; //dügümün sayisal degeri
    Dugum* sonraki; //sonraki dügüme isaretci
};

struct Kuyruk{
    Dugum* bas; //kuyruğun başındaki elemanın adresini tutar
    Dugum* son; //kuyruğun sonundaki elemanın adresini tutar
    void olustur(); //başlangıç için gereken tanımları içerir
    void kapat(); //program bitiminde bellek iadesi yapar
    void ekle(int); //kuyruğa yeni veri ekler
    int cikar(); //kuyruktan sıradaki elemanı çıkarır
    bool bosMu(); //kuyruk boş mu kontrol eder
};

#endif //VERIYAPILARIODEV2_KUYRUK_H
