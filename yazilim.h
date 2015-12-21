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
  void kategoriUrunleriListelemeIslemi(int kategoriKodu);
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

  float kategoriToplamAlisMiktariHesaplama(int kategoriKod);
  float kategoriToplamSatisMiktariHesaplama(int kategoriKod);
  float kategoriToplamAlisFiyatiHesaplama(int kategoriKod);
  float kategoriToplamSatisFiyatiHesaplama(int kategoriKod);
  float kategoriKarHesaplama(int kategoriKodu);

};

#endif // YAZILIM_H
