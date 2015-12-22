#ifndef ARAYUZ_H
#define ARAYUZ_H

#include "yazilim.h"

class Arayuz
{
protected:
  Yazilim *yz;
  enum anaMenu {
    Cikis,
    Urunler,
    Kategoriler,
    Alislar,
    Satislar,
    GunlukKar,
    Kullanim,
    Hakkinda,
    Tazele
  };

  enum urunMenu {
    UrunAnaMenu,
    YeniUrun,
    AdaGoreUrunAra,
    KodaGoreUrunAra,
    UrunleriListele,
    UrunSil,
    UrunDuzenle
  };

  enum kategoriMenu {
    KategoriAnaMenu,
    YeniKategori,
    AdaGoreKategoriAra,
    KodaGoreKategoriAra,
    KategoriListele,
    KategoriDetay,
    KategoriSil,
    KategoriDuzenle
  };

  enum kategoriDetayMenu {
    KategoriDetayAnaMenu,
    KategoriDetayUrunler,
    KategoriDetayToplamAlis,
    KategoriDetayToplamSatis,
    KategoriDetayKar,
    KategoriDetayKategoriler
  };

  enum alisMenu {
    AlisAnaMenu,
    YeniAlis,
    AlisListele,
    AlisSil,
    AlisDuzenle,
    KodaGoreAlisBul
  };

  enum satisMenu {
    SatisAnaMenu,
    YeniSatis,
    SatisListele,
    SatisSil,
    SatisDuzenle,
    KodaGoreSatisBul
  };

  void anaMenuListe();
  void anaMenuSecim();

  void urunMenuListe();
  void urunMenuSecim();

  void kategoriMenuListe();
  void kategoriMenuSecim();

  void kategoriDetayMenuListe();
  void kategoriDetayMenuSecim(int kategoriKodu);

  void alisMenuListe();
  void alisMenuSecim();

  void satisMenuListe();
  void satisMenuSecim();

  void kullanim();
  void hakkinda();
  void gunlukHesapCiktisi();
public:
  Arayuz();
};

#endif // ARAYUZ_H
