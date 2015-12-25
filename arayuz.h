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
    Tazele = 9
  };

  enum urunMenu {
    UrunAnaMenu,
    YeniUrun,
    AdaGoreUrunAra,
    KodaGoreUrunAra,
    UrunleriListele,
    UrunSil,
    UrunDuzenle,
    uTazele = 9
  };

  enum kategoriMenu {
    KategoriAnaMenu,
    YeniKategori,
    AdaGoreKategoriAra,
    KodaGoreKategoriAra,
    KategoriListele,
    KategoriDetay,
    KategoriSil,
    KategoriDuzenle,
    kTazele = 9
  };

  enum kategoriDetayMenu {
    KategoriDetayAnaMenu,
    KategoriDetayUrunler,
    KategoriDetayToplamAlis,
    KategoriDetayToplamSatis,
    KategoriDetayKar,
    KategoriDetayKategoriler,
    kdTazele = 9
  };

  enum alisMenu {
    AlisAnaMenu,
    YeniAlis,
    AlisListele,
    AlisSil,
    AlisDuzenle,
    KodaGoreAlisBul,
    aTazele = 9
  };

  enum satisMenu {
    SatisAnaMenu,
    YeniSatis,
    SatisListele,
    SatisSil,
    SatisDuzenle,
    KodaGoreSatisBul,
    sTazele = 9
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
