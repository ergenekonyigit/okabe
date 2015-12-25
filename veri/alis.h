#ifndef ALIS_H
#define ALIS_H

#include <string>

using namespace std;

class Alis
{
protected:
  int urunKodu;
  int alisTarihi;
  float alisFiyati;
  int alisAdeti;
  int alisKodu;
public:
  Alis();
  int getUrunKodu();
  void setUrunKodu(int value);
  int getAlisTarihi();
  void setAlisTarihi(int value);
  float getAlisFiyati();
  void setAlisFiyati(float value);
  int getAlisAdeti();
  void setAlisAdeti(int value);
  int getAlisKodu();
  void setAlisKodu(int value);
};

#endif // ALIS_H
