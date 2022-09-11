#ifndef VERIYAPILARIODEV2_YIGIN_H
#define VERIYAPILARIODEV2_YIGIN_H
#include <iostream>
#include "kuyruk.h"
using namespace std;

struct Yigin{
    Kuyruk k1, k2; //yığın için kullanılacak kuyruk değişkenleri
    void olustur(); //başlangıç için gereken tanımları içerir
    void kapat(); //program bitiminde bellek iadesi yapar
    void ekle(int); //kuyruğa yeni veri ekler
    int cikar(); //kuyruktan siradaki elemani cikarir
    bool bosMu(); //kuyruk boş mu kontrol eder
    int tepe(); //yığının tepesindeki elemanı okur
    void yazdir(); //yığın elemanlarını sırayla ekrana yazar
};

#endif //VERIYAPILARIODEV2_YIGIN_H