#include "veritabani.h"

#include <exception>

void Veritabani::urunEkle(Urun *urun)
{
  u_vektorUrunler.push_back(urun);
}

void Veritabani::urunEkle(string urunAdi, int kategoriKodu)
{
  /*if (u_aramaUrunKodu.count(urunKodu) == 1) {
      throw "Ayni kodlu başka bir ürün var.";
    }*/
  if (u_aramaKategoriKodu.count(kategoriKodu) == 0) {
      throw "Kategori kodu bulunamadi.";
    }

  Urun *urun = new Urun;
  urun->setUrunAdi(urunAdi);
  urun->setUrunKodu(u_urunKodu);

  u_aramaUrunKodu[u_urunKodu] = urun;
  u_aramaUrunAdi.insert(make_pair(urunAdi, urun));
  u_iliskiKategoriUrun.insert(make_pair(u_aramaKategoriKodu[kategoriKodu], urun));
  u_iliskiUrunKategori.insert(make_pair(urun, u_aramaKategoriKodu[kategoriKodu]));
  u_vektorUrunler.push_back(urun);

  u_urunKodu++;
}

void Veritabani::urunSil(int urunKodu)
{
  if (u_aramaUrunKodu.count(urunKodu) == 0) {
      throw "Silinecek ürün bulunamadi.";
    }
  Urun *silinecekUrun = u_aramaUrunKodu[urunKodu];

  for (auto i = u_vektorUrunler.begin();
       i != u_vektorUrunler.end();
       i++) {
      if (*i == silinecekUrun) {
          u_vektorUrunler.erase(i);
          break;
        }
    }
  u_aramaUrunKodu.erase(urunKodu);

  auto adaGoreSilme = u_aramaUrunAdi.equal_range(
        silinecekUrun->getUrunAdi());

  for (auto i = adaGoreSilme.first;
       i != adaGoreSilme.second;
       i++) {
      if (i->second == silinecekUrun) {
          u_aramaUrunAdi.erase(i);
          break;
        }
    }
  delete silinecekUrun;
}

Urun *Veritabani::urunBul(int urunKodu)
{
  if (u_aramaUrunKodu.count(urunKodu) == 0) {
      throw "Ürün bulunamadi.";
    }
  return u_aramaUrunKodu[urunKodu];
}

UrunVektoru Veritabani::adaGoreUrunAra(string urunAdi)
{
  UrunVektoru urunler;
  for (adaGoreUrunGezgini i = u_aramaUrunAdi.begin();
       i != u_aramaUrunAdi.end();
       i++) {
      if (i->second->getUrunAdi().find(urunAdi) != string::npos) {
          urunler.push_back(i->second);
        }
    }
  return urunler;
}

UrunVektoru Veritabani::kategoriUrunleri(int kategoriKodu)
{
  Kategori *kategori = u_aramaKategoriKodu[kategoriKodu];
  UrunVektoru urunler;
  auto iliskiKategoriUrun = u_iliskiKategoriUrun.equal_range(kategori);
  for (auto i = iliskiKategoriUrun.first;
       i != iliskiKategoriUrun.second;
       i++) {
      if (i->first == kategori) {
        urunler.push_back(i->second);
        }
  }
  return urunler;
}

UrunVektoru Veritabani::tumUrunler()
{
  return u_vektorUrunler;
}

void Veritabani::urunGuncelle(int urunKodu, Urun *urun)
{
  if (u_aramaUrunKodu.count(urunKodu) == 0) {
      throw "Urun kodu bulunamadi.";
    }
  Urun *eskiUrun = u_aramaUrunKodu[urunKodu];
  eskiUrun->setUrunAdi(urun->getUrunAdi());
}

void Veritabani::kategoriEkle(Kategori *kategori)
{
  u_vektorKategoriler.push_back(kategori);
}

void Veritabani::kategoriEkle(string kategoriAdi)
{
  /*if (u_aramaKategoriKodu.count(kategoriKodu) == 1) {
      throw "Ayni kodlu baska bir kategori var.";
    }
  */
  Kategori* kategori = new Kategori;
  kategori->setKategoriAdi(kategoriAdi);
  kategori->setKategoriKodu(u_kategoriKodu);

  u_aramaKategoriAdi.insert(make_pair(kategoriAdi, kategori));
  u_aramaKategoriKodu[u_kategoriKodu] = kategori;

  u_vektorKategoriler.push_back(kategori);

  u_kategoriKodu++;
}

void Veritabani::kategoriSil(int kategoriKodu)
{
  if (u_aramaKategoriKodu.count(kategoriKodu) == 0) {
      throw "Kategori kodu bulunamadi.";
    }

  Kategori *silinecekKategori = u_aramaKategoriKodu[kategoriKodu];

  for (auto i = u_vektorKategoriler.begin(); i != u_vektorKategoriler.end(); i++) {
      if (*i == silinecekKategori) {
          u_vektorKategoriler.erase(i);
          break;
        }
    }

  u_aramaKategoriKodu.erase(kategoriKodu);

  auto adaGoreSilme = u_aramaKategoriAdi.equal_range(silinecekKategori->getKategoriAdi());

  for (auto i = adaGoreSilme.first; i != adaGoreSilme.second; i++) {
      if (i->second == silinecekKategori) {
          u_aramaKategoriAdi.erase(i);
          break;
        }
    }
  delete silinecekKategori;
}

Kategori *Veritabani::kategoriBul(int kategoriKodu)
{
  if (u_aramaKategoriKodu.count(kategoriKodu) == 0) {
      throw "Kategori kodu bulunamadi.";
    }
  return u_aramaKategoriKodu[kategoriKodu];
}

KategoriVektoru Veritabani::adaGoreKategoriAra(string kategoriAdi)
{
  KategoriVektoru kategoriler;
  for (adaGoreKategoriGezgini i = u_aramaKategoriAdi.begin();
       i != u_aramaKategoriAdi.end();
       i++) {
      if (i->second->getKategoriAdi().find(kategoriAdi) != string::npos) {
          kategoriler.push_back(i->second);
        }
    }
  return kategoriler;
}

KategoriVektoru Veritabani::tumKategoriler()
{
  return u_vektorKategoriler;
}

void Veritabani::kategoriGuncelle(int kategoriKodu, Kategori *kategori)
{
  if (u_aramaKategoriKodu.count(kategoriKodu) == 0) {
      throw "Kategori kodu bulunamadi.";
    }
  Kategori *eskiKategori = u_aramaKategoriKodu[kategoriKodu];
  eskiKategori->setKategoriAdi(kategori->getKategoriAdi());
}

void Veritabani::alisEkle(Alis *alis)
{
  u_vektorAlislar.push_back(alis);
}

void Veritabani::alisEkle(int urunKodu, string alisTarihi, float alisFiyati, int alisAdeti)
{
  if (u_aramaUrunKodu.count(urunKodu) == 0) {
      throw "Urun bulunamadi, once urunu eklemelisiniz.";
    }
  Alis *alis = new Alis;
  alis->setAlisKodu(u_alisKodu);
  alis->setAlisAdeti(alisAdeti);
  alis->setAlisFiyati(alisFiyati);
  alis->setAlisTarihi(alisTarihi);
  alis->setUrunKodu(urunKodu);

  u_vektorAlislar.push_back(alis);
  u_aramaAlisKodu[u_alisKodu] = alis;
  u_iliskiUrunAlis.insert(make_pair(u_aramaUrunKodu[urunKodu], alis));

  u_alisKodu++;
}

void Veritabani::alisSil(int alisKodu)
{
  if (u_aramaAlisKodu.count(alisKodu) == 0) {
      throw "Silinecek alis islemi bulunamadi.";
    }

  Alis *silinecekAlis = u_aramaAlisKodu[alisKodu];

  for (auto i = u_vektorAlislar.begin(); i != u_vektorAlislar.end(); i++) {
      if (*i == silinecekAlis) {
          u_vektorAlislar.erase(i);
          break;
        }
    }
  u_aramaAlisKodu.erase(alisKodu);

  delete silinecekAlis;
}

Alis *Veritabani::alisBul(int alisKodu)
{
  if (u_aramaUrunKodu.count(alisKodu) == 0) {
      throw "Alis kodu bulunamadi.";
    }
  return u_aramaAlisKodu[alisKodu];
}

AlisVektoru Veritabani::tumAlislar()
{
  return u_vektorAlislar;
}

void Veritabani::satisEkle(Satis *satis)
{
  u_vektorSatislar.push_back(satis);
}

void Veritabani::satisEkle(int urunKodu, string satisTarihi, float satisFiyati, int satisAdeti)
{
  if (u_aramaUrunKodu.count(urunKodu) == 0) {
      throw "Urun bulunamadi, once urunu eklemelisiniz.";
    }
  Satis *satis = new Satis;
  satis->setSatisKodu(u_satisKodu);
  satis->setSatisAdeti(satisAdeti);
  satis->setSatisFiyati(satisFiyati);
  satis->setSatisTarihi(satisTarihi);
  satis->setUrunKodu(urunKodu);

  u_vektorSatislar.push_back(satis);
  u_aramaSatisKodu[u_satisKodu] = satis;
  u_iliskiUrunSatis.insert(make_pair(u_aramaUrunKodu[urunKodu], satis));

  u_satisKodu++;
}

void Veritabani::satisSil(int satisKodu)
{
  if (u_aramaSatisKodu.count(satisKodu) == 0) {
      throw "Silinecek satis islemi bulunamadi.";
    }

  Satis *silinecekSatis = u_aramaSatisKodu[satisKodu];

  for (auto i = u_vektorSatislar.begin(); i != u_vektorSatislar.end(); i++) {
      if (*i == silinecekSatis) {
          u_vektorSatislar.erase(i);
          break;
        }
    }
  u_aramaSatisKodu.erase(satisKodu);

  delete silinecekSatis;
}

Satis *Veritabani::satisBul(int satisKodu)
{
  if (u_aramaUrunKodu.count(satisKodu) == 0) {
      throw "Satis kodu bulunamadi.";
    }
  return u_aramaSatisKodu[satisKodu];
}

SatisVektoru Veritabani::tumSatislar()
{
  return u_vektorSatislar;
}

int Veritabani::getU_urunKodu()
{
  return u_urunKodu;
}

void Veritabani::setU_urunKodu(int value)
{
  u_urunKodu = value;
}

int Veritabani::getU_kategoriKodu()
{
  return u_kategoriKodu;
}

void Veritabani::setU_kategoriKodu(int value)
{
  u_kategoriKodu = value;
}

int Veritabani::getU_alisKodu()
{
  return u_alisKodu;
}

void Veritabani::setU_alisKodu(int value)
{
  u_alisKodu = value;
}

int Veritabani::getU_satisKodu()
{
  return u_satisKodu;
}

void Veritabani::setU_satisKodu(int value)
{
  u_satisKodu = value;
}

Veritabani::Veritabani()
{
  this->u_urunKodu = 1;
  this->u_kategoriKodu = 1;
  this->u_alisKodu = 1;
  this->u_satisKodu = 1;
}

