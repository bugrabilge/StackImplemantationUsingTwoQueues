#include "kuyruk.h"

void Kuyruk::olustur() {
    bas = NULL;
    son = NULL;
}

void Kuyruk::kapat() {
    Dugum *p;
    //baştan sonraki düğümü baş yapıp
    //boşta kalan eski baş düğümünü(p) sile sile
    //tüm kuyruğun belleğini iade ediyoruz
    while (bas){
        p = bas;
        bas = bas->sonraki;
        delete p;
    }
}

void Kuyruk::ekle(int yeni) {
    Dugum *yeniDugum = new Dugum;
    yeniDugum->veri = yeni;
    yeniDugum->sonraki = NULL;
    if (!bas){ //kuyruk boşsa başa yeni düğümü ekliyoruz
        bas = yeniDugum;
        son = bas;
    } else{ //kuyruk boş değilse sona yeni düğümü ekliyoruz
        son->sonraki = yeniDugum;
        son = yeniDugum;
    }
}

int Kuyruk::cikar() {
    Dugum *ustDugum;
    int temp;
    //baştan sonraki düğümü baş yapıp,
    //boşta kalan eski baş düğümünü(ustDugum) siliyoruz
    ustDugum = bas;
    bas = bas->sonraki;
    temp = ustDugum->veri;
    delete ustDugum;
    return temp;
}

bool Kuyruk::bosMu() {
    //bas NULL'a eşitse yani kuyruğun elemanı yoksa true dönüyor
    return bas == NULL;
}