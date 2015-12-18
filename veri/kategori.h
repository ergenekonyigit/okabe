#ifndef KATEGORI_H
#define KATEGORI_H

#include <string>

using namespace std;

class Kategori
{
public:
  int kategoriKodu;
  string kategoriAdi;
  Kategori();
  int getKategoriKodu();
  void setKategoriKodu(int value);
  string getKategoriAdi();
  void setKategoriAdi(string value);
};

#endif // KATEGORI_H
