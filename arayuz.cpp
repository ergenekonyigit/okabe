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
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Okabe Stok Kontrol Yazılımı        │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│  1  ▸  Ürünler                            │" << endl;
  cout << "│  2  ▸  Kategoriler                        │" << endl;
  cout << "│  3  ▸  Alışlar                            │" << endl;
  cout << "│  4  ▸  Satışlar                           │" << endl;
  cout << "│  5  ▸  Hakkında                           │" << endl;
  cout << "│  0  ▸  Çıkış                              │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::anaMenuSecim()
{
  int secim;
  do {
      cout << "Seçiminiz:";
      cin >> secim;
    } while (secim < 0 || secim > 5);

  switch (secim) {
    case Cikis:
      cout << "Çıkılıyor..." << endl;
      exit(0);
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
      satisMenuListe();
      satisMenuSecim();
      break;
    case Hakkinda:
      hakkinda();
      return;
      break;
    default:
      break;
    }
  anaMenuSecim();
}

void Arayuz::urunMenuListe()
{
  system("clear");
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Ana Menu  ▸  Urunler               │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│  1  ▸  Yeni Urun                          │" << endl;
  cout << "│  2  ▸  Ada Gore Urun Ara                  │" << endl;
  cout << "│  3  ▸  Koda Gore Urun Ara                 │" << endl;
  cout << "│  4  ▸  Urunleri Listele                   │" << endl;
  cout << "│  5  ▸  Urun Sil                           │" << endl;
  cout << "│  6  ▸  Urun Duzenle                       │" << endl;
  cout << "│  0  ▸  Ana Menu                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::urunMenuSecim()
{
  int secim;
  do {
      cout << "Seçiminiz:";
      cin >> secim;
    } while (secim < 0 || secim > 6);

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
  urunMenuSecim();
}

void Arayuz::kategoriMenuListe()
{
  system("clear");
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Ana Menu  ▸  Kategoriler           │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│  1  ▸  Yeni Kategori                      │" << endl;
  cout << "│  2  ▸  Ada Gore Kategori Ara              │" << endl;
  cout << "│  3  ▸  Koda Gore Urun Ara                 │" << endl;
  cout << "│  4  ▸  Kategorileri Listele               │" << endl;
  cout << "│  5  ▸  Kategori Sil                       │" << endl;
  cout << "│  6  ▸  Kategori Duzenle                   │" << endl;
  cout << "│  0  ▸  Ana Menu                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::kategoriMenuSecim()
{
  int secim;
  do {
      cout << "Seçiminiz:";
      cin >> secim;
    } while (secim < 0 || secim > 6);

  switch (secim) {
    case KategoriAnaMenu:
      anaMenuListe();
      anaMenuSecim();
      break;
    case YeniKategori:
      yz->kategoriEklemeIslemi();
      break;
    case AdaGoreKategoriAra:
      yz->adaGoreKategoriBulmaIslemi();
      break;
    case KodaGoreKategoriAra:
      yz->kodaGoreKategoriBulmaIslemi();
      break;
    case KategoriListele:
      yz->kategoriListelemeIslemi();
      break;
    case KategoriSil:
      yz->kategoriSilmeIslemi();
      break;
    case KategoriDuzenle:
      yz->kategoriDuzenlemeIslemi();
      break;
    default:
      break;
    }
  kategoriMenuSecim();
}

void Arayuz::alisMenuListe()
{
  system("clear");
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Ana Menu  ▸  Alislar               │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│  1  ▸  Alis ekle                          │" << endl;
  cout << "│  2  ▸  Alislari listele                   │" << endl;
  cout << "│  3  ▸  Alis sil                           │" << endl;
  cout << "│  4  ▸  Alis duzenle                       │" << endl;
  cout << "│  5  ▸  Alis bul (koda gore)               │" << endl;
  cout << "│  0  ▸  Ana Menu                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::alisMenuSecim()
{
  int secim;
  do {
      cout << "Seçiminiz:";
      cin >> secim;
    } while (secim < 0 || secim > 5);

  switch (secim) {
    case AlisAnaMenu:
      anaMenuListe();
      anaMenuSecim();
      break;
    case YeniAlis:
      yz->alisEklemeIslemi();
      break;
    case AlisListele:
      yz->alisListelemeIslemi();
      break;
    case AlisSil:
      yz->alisSilmeIslemi();
      break;
    case AlisDuzenle:
      yz->alisDuzenlemeIslemi();
      break;
    case KodaGoreAlisBul:
      yz->kodaGoreAlisBulmaIslemi();
      break;
    default:
      break;
    }
  alisMenuSecim();
}

void Arayuz::satisMenuListe()
{
  system("clear");
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Ana Menu  ▸  Satislar              │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│  1  ▸  Satis ekle                         │" << endl;
  cout << "│  2  ▸  Satislari listele                  │" << endl;
  cout << "│  3  ▸  Satis sil                          │" << endl;
  cout << "│  4  ▸  Satis duzenle                      │" << endl;
  cout << "│  5  ▸  Alis bul (koda göre)               │" << endl;
  cout << "│  0  ▸  Ana Menu                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::satisMenuSecim()
{
  int secim;
  do {
      cout << "Seçiminiz:";
      cin >> secim;
    } while (secim < 0 || secim > 5);

  switch (secim) {
    case SatisAnaMenu:
      anaMenuListe();
      anaMenuSecim();
      break;
    case YeniSatis:
      yz->satisEklemeIslemi();
      break;
    case SatisListele:
      yz->satisListelemeIslemi();
      break;
    case SatisSil:
      yz->satisSilmeIslemi();
      break;
    case SatisDuzenle:
      yz->satisDuzenlemeIslemi();
      break;
    case KodaGoreSatisBul:
      yz->kodaGoreSatisBulmaIslemi();
      break;
    default:
      break;
    }
  satisMenuSecim();
}

void Arayuz::hakkinda()
{
  system("clear");
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Okabe Stok Kontrol Yazılımı        │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│                                           │" << endl;
  cout << "│  https://github.com/ergenekonyigit/okabe  │" << endl;
  cout << "│                                           │" << endl;
  cout << "│         Regaip Ergenekon Yiğit            │" << endl;
  cout << "│           Taha İbrahim Bayram             │" << endl;
  cout << "│                                           │" << endl;
  cout << "│                                           │" << endl;
  cout << "│                Okabe Inc.                 │" << endl;
  cout << "│                                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}


