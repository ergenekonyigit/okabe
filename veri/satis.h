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
  float KDV;
  int satisAdeti;
public:
  Satis();
  int getUrunKodu();
  void setUrunKodu(int value);
  string getSatisTarihi();
  void setSatisTarihi(string value);
  float getKDV();
  void setKDV(float value);
  int getSatisAdeti();
  void setSatisAdeti(int value);
  float getSatisFiyati();
  void setSatisFiyati(float value);
};

#endif // SATIS_H
