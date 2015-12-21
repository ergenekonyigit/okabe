#include <iostream>
#include <string>

#include "yazilim.h"
#include "veri/veritabani.h"

using namespace std;

Yazilim::Yazilim()
{
  this->vt = new Veritabani;
}

void Yazilim::urunEklemeIslemi()
{
  string urunAdi;
  int kategoriKodu;
  cout << "Urun Adini Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, urunAdi);
  cout << "Kategori Kodunu Giriniz : ";
  cin >> kategoriKodu;

  try {
    this->vt->urunEkle(urunAdi, kategoriKodu);
    cout << "Urun Eklendi!" << endl;
    cout << urunAdi << " için urun kodu : " << vt->getU_urunKodu() - 1 << endl;
    cout << "Girilen kategori : " << vt->kategoriBul(kategoriKodu)->getKategoriAdi() << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::urunSilmeIslemi()
{
  int urunKodu;
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;

  try {
    this->vt->urunSil(urunKodu);
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::urunDuzenlemeIslemi()
{
  urunSilmeIslemi();
  urunEklemeIslemi();
}

void Yazilim::urunListelemeIslemi()
{

}

void Yazilim::adaGoreUrunBulmaIslemi()
{
  string urunAdi;
  cout << "Urun Adini Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, urunAdi);

  UrunVektoru sonuc = this->vt->adaGoreUrunAra(urunAdi);

  cout << " Urun Kodu" << '\t' << "         Urun Adi      " << endl;
  cout << "==========="  << '\t' << "======================" << endl;
  for (UrunGezgini i = sonuc.begin(); i != sonuc.end(); i++) {
      Urun *urun_i = *i;
      cout << urun_i->getUrunKodu() << '\t' << '\t' << urun_i->getUrunAdi() << endl;
    }
  cout << "======================================" << endl;
  cout << "Toplam Urun Sayisi : " << sonuc.size() << endl;
}

void Yazilim::kodaGoreUrunBulmaIslemi()
{
  int urunKodu;
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;

  try {
    Urun* urun = this->vt->urunBul(urunKodu);

    cout << " Urun Kodu" << '\t' << "         Urun Adi      " << endl;
    cout << "==========="  << '\t' << "======================" << endl;
    cout << urun->getUrunKodu() << '\t' << '\t' << urun->getUrunAdi() << endl;
    cout << "======================================" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::kategoriEklemeIslemi()
{
  string kategoriAdi;
  cout << "Kategori Adini Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, kategoriAdi);

  try {
    this->vt->kategoriEkle(kategoriAdi);
    cout << "Kategori Eklendi!" << endl;
    cout << kategoriAdi << " için kategori kodu : " << vt->getU_kategoriKodu() - 1 << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::kategoriSilmeIslemi()
{
  int kategoriKodu;
  cout << "Kategori Kodunu Giriniz : ";
  cin >> kategoriKodu;

  try {
    this->vt->urunSil(kategoriKodu);
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::kategoriDuzenlemeIslemi()
{
  kategoriSilmeIslemi();
  kategoriEklemeIslemi();
}

void Yazilim::kategoriListelemeIslemi()
{
  /*
  KategoriVektoru sonuc;
  cout << "Kategori Kodu" << '\t' << "      Kategori Adi    " << endl;
  cout << "============="  << '\t' << "======================" << endl;
  for (KategoriGezgini i = sonuc.begin(); i != sonuc.end(); i++) {
      Kategori *kategori_i = *i;
      cout << kategori_i->getKategoriKodu() << '\t' << '\t' << kategori_i->getKategoriAdi() << endl;
    }
  cout << "======================================" << endl;
  cout << "Toplam Kategori Sayisi : " << sonuc.size() << endl;
  */
}

void Yazilim::kategoriUrunleriListelemeIslemi()
{

}

void Yazilim::adaGoreKategoriBulmaIslemi()
{
  string kategoriAdi;
  cout << "Kategori Adini Giriniz : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, kategoriAdi);

  KategoriVektoru sonuc = this->vt->adaGoreKategoriAra(kategoriAdi);

  cout << "Kategori Kodu" << '\t' << "      Kategori Adi    " << endl;
  cout << "============="  << '\t' << "======================" << endl;
  for (KategoriGezgini i = sonuc.begin(); i != sonuc.end(); i++) {
      Kategori *kategori_i = *i;
      cout << kategori_i->getKategoriKodu() << '\t' << '\t' << kategori_i->getKategoriAdi() << endl;
    }
  cout << "======================================" << endl;
  cout << "Toplam Kategori Sayisi : " << sonuc.size() << endl;
}

void Yazilim::kodaGoreKategoriBulmaIslemi()
{
  int kategoriKodu;
  cout << "Kategori Kodunu Giriniz : ";
  cin >> kategoriKodu;

  try {
    Kategori* kategori = this->vt->kategoriBul(kategoriKodu);

    cout << "Kategori Kodu" << '\t' << "      Kategori Adi    " << endl;
    cout << "============="  << '\t' << "======================" << endl;
    cout << kategori->getKategoriKodu() << '\t' << '\t' << kategori->getKategoriAdi() << endl;
    cout << "======================================" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::alisEklemeIslemi()
{
  string alisTarihi;
  float alisFiyati;
  int urunKodu, alisAdeti;
  cout << "Alis Tarihini Giriniz (YilAyGun Seklinde Yaziniz) : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, alisTarihi);
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;
  cout << "Alis Fiyatini Giriniz : ";
  cin >> alisFiyati;
  cout << "Alis Adetini Giriniz : ";
  cin >> alisAdeti;

  try {
    this->vt->alisEkle(urunKodu, alisTarihi, alisFiyati, alisAdeti);
    cout << "Başarılı!" << endl;
    cout << "Alış kodu : " << vt->getU_alisKodu() - 1 << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::alisSilmeIslemi()
{
  int alisKodu;
  cout << "Alis Kodunu Giriniz : ";
  cin >> alisKodu;

  try {
    this->vt->alisSil(alisKodu);
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::alisDuzenlemeIslemi()
{
  alisSilmeIslemi();
  alisEklemeIslemi();
}

void Yazilim::alisListelemeIslemi()
{

}

void Yazilim::kodaGoreAlisBulmaIslemi()
{
  int alisKodu;
  cout << "Alis Kodunu Giriniz : ";
  cin >> alisKodu;

  try {
    Alis* alis = this->vt->alisBul(alisKodu);

    cout << " Alis Kodu" << '\t' << "         Urun Kodu     " << endl;
    cout << "==========="  << '\t' << "======================" << endl;
    cout << alis->getAlisKodu() << '\t' << '\t' << alis->getUrunKodu() << endl;
    cout << "======================================" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::satisEklemeIslemi()
{
  string satisTarihi;
  float satisFiyati;
  int urunKodu, satisAdeti;
  cout << "Satis Tarihini Giriniz (YilAyGun Seklinde Yaziniz) : ";
  cin.clear();
  cin.ignore(1, '\n');
  getline(cin, satisTarihi);
  cout << "Urun Kodunu Giriniz : ";
  cin >> urunKodu;
  cout << "Satis Fiyatini Giriniz : ";
  cin >> satisFiyati;
  cout << "Satis Adetini Giriniz : ";
  cin >> satisAdeti;

  try {
    this->vt->satisEkle(urunKodu, satisTarihi, satisFiyati, satisAdeti);
    cout << "Başarılı!" << endl;
    cout << "Satış kodu : " << vt->getU_satisKodu() - 1 << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::satisSilmeIslemi()
{
  int satisKodu;
  cout << "Satis Kodunu Giriniz : ";
  cin >> satisKodu;

  try {
    this->vt->satisSil(satisKodu);
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}

void Yazilim::satisDuzenlemeIslemi()
{
  satisSilmeIslemi();
  satisEklemeIslemi();
}

void Yazilim::satisListelemeIslemi()
{

}

void Yazilim::kodaGoreSatisBulmaIslemi()
{
  int satisKodu;
  cout << "Satis Kodunu Giriniz : ";
  cin >> satisKodu;

  try {
    Satis* satis = this->vt->satisBul(satisKodu);

    cout << "Satis Kodu" << '\t' << "         Urun Kodu     " << endl;
    cout << "=========="  << '\t' << "======================" << endl;
    cout << satis->getSatisKodu() << '\t' << '\t' << satis->getUrunKodu() << endl;
    cout << "======================================" << endl;
  } catch (char const* hata) {
    cout << "HATA OLUSTU : " << hata << endl;
  }
}


/* ==Bilinen Eksikler==
 * haftalik-aylik alis ve satislarin listelenmesi
 */
