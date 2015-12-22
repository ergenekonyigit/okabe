#include <iostream>
#include <string>

#include "yazilim.h"
#include "veri/veritabani.h"


using namespace std;

Yazilim::Yazilim()
{
  this->vt = new Veritabani;
  testVeri();
}

void Yazilim::urunEklemeIslemi()
{
  string urunAdi;
  int kategoriKodu;
  cout << "Urun Adini Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, urunAdi);
  cout << "Kategori Kodunu Giriniz : ";
  cin >> kategoriKodu;

  try {
    this->vt->urunEkle(urunAdi, kategoriKodu);
    cout << "Urun Eklendi!" << endl;
    cout << urunAdi << " icin urun kodu : " << vt->getU_urunKodu() - 1 << endl;
    cout << "Girilen kategori : " << vt->kategoriBul(kategoriKodu)->getKategoriAdi() << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::urunSilmeIslemi()
{
  int urunKodu;
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;

  try {
    this->vt->urunSil(urunKodu);
    cout << "Basarili!" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::urunDuzenlemeIslemi()
{
  int urunKodu;
  string urunAdi;
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;
  cout << "Yeni Urun Adini Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, urunAdi);
  Urun *urun = vt->urunBul(urunKodu);
  urun->setUrunAdi(urunAdi);
  vt->urunGuncelle(urunKodu, urun);
  cout << "Basarili!" << endl;
}

void Yazilim::urunListelemeIslemi()
{
  cout << "Urun Adi" << '\t' << '\t' << "Urun Kodu"     << endl;
  cout << "───────────────────────────────────────────" << endl;
  UrunVektoru urunler = vt->tumUrunler();
  for (unsigned int i = 0; i < urunler.size(); i++) {
      cout << urunler[i]->getUrunAdi() << '\t' << '\t' << urunler[i]->getUrunKodu() << endl;
    }
  cout << "───────────────────────────────────────────" << endl;
  cout << "Toplam Urun Sayisi : " << urunler.size() << endl;
}

void Yazilim::adaGoreUrunBulmaIslemi()
{
  string urunAdi;
  cout << "Anahtar Metni Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, urunAdi);

  UrunVektoru sonuc = this->vt->adaGoreUrunAra(urunAdi);

  cout << "Urun Kodu" << '\t' << '\t' << "Urun Adi"     << endl;
  cout << "───────────────────────────────────────────" << endl;
  for (UrunGezgini i = sonuc.begin(); i != sonuc.end(); i++) {
      Urun *urun_i = *i;
      cout << urun_i->getUrunKodu() << '\t' << '\t' << '\t' << urun_i->getUrunAdi() << endl;
    }
  cout << "───────────────────────────────────────────" << endl;
  cout << "Toplam Urun Sayisi : " << sonuc.size() << endl;
}

void Yazilim::kodaGoreUrunBulmaIslemi()
{
  int urunKodu;
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;

  try {
    Urun* urun = this->vt->urunBul(urunKodu);

    cout << "Urun Kodu" << '\t' << '\t' << "Urun Adi"     << endl;
    cout << "───────────────────────────────────────────" << endl;
    cout << urun->getUrunKodu() << '\t' << '\t' << '\t' << urun->getUrunAdi() << endl;
    cout << "───────────────────────────────────────────" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::kategoriEklemeIslemi()
{
  string kategoriAdi;
  cout << "Kategori Adini Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, kategoriAdi);

  try {
    this->vt->kategoriEkle(kategoriAdi);
    cout << "Kategori Eklendi!" << endl;
    cout << kategoriAdi << " icin kategori kodu : " << vt->getU_kategoriKodu() - 1 << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::kategoriSilmeIslemi()
{
  int kategoriKodu;
  cout << "Kategori Kodunu Giriniz : ";
  cin >> kategoriKodu;

  try {
    this->vt->kategoriSil(kategoriKodu);
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::kategoriDuzenlemeIslemi()
{
  int kategoriKodu;
  string kategoriAdi;
  cout << "Kategori Kodunu Giriniz : ";
  cin >> kategoriKodu;
  cout << "Yeni Kategori Adini Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, kategoriAdi);
  Kategori *kategori = vt->kategoriBul(kategoriKodu);
  kategori->setKategoriAdi(kategoriAdi);
  vt->kategoriGuncelle(kategoriKodu, kategori);
  cout << "Basarili!" << endl;
}

void Yazilim::kategoriListelemeIslemi()
{
  cout << "         Tum Kategorilerin Listesi         " << endl;
  cout << "───────────────────────────────────────────" << endl;
  cout << "Kategori Adi" << '\t' << '\t' << "Kategori Kodu"     << endl;
  cout << "───────────────────────────────────────────" << endl;
  KategoriVektoru kategoriler =  vt->tumKategoriler();
  for (unsigned int i = 0; i < kategoriler.size(); i++) {
      cout << kategoriler[i]->getKategoriAdi() << '\t' << '\t' << '\t' << kategoriler[i]->getKategoriKodu() << endl;
    }
  cout << "───────────────────────────────────────────" << endl;
  cout << "Toplam Kategori Sayisi : " << kategoriler.size() << endl;
}

void Yazilim::kategoriUrunleriListelemeIslemi(int kategoriKodu)
{
  cout << "          Kategorideki Tum Urunler         " << endl;
  cout << "───────────────────────────────────────────" << endl;
  cout << "Urun Adi" << '\t' << '\t' << "Urun Kodu"     << endl;
  cout << "───────────────────────────────────────────" << endl;
  UrunVektoru urunler =  vt->kategoriUrunleri(kategoriKodu);
  for (unsigned int i = 0; i < urunler.size(); i++) {
      cout << urunler[i]->getUrunAdi() << '\t' << '\t' << '\t' << urunler[i]->getUrunKodu() << endl;
    }
  cout << "───────────────────────────────────────────" << endl;
  cout << "Toplam Urun Sayisi : " << urunler.size() << endl;
}

void Yazilim::adaGoreKategoriBulmaIslemi()
{
  string kategoriAdi;
  cout << "Anahtar metni Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, kategoriAdi);

  KategoriVektoru sonuc = this->vt->adaGoreKategoriAra(kategoriAdi);

  if (sonuc.size() == 0) {
      cout << "Kategori bulunamadi. Tam adi giriniz." << endl;
    }
  else {
      cout << "Kategori Kodu" << '\t' << '\t' << "Kategori Adi" << endl;
      cout << "───────────────────────────────────────────" << endl;
      for (KategoriGezgini i = sonuc.begin(); i != sonuc.end(); i++) {
          Kategori *kategori_i = *i;
          cout << kategori_i->getKategoriKodu() << '\t' << '\t' << kategori_i->getKategoriAdi() << endl;
        }
      cout << "───────────────────────────────────────────" << endl;
      cout << "Toplam Kategori Sayisi : " << sonuc.size() << endl;
    }
}

void Yazilim::kodaGoreKategoriBulmaIslemi()
{
  int kategoriKodu;
  cout << "Kategori Kodunu Giriniz : ";
  cin >> kategoriKodu;

  try {
    Kategori* kategori = this->vt->kategoriBul(kategoriKodu);

    cout << "Kategori Kodu" << '\t' << '\t' << "Kategori Adi" << endl;
    cout << "───────────────────────────────────────────" << endl;
    cout << kategori->getKategoriKodu() << '\t' << '\t' << '\t' << kategori->getKategoriAdi() << endl;
    cout << "───────────────────────────────────────────" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::alisEklemeIslemi()
{
  string alisTarihi;
  float alisFiyati;
  int urunKodu, alisAdeti;
  cout << "Alis Tarihini Giriniz (YilAyGun Seklinde Yaziniz) : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, alisTarihi);
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;
  cout << "Alis Fiyatini Giriniz : ";
  cin >> alisFiyati;
  cout << "Alis Adetini Giriniz : ";
  cin >> alisAdeti;

  try {
    this->vt->alisEkle(urunKodu, alisTarihi, alisFiyati, alisAdeti);
    cout << "Basarili!" << endl;
    cout << "Alis kodu : " << vt->getU_alisKodu() - 1 << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::alisSilmeIslemi()
{
  int alisKodu;
  cout << "Alis Kodunu Giriniz : ";
  cin >> alisKodu;

  try {
    this->vt->alisSil(alisKodu);
    cout << "Basarili!";
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::alisDuzenlemeIslemi()
{
  alisSilmeIslemi();
  alisEklemeIslemi();
}

void Yazilim::alisListelemeIslemi()
{
  cout << "                 Tum Alislar               " << endl;
  cout << "───────────────────────────────────────────" << endl;
  cout << "Alis" << '\t' << "Urun   " << '\t' << "Fiyat" << '\t' << "Adet" << '\t' << "Tarih" << endl;
  AlisVektoru alislar =  vt->tumAlislar();
  for (unsigned int i = 0; i < alislar.size(); i++) {
      cout << alislar[i]->getAlisKodu() <<
              '\t' << vt->urunBul(alislar[i]->getUrunKodu())->getUrunAdi() <<
              '\t' << alislar[i]->getAlisFiyati() <<
              '\t' << alislar[i]->getAlisAdeti() <<
              '\t' << alislar[i]->getAlisTarihi() <<
              endl;
    }
  cout << "───────────────────────────────────────────" << endl;
  cout << "Toplam Alis Sayisi : " << alislar.size() << endl;
  cout << "Toplam Alis Miktari : " << toplamAlisMiktariHesaplama() << endl;
  cout << "Toplam Alis Fiyati : " << toplamAlisFiyatiHesaplama() <<endl;
}

void Yazilim::kodaGoreAlisBulmaIslemi()
{
  int alisKodu;
  cout << "Alis Kodunu Giriniz : ";
  cin >> alisKodu;

  try {
    Alis* alis = this->vt->alisBul(alisKodu);

    cout << "Alis Kodu" << '\t' << '\t' << "Alis Adi"     << endl;
    cout << "───────────────────────────────────────────" << endl;
    cout << alis->getAlisKodu() << '\t' << '\t' << '\t' << alis->getUrunKodu() << endl;
    cout << "───────────────────────────────────────────" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::satisEklemeIslemi()
{
  string satisTarihi;
  float satisFiyati;
  int urunKodu, satisAdeti;
  cout << "Satis Tarihini Giriniz (YilAyGun Seklinde Yaziniz) : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, satisTarihi);
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;
  cout << "Satis Fiyatini Giriniz : ";
  cin >> satisFiyati;
  cout << "Satis Adetini Giriniz : ";
  cin >> satisAdeti;

  try {
    this->vt->satisEkle(urunKodu, satisTarihi, satisFiyati, satisAdeti);
    cout << "Basarili!" << endl;
    cout << "Satis kodu : " << vt->getU_satisKodu() - 1 << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::satisSilmeIslemi()
{
  int satisKodu;
  cout << "Satis Kodunu Giriniz : ";
  cin >> satisKodu;

  try {
    this->vt->satisSil(satisKodu);
    cout << "Basarili!";
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::satisDuzenlemeIslemi()
{
  satisSilmeIslemi();
  satisEklemeIslemi();
}

void Yazilim::satisListelemeIslemi()
{
  cout << "                Tum Satislar               " << endl;
  cout << "───────────────────────────────────────────" << endl;
  cout << "Satis" << '\t' << "Urun   " << '\t' << "Fiyat" << '\t' << "Adet" << '\t' << "Tarih" << endl;
  SatisVektoru satislar = vt->tumSatislar();
  for (unsigned int i = 0; i < satislar.size(); i++) {
      cout << satislar[i]->getSatisKodu() <<
              '\t' << vt->urunBul(satislar[i]->getUrunKodu())->getUrunAdi() <<
              '\t' << satislar[i]->getSatisFiyati() <<
              '\t' << satislar[i]->getSatisAdeti() <<
              '\t' << satislar[i]->getSatisTarihi() <<
              endl;
    }
  cout << "───────────────────────────────────────────" << endl;
  cout << "Toplam Satis Sayisi : " << satislar.size() << endl;
  cout << "Toplam Satis Miktari : " << toplamSatisMiktariHesaplama() << endl;
  cout << "Toplam Satis Fiyati : " << toplamSatisFiyatiHesaplama() <<endl;
}

void Yazilim::kodaGoreSatisBulmaIslemi()
{
  int satisKodu;
  cout << "Satis Kodunu Giriniz : ";
  cin >> satisKodu;

  try {
    Satis* satis = this->vt->satisBul(satisKodu);

    cout << "Alis Kodu" << '\t' << '\t' << "Alis Adi"     << endl;
    cout << "───────────────────────────────────────────" << endl;
    cout << satis->getSatisKodu() << '\t' << '\t' << satis->getUrunKodu() << endl;
    cout << "───────────────────────────────────────────" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

float Yazilim::gunlukKarHesabi(string tarih)
{
  float alisToplami = 0, satisToplami = 0, kar = 0;
  for (unsigned int i = 0; i < vt->tumAlislar().size(); i++) {
      if (vt->tumAlislar()[i]->getAlisTarihi() == tarih) {
          alisToplami += vt->tumAlislar()[i]->getAlisFiyati() * vt->tumAlislar()[i]->getAlisAdeti();
        }
    }
  for (unsigned int i = 0; i < vt->tumSatislar().size(); i++) {
      if (vt->tumSatislar()[i]->getSatisTarihi() == tarih) {
          satisToplami += vt->tumSatislar()[i]->getSatisFiyati() * vt->tumSatislar()[i]->getSatisAdeti();
        }
    }
  kar = satisToplami - alisToplami;
  return kar;
}

float Yazilim::toplamAlisMiktariHesaplama()
{
  float sonuc = 0;
  for (unsigned int i = 0; i < vt->tumAlislar().size(); i++) {
      sonuc += vt->tumAlislar()[i]->getAlisAdeti();
    }
  return sonuc;
}

float Yazilim::toplamAlisFiyatiHesaplama()
{
  float sonuc = 0;
  for (unsigned int i = 0; i < vt->tumAlislar().size(); i++) {
      sonuc += vt->tumAlislar()[i]->getAlisFiyati() * vt->tumAlislar()[i]->getAlisAdeti();
    }
  return sonuc;
}

float Yazilim::toplamSatisMiktariHesaplama()
{
  float sonuc = 0;
  for (unsigned int i = 0; i < vt->tumSatislar().size(); i++) {
      sonuc += vt->tumSatislar()[i]->getSatisAdeti();
    }
  return sonuc;
}

float Yazilim::toplamSatisFiyatiHesaplama()
{
  float sonuc = 0;
  for (unsigned int i = 0; i < vt->tumSatislar().size(); i++) {
      sonuc += vt->tumSatislar()[i]->getSatisFiyati() * vt->tumSatislar()[i]->getSatisAdeti();
    }
  return sonuc;
}

float Yazilim::kategoriToplamAlisMiktariHesaplama(int kategoriKod)
{
  float sonuc = 0;
  for (unsigned int i = 0; i < vt->tumAlislar().size(); i++) {
      for (unsigned j = 0;
           j < vt->kategoriUrunleri(kategoriKod).size();
           j++) {
          if (vt->kategoriUrunleri(kategoriKod)[j]->getUrunKodu() == vt->tumAlislar()[i]->getUrunKodu()) {
              sonuc += vt->tumAlislar()[i]->getAlisAdeti();
            }
        }
    }
  return sonuc;
}

float Yazilim::kategoriToplamSatisMiktariHesaplama(int kategoriKod)
{
  float sonuc = 0;
  for (unsigned int i = 0; i < vt->tumSatislar().size(); i++) {
      for (unsigned j = 0;
           j < vt->kategoriUrunleri(kategoriKod).size();
           j++) {
          if (vt->kategoriUrunleri(kategoriKod)[j]->getUrunKodu() == vt->tumSatislar()[i]->getUrunKodu()) {
              sonuc += vt->tumSatislar()[i]->getSatisAdeti();
            }
        }
    }
  return sonuc;
}

float Yazilim::kategoriToplamAlisFiyatiHesaplama(int kategoriKod)
{
  float sonuc = 0;
  for (unsigned int i = 0; i < vt->tumAlislar().size(); i++) {
      for (unsigned j = 0;
           j < vt->kategoriUrunleri(kategoriKod).size();
           j++) {
          if (vt->kategoriUrunleri(kategoriKod)[j]->getUrunKodu() == vt->tumAlislar()[i]->getUrunKodu()) {
              sonuc += vt->tumAlislar()[i]->getAlisAdeti() * vt->tumAlislar()[i]->getAlisFiyati();
            }
        }
    }
  return sonuc;
}

float Yazilim::kategoriToplamSatisFiyatiHesaplama(int kategoriKod)
{
  float sonuc = 0;
  for (unsigned int i = 0; i < vt->tumSatislar().size(); i++) {
      for (unsigned j = 0;
           j < vt->kategoriUrunleri(kategoriKod).size();
           j++) {
          if (vt->kategoriUrunleri(kategoriKod)[j]->getUrunKodu() == vt->tumSatislar()[i]->getUrunKodu()) {
              sonuc += vt->tumSatislar()[i]->getSatisAdeti() * vt->tumSatislar()[i]->getSatisFiyati();
            }
        }
    }
  return sonuc;
}

float Yazilim::kategoriKarHesaplama(int kategoriKodu)
{
  return kategoriToplamSatisFiyatiHesaplama(kategoriKodu) - kategoriToplamAlisFiyatiHesaplama(kategoriKodu);
}

void Yazilim::testVeri()
{
    vt->kategoriEkle("Cep Telefonu");
    vt->kategoriEkle("Bilgisayar");
    vt->kategoriEkle("Tablet");
    vt->kategoriEkle("Kulaklik");
    vt->kategoriEkle("Aksesuar");

    vt->urunEkle("iPhone 5S", 1);
    vt->urunEkle("iPhone 6", 1);
    vt->urunEkle("iPhone 6S", 1);
    vt->urunEkle("Macbook Air", 2);
    vt->urunEkle("Macbook Pro", 2);
    vt->urunEkle("iPad Pro", 3);
    vt->urunEkle("iPad Air 2", 3);
    vt->urunEkle("iPad Mini 4", 3);
    vt->urunEkle("Beats Solo2", 4);
    vt->urunEkle("Beats Pro", 4);
    vt->urunEkle("iPhone Case", 5);
    vt->urunEkle("iPad Case", 5);
    vt->urunEkle("HDMI Cable", 5);
    vt->urunEkle("iPhone Dock", 5);

    vt->alisEkle(1, "20151220", 1500, 800);
    vt->alisEkle(2, "20151220", 2500, 500);
    vt->alisEkle(3, "20151221", 3000, 250);
    vt->alisEkle(4, "20151222", 3500, 150);
    vt->alisEkle(5, "20151222", 5000, 50);
    vt->alisEkle(6, "20151224", 3500, 450);
    vt->alisEkle(7, "20151224", 1500, 850);
    vt->alisEkle(8, "20151225", 1000, 1000);
    vt->alisEkle(9, "20151226", 600, 600);
    vt->alisEkle(10, "20151226", 900, 450);
    vt->alisEkle(11, "20151228", 120, 3000);
    vt->alisEkle(12, "20151228", 200, 1000);
    vt->alisEkle(13, "20151228", 50, 500);
    vt->alisEkle(14, "20151228", 100, 250);

    vt->satisEkle(1, "20151220", 2300, 16);
    vt->satisEkle(2, "20151220", 2700, 19);
    vt->satisEkle(3, "20151221", 3100, 45);
    vt->satisEkle(1, "20151221", 2300, 34);
    vt->satisEkle(2, "20151221", 2700, 12);
    vt->satisEkle(3, "20151222", 3100, 19);
    vt->satisEkle(4, "20151222", 4000, 9);
    vt->satisEkle(5, "20151222", 5300, 4);
    vt->satisEkle(6, "20151224", 4000, 11);
    vt->satisEkle(7, "20151224", 1800, 23);
    vt->satisEkle(8, "20151225", 1300, 49);
    vt->satisEkle(3, "20151226", 3100, 30);
    vt->satisEkle(9, "20151227", 700, 2);
    vt->satisEkle(10, "20151227", 1200, 1);
    vt->satisEkle(11, "20151228", 150, 73);
    vt->satisEkle(12, "20151228", 250, 40);
    vt->satisEkle(2, "20151229", 2700, 14);
    vt->satisEkle(6, "20151230", 4000, 7);
    vt->satisEkle(3, "20151231", 3100, 10);
}


/* ==New Features==
 * haftalik-aylik alis ve satislarin listelenmesi
 */
