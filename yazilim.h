#ifndef YAZILIM_H
#define YAZILIM_H

#include "veri/veritabani.h"
#include "arayuz.h"

class Yazilim
{
private:
  Veritabani *vt;
  Arayuz *arayuz;
public:
  Yazilim();
  void baslat();
};

#endif // YAZILIM_H
