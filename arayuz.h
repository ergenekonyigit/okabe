#ifndef ARAYUZ_H
#define ARAYUZ_H


class Arayuz
{
private:
  enum anaMenu {
    Cikis,
    Urunler,
    Kategoriler,
    Alislar,
    Satislar
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
    KategoriSil,
    KategoriDuzenle
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

  void alisMenuListe();
  void alisMenuSecim();

  void satisMenuListe();
  void satisMenuSecim();
public:
  Arayuz();
};

#endif // ARAYUZ_H
