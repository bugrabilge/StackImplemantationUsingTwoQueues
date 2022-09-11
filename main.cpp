#include <iostream>
#include "yigin.h"

using namespace std;

void siraliEkle(Yigin *s, int x){
    //yığın boşsa veya eklenecek deger tepe değerinden büyükse,
    //yığının başına yani tepesine ekliyoruz ve dönüyoruz
    if (s->bosMu() || x > s->tepe()){
        s->ekle(x);
        return;
    }
    //yığın boş değilse ve eklenecek değer tepe değerinden büyük değilse
    int temp = s->cikar(); //tepe değerini gecici bir değikene çıkarıp
    siraliEkle(s, x); //bulunduğumuz fonksiyonu tekrar çağırıyoruz

    s->ekle(temp); //son olarak geçici değişkene çıkardığımız değeri tekrar ekliyoruz
}

void yiginCikar(Yigin *s){
    //yigin boş degilse
    if (!s->bosMu()){
        //tepedeki elemanı cikarıyoruz
        int x = s->cikar();
        //yiginCikar fonksiyonunu geriye kalan elemanlar için tekrar çağırıyoruz
        yiginCikar(s);

        siraliEkle(s, x);
    }
}

int main() {
    Yigin kullanilacakYigin;
    kullanilacakYigin.olustur();

    //elemanlar ekleniyor
    kullanilacakYigin.ekle(3);
    kullanilacakYigin.ekle(1);
    kullanilacakYigin.ekle(7);
    kullanilacakYigin.ekle(4);
    kullanilacakYigin.ekle(8);

    //yığın yazdırılıyor
    cout << "Orijinal Yigin:" << endl;
    kullanilacakYigin.yazdir();

    //yiginCikar fonksiyonunu çağırıyoruz
    cout << endl << "---yiginCikar fonksiyon cagrisi---" << endl << endl;
    yiginCikar(&kullanilacakYigin);

    //yığını tekrar yazdırıyoruz
    kullanilacakYigin.yazdir();

    //bellek iadelerini gerçekleştiriyoruz
    kullanilacakYigin.kapat();
    return 0;
}
