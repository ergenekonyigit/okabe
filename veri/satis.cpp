#include "satis.h"

int Satis::getSatisKodu()
{
    return satisKodu;
}

void Satis::setSatisKodu(int value)
{
    satisKodu = value;
}

int Satis::getUrunKodu()
{
    return urunKodu;
}

void Satis::setUrunKodu(int value)
{
  urunKodu = value;
}

string Satis::getSatisTarihi()
{
  return satisTarihi;
}

void Satis::setSatisTarihi(string value)
{
  satisTarihi = value;
}

float Satis::getKDV()
{
  return KDV;
}

void Satis::setKDV(float value)
{
  KDV = value;
}

int Satis::getSatisAdeti()
{
  return satisAdeti;
}

void Satis::setSatisAdeti(int value)
{
  satisAdeti = value;
}

Satis::Satis()
{

}

