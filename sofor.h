/* 
 * File:   sofor.h
 * Author: Suat BAYIR
 *
 */

#ifndef SOFOR_H
#define SOFOR_H
#include <string>
#include <iostream>

using namespace std;

// sofor bilgilerini tutan class
class sofor{
	private:		
		// dýþarýdan eriþime kapalý deðiþkenler
		int soforNo;
		string ad;
		string soyad;
		int maas;
	public:
		// default ve parametreli constructor
		sofor();
		sofor(int sn,string a,string s,int m);
		void setSoforNo(int sn);
		void setAd(string a);
		void setSoyad(string s);
		void setMaas(int m);
		int getSoforNo();
		string getAd();
		string getSoyad();
		int getMaas();
		void soforYaz();
};

#endif	// SOFOR H
