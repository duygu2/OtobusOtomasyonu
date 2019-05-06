/* 
 * File:   sefer.h
 * Author: Suat BAYIR
 *
 */

#ifndef SEFER_H
#define	SEFER_H
#include <string>
#include <iostream>

using namespace std;

// sefer class'ý prototip header dosyasý

class sefer{
private:
	// private alan sadece class içi eriþim
    int SeferNo;
    int KoltukSayisi;
    string KalkisYeri;
    string VarisYeri;
public:
	// public alan herkese açýk eriþim
	// parametreli ve paremetresiz constructor'lar
    sefer();
    sefer(int sn,int ks,string ky,string vy);
    // encapsulation
    void setSeferNo(int sn);
    int getSeferNo();
    void setKoltukSayisi(int ks);
    int getKoltukSayisi();
    void setKalkisYeri(string ky);
    string getKalkisYeri();
    void setVarisYeri(string vy);
    string getVarisYeri();
    // sefer print fonksiyonu
    void seferYaz();
};

#endif	/* SEFER_H */

