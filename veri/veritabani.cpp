#include "veritabani.h"

#include <exception>

void Veritabani::urunEkle(Urun *urun)
{
  u_vektorUrunler.push_back(urun);
}

void Veritabani::urunEkle(string urunAdi, int urunKodu, int kategoriKodu)
{
  if (u_aramaUrunKodu.count(urunKodu) == 1) {
      throw "Aynı kodlu başka bir ürün var.";
  }
  if (u_aramaKategoriKodu.count(kategoriKodu) == 0) {
    throw "Kategori kodu bulunamadı.";
  }

  Urun *urun = new Urun;
  urun->setUrunAdi(urunAdi);
  urun->setUrunKodu(u_urunKodu); u_urunKodu++;

  u_aramaUrunKodu[urunKodu] = urun;
  u_aramaUrunAdi.insert(make_pair(urunAdi, urun));

  u_iliskiKategoriUrun.insert(
        make_pair(u_aramaKategoriKodu[kategoriKodu], urun));
  u_iliskiUrunKategori.insert(
        make_pair(urun, u_aramaKategoriKodu[kategoriKodu]));
  u_vektorUrunler.push_back(urun);

}

void Veritabani::urunSil(int urunKodu)
{
  if (u_aramaUrunKodu.count(urunKodu) == 0) {
      throw "Silinecek ürün bulunamadı.";
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

void Veritabani::kategoriEkle(Kategori *kategori)
{
  u_vektorKategoriler.push_back(kategori);
}

void Veritabani::kategoriEkle(string kategoriAdi, int kategoriKodu)
{
  if (u_aramaKategoriKodu.count(kategoriKodu) == 1) {
      throw "Ayni kodlu baska bir kategori var.";
  }

  Kategori* kategori = new Kategori;
  kategori->setKategoriAdi(kategoriAdi);
  kategori->setKategoriKodu(kategoriKodu);

  u_aramaKategoriAdi.insert(make_pair(kategoriAdi, kategori));
  u_aramaKategoriKodu[kategoriKodu] = kategori;

  u_vektorKategoriler.push_back(kategori);

  /*
  u_vektorKategoriler[0] = kategori;
  kategori = u_vektorKategoriler[0];
  */
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
  if (u_aramaUrunKodu.count(kategoriKodu) == 0) {
      throw "Kategori kodu bulunamadi.";
    }
  return u_aramaKategoriKodu[kategoriKodu];
}

KategoriVektoru Veritabani::adaGoreKategoriAra(string kategoriAdi)
{
  KategoriVektoru sonuc;

  adaGoreKategoriGezgini baslangic, bitis;
  baslangic = u_aramaKategoriAdi.lower_bound(kategoriAdi);
  bitis = u_aramaKategoriAdi.upper_bound(kategoriAdi);

  for (adaGoreKategoriGezgini i = baslangic; i != bitis; i++) {
      sonuc.push_back(i->second);
    }
  return sonuc;
}

void Veritabani::alisEkle(Alis *alis)
{
  u_vektorAlislar.push_back(alis);
}

void Veritabani::alisEkle(string alisTarihi, float alisFiyati, int alisAdeti)
{

}

void Veritabani::satisEkle(Satis *satis)
{
  u_vektorSatislar.push_back(satis);
}

void Veritabani::satisEkle(int urunKodu, string satisTarihi, float satisFiyati, float KDV, int satisAdeti)
{

}

Veritabani::Veritabani()
{
  this->u_urunKodu = 0;
}

