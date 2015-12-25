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
    KarHesabi,
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
    UrunTazele = 9
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
    KategoriTazele = 9
  };

  enum kategoriDetayMenu {
    KategoriDetayAnaMenu,
    KategoriDetayUrunler,
    KategoriDetayToplamAlis,
    KategoriDetayToplamSatis,
    KategoriDetayKar,
    KategoriDetayKategoriler,
    KategoriDeteyTazele = 9
  };

  enum alisMenu {
    AlisAnaMenu,
    YeniAlis,
    AlisListele,
    AlisSil,
    AlisDuzenle,
    KodaGoreAlisBul,
    AlisTazele = 9
  };

  enum satisMenu {
    SatisAnaMenu,
    YeniSatis,
    SatisListele,
    SatisSil,
    SatisDuzenle,
    KodaGoreSatisBul,
    SatisTazele = 9
  };

  enum karMenu {
    KarAnaMenu,
    GunlukKar,
    HaftalikKar,
    AylikKar,
    KarTazele = 9
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

  void karHesapMenuListe();
  void karHesapMenuSecim();

  void kullanim();
  void hakkinda();
  void gunlukHesapCiktisi();
  void haftalikHesapCiktisi();
  void aylikHesapCiktisi();
public:
  Arayuz();
};

#endif // ARAYUZ_H
