#ifndef ARAYUZ_H
#define ARAYUZ_H


class Arayuz
{
private:
  enum anaMenu {
    Cikis,
    Urunler,
    Kategoriler,
    Satislar,
    Alislar
  };

  enum urunMenu {
    UrunAnaMenu,
    YeniUrun,
    UrunAra,
    UrunleriListele,
    UrunSil,
    UrunDuzenle
  };

  enum kategoriMenu {
    KategoriAnaMenu,
    YeniKategori,
    KategoriListele,
    KategoriSil,
    KategoriDuzenle
  };

  enum alisMenu {
    AlisAnaMenu,
    YeniAlis,
    AlisListele,
    AlisSil,
    AlisDuzenle
  };

  enum satisMenu {
    SatisAnaMenu,
    YeniSatis,
    SatisListele,
    SatisSil,
    SatisDuzenle
  };

  void anaMenuListe();
  anaMenu anaMenuSecim();
public:
  Arayuz();
};

#endif // ARAYUZ_H
