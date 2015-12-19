#ifndef VERITABANI_H
#define VERITABANI_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "urun.h"
#include "kategori.h"
#include "alis.h"
#include "satis.h"

using namespace std;

typedef vector<Urun*> UrunVektoru;
typedef vector<Kategori*> KategoriVektoru;
typedef vector<Alis*> AlisVektoru;
typedef vector<Satis*> SatisVektoru;

typedef UrunVektoru::iterator UrunGezgini;
typedef KategoriVektoru::iterator KategoriGezgini;
typedef AlisVektoru::iterator AlisGezgini;
typedef SatisVektoru::iterator SatisGezgini;

// Ada Göre Arama
typedef multimap<string, Urun*> adaGoreUrunArama;
typedef multimap<string, Kategori*> adaGoreKategoriArama;

typedef adaGoreUrunArama::iterator adaGoreUrunGezgini;
typedef adaGoreKategoriArama::iterator adaGoreKategoriGezgini;

// Koda Göre Bulma
typedef unordered_map<int, Urun*> kodaGoreUrunArama;
typedef unordered_map<int, Kategori*> kodaGoreKategoriArama;
typedef unordered_map<int, Alis*> kodaGoreAlisArama;
typedef unordered_map<int, Satis*> kodaGoreSatisArama;

// Sonsuz-sonsuz ilişkileri
typedef unordered_multimap<Urun*, Kategori*> UrunKategoriIliski;
typedef unordered_multimap<Kategori*, Urun*> KategoriUrunIliski;

// 1-Sonsuz ilişkisi
typedef unordered_multimap<Urun*, Alis*> UrunAlisIliskisi;
typedef unordered_multimap<Urun*, Satis*> UrunSatisIliskisi;

class Veritabani
{
private:
  UrunVektoru u_vektorUrunler;
  KategoriVektoru u_vektorKategoriler;
  AlisVektoru u_vektorAlislar;
  SatisVektoru u_vektorSatislar;

  UrunKategoriIliski u_iliskiUrunKategori;
  KategoriUrunIliski u_iliskiKategoriUrun;

  UrunAlisIliskisi u_iliskiUrunAlis;
  UrunSatisIliskisi u_iliskiUrunSatis;

  adaGoreUrunArama u_aramaUrunAdi;
  kodaGoreUrunArama u_aramaUrunKodu;

  adaGoreKategoriArama u_aramaKategoriAdi;
  kodaGoreKategoriArama u_aramaKategoriKodu;

  kodaGoreAlisArama u_aramaAlisKodu;
  kodaGoreSatisArama u_aramaSatisKodu;

  int u_urunKodu;
  int u_alisKodu;
  int u_satisKodu;
public:
  Veritabani();
  void urunEkle(Urun *urun);
  void urunEkle(string urunAdi, int urunKodu, int kategoriKodu);
  void urunSil(int urunKodu);
  Urun *urunBul(int urunKodu);
  UrunVektoru adaGoreUrunAra(string urunAdi);
  UrunVektoru kategoriUrunleri(Kategori *kategori);

  void kategoriEkle(Kategori *kategori);
  void kategoriEkle(string kategoriAdi, int kategoriKodu);
  void kategoriSil(int kategoriKodu);
  Kategori *kategoriBul(int kategoriKodu);
  KategoriVektoru adaGoreKategoriAra(string kategoriAdi);

  void alisEkle(Alis *alis);
  void alisEkle(int urunKodu, string alisTarihi, float alisFiyati, int alisAdeti);
  void alisSil(int alisKodu);
  Alis *alisBul(int alisKodu);

  void satisEkle(Satis *satis);
  void satisEkle(int urunKodu, string satisTarihi, float satisFiyati, float KDV, int satisAdeti);
  void satisSil(int satisKodu);
  Satis *satisBul(int satisKodu);


};

#endif // VERITABANI_H
