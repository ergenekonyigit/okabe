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

Veritabani::Veritabani()
{
  this->u_urunKodu = 0;
}

