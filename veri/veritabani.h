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

class Veritabani
{
private:
  UrunVektoru u_vektorUrunler;
  KategoriVektoru u_vektorKategoriler;
  AlisVektoru u_vektorAlislar;
  SatisVektoru u_vektorSatislar;

public:
  Veritabani();
};

#endif // VERITABANI_H
