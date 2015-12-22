#include "arayuz.h"
#include "yazilim.h"

#include <iostream>

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
  cout << "│        Okabe Stok Kontrol Yazilimi        │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│  1  ▸  Urunler                            │" << endl;
  cout << "│  2  ▸  Kategoriler                        │" << endl;
  cout << "│  3  ▸  Alislar                            │" << endl;
  cout << "│  4  ▸  Satislar                           │" << endl;
  cout << "│  5  ▸  Gunluk Kar Hesabi                  │" << endl;
  cout << "│  6  ▸  Kullanim                           │" << endl;
  cout << "│  7  ▸  Hakkinda                           │" << endl;
  cout << "│  0  ▸  Cikis                              │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::anaMenuSecim()
{
  int secim;
  do {
      cout << "Seciminiz : ";
      cin >> secim;
    } while (secim < 0 || secim > 8);

  switch (secim) {
    case Cikis:
      cout << "Cikiliyor..." << endl;
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
    case Kullanim:
      kullanim();
      break;
    case Hakkinda:
      hakkinda();
      return;
      break;
    case Tazele:
      anaMenuListe();
      anaMenuSecim();
      break;
    case GunlukKar:
      gunlukHesapCiktisi();
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
      cout << "Seciminiz : ";
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
  cout << "│  3  ▸  Koda Gore Kategori Ara             │" << endl;
  cout << "│  4  ▸  Kategorileri Listele               │" << endl;
  cout << "│  5  ▸  Kategori Detay                     │" << endl;
  cout << "│  6  ▸  Kategori Sil                       │" << endl;
  cout << "│  7  ▸  Kategori Duzenle                   │" << endl;
  cout << "│  0  ▸  Ana Menu                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::kategoriMenuSecim()
{
  int secim;
  do {
      cout << "Seciminiz : ";
      cin >> secim;
    } while (secim < 0 || secim > 7);

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
    case KategoriDetay:
      kategoriDetayMenuListe();
      int kategoriKodu;
      cout << "Kategori Kodu : ";
      cin >>kategoriKodu;
      kategoriDetayMenuSecim(kategoriKodu);
      break;
    default:
      break;
    }
  kategoriMenuSecim();
}

void Arayuz::kategoriDetayMenuListe()
{
  system("clear");
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Kategoriler  ▸  KategoriDetay      │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│  1  ▸  Urunler                            │" << endl;
  cout << "│  2  ▸  Alislar                            │" << endl;
  cout << "│  3  ▸  Satislar                           │" << endl;
  cout << "│  4  ▸  Kar                                │" << endl;
  cout << "│  5  ▸  Ust Menu                           │" << endl;
  cout << "│  0  ▸  Ana Menu                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::kategoriDetayMenuSecim(int kategoriKodu)
{
  int secim;
  do {
      cout << "Seciminiz : ";
      cin >> secim;
    } while (secim < 0 || secim > 5);

  switch (secim) {
    case KategoriDetayAnaMenu:
      anaMenuListe();
      anaMenuSecim();
      break;
    case KategoriDetayKategoriler:
      kategoriMenuListe();
      kategoriMenuSecim();
      break;
    case KategoriDetayUrunler:
      yz->kategoriUrunleriListelemeIslemi(kategoriKodu);
      break;
    case KategoriDetayToplamAlis:
      cout << "Alis Miktari : "
          << yz->kategoriToplamAlisMiktariHesaplama(kategoriKodu)
          << endl
          << "Alis Fiyati : "
          << yz->kategoriToplamAlisFiyatiHesaplama(kategoriKodu)
          << endl;
      break;
    case KategoriDetayToplamSatis:
      cout << "Satis Miktari : "
          << yz->kategoriToplamSatisMiktariHesaplama(kategoriKodu)
          << endl
          << "Satis Fiyati : "
          << yz->kategoriToplamSatisFiyatiHesaplama(kategoriKodu)
          << endl;
      break;
    case KategoriDetayKar:
      cout << yz->kategoriKarHesaplama(kategoriKodu) << endl;
      break;
    default:
      break;
    }
  kategoriDetayMenuSecim(kategoriKodu);
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
      cout << "Seciminiz : ";
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
  cout << "│  5  ▸  Satis bul (koda göre)              │" << endl;
  cout << "│  0  ▸  Ana Menu                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::satisMenuSecim()
{
  int secim;
  do {
      cout << "Seciminiz : ";
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

void Arayuz::kullanim()
{
  system("clear");
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Okabe Stok Kontrol Yazilimi        │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│                                           │" << endl;
  cout << "│  •  Sorunsuz kullanim icin talimatlari    │" << endl;
  cout << "│           sirasiyla uygulayiniz           │" << endl;
  cout << "│                                           │" << endl;
  cout << "│                                           │" << endl;
  cout << "│  1-)  Kategorileri Ekleyiniz.             │" << endl;
  cout << "│                                           │" << endl;
  cout << "│  2-)  Urunleri Ekleyiniz.                 │" << endl;
  cout << "│                                           │" << endl;
  cout << "│  3-)  Alislari Ekleyiniz.                 │" << endl;
  cout << "│                                           │" << endl;
  cout << "│  4-)  Satislari Ekleyiniz.                │" << endl;
  cout << "│                                           │" << endl;
  cout << "│                                           │" << endl;
  cout << "│  Geribildirim : yigitergenekon@gmail.com  │" << endl;
  cout << "│                                           │" << endl;
  cout << "│                                           │" << endl;
  cout << "│  • Ana Menuye Donmek Icin 8'e basiniz •   │" << endl;
  cout << "│                                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::hakkinda()
{
  system("clear");
  cout << "┌───────────────────────────────────────────┐" << endl;
  cout << "│        Okabe Stok Kontrol Yazilimi        │" << endl;
  cout << "├───────────────────────────────────────────┤" << endl;
  cout << "│                                           │" << endl;
  cout << "│  https://github.com/ergenekonyigit/okabe  │" << endl;
  cout << "│                                           │" << endl;
  cout << "│         Regaip Ergenekon Yigit            │" << endl;
  cout << "│           Taha Ibrahim Bayram             │" << endl;
  cout << "│                                           │" << endl;
  cout << "│                                           │" << endl;
  cout << "│                Okabe Inc.                 │" << endl;
  cout << "│                                           │" << endl;
  cout << "│                                           │" << endl;
  cout << "│  • Ana Menuye Donmek Icin 8'e basiniz •   │" << endl;
  cout << "│                                           │" << endl;
  cout << "└───────────────────────────────────────────┘" << endl;
}

void Arayuz::gunlukHesapCiktisi()
{
  string tarih;
  cout << "Tarihi Giriniz (YilAyGun Seklinde Yaziniz) : ";
  cin >> tarih;
  cout << "Gunluk kar : " << yz->gunlukKarHesabi(tarih) << endl;
}



