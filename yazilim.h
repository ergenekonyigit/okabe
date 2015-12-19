#ifndef YAZILIM_H
#define YAZILIM_H


class Yazilim
{
private:
  enum islemTipi {
    Exit,
    UrunEkle,
    UrunAramaAd,
    UrunAramaKod,
    UrunSilme,
    UrunListele,
    AlisEkle,
    AlisArama,
    AlisSilme,
    AlisListele,
    SatisEkle,
    SatisArama,
    SatisSilme,
    SatisListele,
    AlisSatisListele,
  };

  void islemListesi();
  islemTipi islemSec();

public:
  Yazilim();
  void baslat();
};

#endif // YAZILIM_H
