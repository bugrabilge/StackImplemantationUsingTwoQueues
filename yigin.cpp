#include "yigin.h"

void Yigin::olustur() {
    //yığını gerçekleyeceğimiz k1 ve k2 kuyruklarını oluşturuyoruz
    k1.olustur();
    k2.olustur();
}

void Yigin::kapat() {
    //k1 ve k2 kuyruklarının bellek iadelerini yapıyoruz
    k1.kapat();
    k2.kapat();
}

void Yigin::ekle(int eklenecekEleman) {
    //eklenecekEleman'ı önce boş olan k2ye ekliyoruz
    k2.ekle(eklenecekEleman);

    //k1'deki tüm elemanları k2'ye ekliyoruz ve k1'i boşaltıyoruz
    //böylece k1'deki elemanlar eklenecekEleman'ın arkasına sıralanıyor
    while (!k1.bosMu()){
        k2.ekle(k1.bas->veri);
        k1.cikar();
    }
    //son olarak k2 ile k1'in isimlerini değiştiriyoruz
    //böylece k2 boş halde tekrar kullanıma hazır duruma geliyor
    Kuyruk q = k1;
    k1 = k2;
    k2 = q;
}

int Yigin::cikar() {
    if (k1.bosMu())
        return -1;

    //yığının elemanlarını tuttuğumuz k1 kuyruğunun
    //baş elemanını çıkarıyoruz
    return k1.cikar();
}

bool Yigin::bosMu() {
    //yığının elemanlarını tuttuğumuz k1 kuyruğunun kontrolünü yapıyoruz
    return k1.bosMu();
}

int Yigin::tepe() {
    if (k1.bosMu())
        return -1;

    //tepe elemanı yani yığının elemanlarını tuttuğumuz k1 kuyruğunun,
    //baş elemanının verisini döndürüyoruz
    return  k1.bas->veri;
}

void Yigin::yazdir() {
    Dugum* tara;
    tara = k1.bas;
    if (!tara){
        cout << "Liste boş!" << endl;
        return;
    }
    while (tara){//bas düğümden başlayarak tüm elemanları yazdırıyoruz
        cout << tara->veri << " ";
        tara = tara->sonraki;
    }
    cout << endl;
}