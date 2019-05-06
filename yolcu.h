/* 
 * File:   yolcu.h
 * Author: Suat BAYIR
 *
 */

#include <iostream>
#include <string>

#ifndef YOLCU_H
#define YOLCU_H
#include "sefer.h"
using namespace std;

// yolcu class'ý prototip header dosyasý

// sefer class'ýný inherit et
class yolcu:public sefer{
	private:
		// dýþardan eriþime kapalý deðiþkenler
		string Ad;
		string Soyad;
		int KoltukNo;
		int YolcuNo;
	public:
		// parametreli ve parametresiz constructor'lar
		yolcu();
		yolcu(string ad,string s,int kno,int yno);
		yolcu(int sn,int yn,string ky,string vy,int kn,string ad,string soyad);
		// encapsulation
		void setAd(string ad);
		string getAd();
		void setSoyad(string s);
		string getSoyad();
		void setKoltukNo(int kno);
		int getKoltukNo();
		void setYolcuNo(int yno);
		int getYolcuNo();
		void yolcuYaz();
		void yolcuKayitYaz();
};

#endif
