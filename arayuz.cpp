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
  cout << " ( 3 )  Koda Gore Urun Ar                   " << endl;
  cout << " ( 4 )  Urunleri Listele                    " << endl;
  cout << " ( 5 )  Urun Sil                            " << endl;
  cout << " ( 6 )  Urun Duzenle                        " << endl;
  cout << " ( 1 )  Ana Menu                            " << endl;
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

}

void Arayuz::kategoriMenuSecim()
{

}

void Arayuz::alisMenuListe()
{

}

void Arayuz::alisMenuSecim()
{

}

void Arayuz::satisMenuListe()
{

}

void Arayuz::satisMenuSecim()
{

}



