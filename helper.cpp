#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void sayisalGirdi(int &degisken) {
  bool ok = false;
  while (!ok)
    {
      cin >> degisken;
      if(!cin.fail() && (cin.peek()==EOF || cin.peek()=='\n'))
        {
          ok = true;
        }
      else
        {
          cin.clear();
          cin.ignore(256,'\n');
          cout << "Hata! Sayisal deger giriniz!" << endl
               << "Secim : ";
        }
    }
}

void sayisalGirdi(int &degisken, int min, int max)
{
  bool ok = false;
  while (!ok)
    {
      cin >> degisken;
      if(!cin.fail() && (cin.peek()==EOF || cin.peek()=='\n'))
        {
          if (degisken <= max && degisken >= min) {
              ok = true;
            }
          else {
              cin.clear();
              cin.ignore(256,'\n');
              cout << "Hata! Belirtilen aralikta bir deger giriniz!" << endl
                   << "Secim : ";
            }
        }
      else
        {
          cin.clear();
          cin.ignore(256,'\n');
          cout << "Hata! Sayisal deger giriniz!" << endl
               << "Secim : ";
        }
    }
}

string buyukHarf(string metin)
{
  transform(metin.begin(), metin.end(),metin.begin(), ::toupper);
  return metin;
}



string kucukHarf(string metin)
{
  transform(metin.begin(), metin.end(), metin.begin(), ::tolower);
  return metin;
}

void sayisalGirdi(int &degisken, string hataMesaji) {
  bool ok = false;
  while (!ok)
    {
      cin >> degisken;
      if(!cin.fail() && (cin.peek()==EOF || cin.peek()=='\n'))
        {
          ok = true;
        }
      else
        {
          cin.clear();
          cin.ignore(256,'\n');
          cout << hataMesaji;
        }
    }
}
