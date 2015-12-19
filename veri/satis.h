#ifndef SATIS_H
#define SATIS_H

#include <string>

using namespace std;

class Satis
{
private:
  int urunKodu;
  string satisTarihi;
  float satisFiyati;
  int satisAdeti;
  int satisKodu;
public:
  Satis();
  int getUrunKodu();
  void setUrunKodu(int value);
  string getSatisTarihi();
  void setSatisTarihi(string value);
  int getSatisAdeti();
  void setSatisAdeti(int value);
  float getSatisFiyati();
  void setSatisFiyati(float value);
  int getSatisKodu();
  void setSatisKodu(int value);
};

#endif // SATIS_H
