#include "arayuz.h"

#include <iostream>
#include "yazilim.h"

using namespace std;

Arayuz::Arayuz()
{
  this->yz = new Yazilim;
  anaMenuListe();
  anaMenuSecim();
}

void Arayuz::anaMenuListe()
{
  system("clear");
  cout << "         Okabe Stok Kontrol Yazılımı        " << endl;
  cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
  cout << " ( 1 )  Ürünler                             " << endl;
  cout << " ( 2 )  Kategoriler                         " << endl;
  cout << " ( 3 )  Alışlar                             " << endl;
  cout << " ( 4 )  Satışlar                            " << endl;
  cout << " ( 0 )  Çıkış                               " << endl;
}

void Arayuz::anaMenuSecim()
{
  int secim;
  do {
      cout << "Seçiminiz:";
      cin >> secim;
    } while (secim < 0 || secim > 4);

  switch (secim) {
    case Cikis:
      cout << "Çıkılıyor";
      break;
    case Urunler:
      urunMenuListe();
      urunMenuSecim();
      break;
    case Kategoriler:
      kategoriMenuListe();
      kategoriMenuSecim();
      break;
    case Alislar:
      alisMenuListe();
      alisMenuSecim();
      break;
    case Satislar:
      satisMenuSecim();
      satisMenuSecim();
      break;
    default:
      break;
    }
}

void Arayuz::urunMenuListe()
{
  system("clear");
  cout << "         Okabe Stok Kontrol Yazılımı        " << endl;
  cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
  cout << " ( 1 )  Yeni Urun                           " << endl;
  cout << " ( 2 )  Ada Gore Urun Ara                   " << endl;
  cout << " ( 3 )  Koda Gore Urun Ara                  " << endl;
  cout << " ( 4 )  Urunleri Listele                    " << endl;
  cout << " ( 5 )  Urun Sil                            " << endl;
  cout << " ( 6 )  Urun Duzenle                        " << endl;
  cout << " ( 0 )  Ana Menu                            " << endl;
}

void Arayuz::urunMenuSecim()
{
  int secim;
  do {
      cout << "Seçiminiz:";
      cin >> secim;
    } while (secim < 0 || secim > 4);

  switch (secim) {
    case UrunAnaMenu:
      anaMenuListe();
      anaMenuSecim();
      break;
    case YeniUrun:
      yz->urunEklemeIslemi();
      break;
    case AdaGoreUrunAra:
      yz->adaGoreUrunBulmaIslemi();
      break;
    case KodaGoreUrunAra:
      yz->kodaGoreUrunBulmaIslemi();
      break;
    case UrunleriListele:
      yz->urunListelemeIslemi();
      break;
    case UrunSil:
      yz->urunSilmeIslemi();
      break;
    case UrunDuzenle:
      yz->urunDuzenlemeIslemi();
      break;
    default:
      break;
    }
}

void Arayuz::kategoriMenuListe()
{
  system("clear");
  cout << "         Okabe Stok Kontrol Yazılımı        " << endl;
  cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
  cout << " ( 1 )  Yeni Kategori                       " << endl;
  cout << " ( 2 )  Ada Gore Kategori Ara               " << endl;
  cout << " ( 3 )  Koda Gore Urun Ara                  " << endl;
  cout << " ( 4 )  Kategorileri Listele                " << endl;
  cout << " ( 5 )  Kategori Sil                        " << endl;
  cout << " ( 6 )  Kategori Duzenle                    " << endl;
  cout << " ( 0 )  Ana Menu                            " << endl;
}

void Arayuz::kategoriMenuSecim()
{

}

void Arayuz::alisMenuListe()
{
  system("clear");
  cout << "         Okabe Stok Kontrol Yazılımı        " << endl;
  cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
  cout << " ( 1 )  Alis ekle                           " << endl;
  cout << " ( 2 )  Alislari listele                    " << endl;
  cout << " ( 3 )  Alis sil                            " << endl;
  cout << " ( 4 )  Alis duzenle                        " << endl;
  cout << " ( 5 )  Alis bul (koda gore)                " << endl;
  cout << " ( 0 )  Ana Menu                            " << endl;
}

void Arayuz::alisMenuSecim()
{

}

void Arayuz::satisMenuListe()
{
  system("clear");
  cout << "         Okabe Stok Kontrol Yazılımı        " << endl;
  cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
  cout << " ( 1 )  Satis ekle                          " << endl;
  cout << " ( 2 )  Satislari listele                   " << endl;
  cout << " ( 3 )  Satis sil                           " << endl;
  cout << " ( 4 )  Satis duzenle                       " << endl;
  cout << " ( 5 )  Alis bul (koda göre)                " << endl;
  cout << " ( 0 )  Ana Menu                            " << endl;
}

void Arayuz::satisMenuSecim()
{

}



