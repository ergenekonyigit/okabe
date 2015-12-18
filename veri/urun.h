#ifndef URUN_H
#define URUN_H

#include <string>

using namespace std;

class Urun
{
private:
  int urunKodu;
  string urunAdi;
public:
  Urun();

  int getUrunKodu();
  void setUrunKodu(int value);
  string getUrunAdi();
  void setUrunAdi(string value);
};

#endif // URUN_H
