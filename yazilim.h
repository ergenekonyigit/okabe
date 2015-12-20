#ifndef YAZILIM_H
#define YAZILIM_H

#include "veri/veritabani.h"

class Yazilim
{
private:
  Veritabani *vt;

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
