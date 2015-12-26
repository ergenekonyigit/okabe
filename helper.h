#ifndef HELPER_H
#define HELPER_H

#include <string>

using namespace  std;

void sayisalGirdi(int &degisken);
void sayisalGirdi(int &degisken, string hataMesaji);
void sayisalGirdi(int &degisken, int min, int max);
string buyukHarf(string metin);
string kucukHarf(string metin);
void ekraniTemizle();
#endif // HELPER_H

