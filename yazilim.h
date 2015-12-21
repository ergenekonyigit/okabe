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

  void gunlukKarHesabiIslemi();
  void toplamAlisMiktariHesaplamaIslemi();
  void toplamAlisFiyatiHesaplamaIslemi();
  void kategoriToplamAlisHesaplamaIslemi();
  void kategoriToplamSatisHesaplamaIslemi();

};

#endif // YAZILIM_H
