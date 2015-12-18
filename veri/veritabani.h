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
typedef vector<Urun*> KategoriVektoru;
typedef vector<Urun*> AlisVektoru;
typedef vector<Urun*> SatisVektoru;

typedef UrunVektoru::iterator UrunGezgini;
typedef KategoriVektoru::iterator KategoriGezgini;
typedef AlisVektoru::iterator AlisGezgini;
typedef SatisVektoru::iterator SatisGezgini;

// Ada Göre Arama
typedef multimap<string, Urun*> adaGoreUrunArama;
typedef multimap<string, Kategori*> adaGoreKategoriArama;

typedef adaGoreUrunArama::iterator adaGoreUrunAramaGezgini;
typedef adaGoreKategoriArama::iterator adaGoreKategoriAramaGezgini;

// Koda Göre Bulma
typedef unordered_map<int, Urun*> kodaGoreUrunArama;
typedef unordered_map<int, Kategori*> kodaGoreKategoriArama;

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

  int u_urunKodu;
public:
  Veritabani();
  void urunEkle(Urun *urun);
  void urunEkle(string urunAdi, int urunKodu, int kategoriKodu);
  void urunSil(int urunKodu);
  Urun *urunBul(int urunKodu);
  UrunVektoru adaGoreUrunAra(string urunAdi);
  UrunVektoru kategoriUrunleri(Kategori *kategori);
};

#endif // VERITABANI_H
