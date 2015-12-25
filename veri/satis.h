#ifndef SATIS_H
#define SATIS_H

#include <string>

using namespace std;

class Satis
{
private:
  int urunKodu;
  int satisTarihi;
  float satisFiyati;
  int satisAdeti;
  int satisKodu;
public:
  Satis();
  int getUrunKodu();
  void setUrunKodu(int value);
  int getSatisTarihi();
  void setSatisTarihi(int value);
  int getSatisAdeti();
  void setSatisAdeti(int value);
  float getSatisFiyati();
  void setSatisFiyati(float value);
  int getSatisKodu();
  void setSatisKodu(int value);
};

#endif // SATIS_H
