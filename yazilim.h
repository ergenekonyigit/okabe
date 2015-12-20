#ifndef YAZILIM_H
#define YAZILIM_H

#include "veri/veritabani.h"
#include "arayuz.h"

class Yazilim
{
private:
  Veritabani *vt;
  Arayuz *arayuz;
public:
  Yazilim();
  void baslat();

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

};

#endif // YAZILIM_H
