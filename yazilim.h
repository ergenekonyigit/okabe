#ifndef YAZILIM_H
#define YAZILIM_H

#include "veri/veritabani.h"

class Yazilim
{
protected:
  Veritabani *vt;
public:
  Yazilim();

  void urunEklemeIslemi();
  void urunSilmeIslemi();
  void urunDuzenlemeIslemi();
  void urunListelemeIslemi();
  void adaGoreUrunBulmaIslemi();
  void kodaGoreUrunBulmaIslemi();

  void kategoriEklemeIslemi();
  void kategoriSilmeIslemi();
  void kategoriDuzenlemeIslemi();
  void kategoriListelemeIslemi();
  void kategoriUrunleriListelemeIslemi();
  void adaGoreKategoriBulmaIslemi();
  void kodaGoreKategoriBulmaIslemi();

  void alisEklemeIslemi();
  void alisSilmeIslemi();
  void alisDuzenlemeIslemi();
  void alisListelemeIslemi();
  void kodaGoreAlisBulmaIslemi();

  void satisEklemeIslemi();
  void satisSilmeIslemi();
  void satisDuzenlemeIslemi();
  void satisListelemeIslemi();
  void kodaGoreSatisBulmaIslemi();

  float gunlukKarHesabi(string tarih);
  float toplamAlisMiktariHesaplama();
  float toplamAlisFiyatiHesaplama();
  float toplamSatisMiktariHesaplama();
  float toplamSatisFiyatiHesaplama();
  float kategoriToplamAlisHesaplama(int kategoriKod);
  float kategoriToplamSatisHesaplama(int kategoriKod);

};

#endif // YAZILIM_H
