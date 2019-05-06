/* 
 * File:   sefer.cpp
 * Author: Suat BAYIR
 *
 */

#include <iostream>
#include <string>
#include "sefer.h"

using namespace std;

// parametresiz constructor fonksiyon
sefer::sefer(){
    setSeferNo(0);
    setKoltukSayisi(0);
    setKalkisYeri("");
    setVarisYeri("");
}

// parametreli contructor fonksiyon
sefer::sefer(int sn,int ks,string ky,string vy){
    setSeferNo(sn);
    setKoltukSayisi(ks);
    setKalkisYeri(ky);
    setVarisYeri(vy);
}

// sefer no set&get fonksiyonu
void sefer::setSeferNo(int sn){
    this->SeferNo=sn;
}
int sefer::getSeferNo(){
    return this->SeferNo;
}

// koltuk sayisi set&get fonksiyon
void sefer::setKoltukSayisi(int ks){
    this->KoltukSayisi=ks;
}
int sefer::getKoltukSayisi(){
    return this->KoltukSayisi;
}

// kalkis yeri set&get fonksiyon
void sefer::setKalkisYeri(string ky){
    this->KalkisYeri=ky;
}
string sefer::getKalkisYeri(){
    return this->KalkisYeri;
}

// varis yeri set&get fonksiyon
void sefer::setVarisYeri(string vy){
    this->VarisYeri=vy;
}
string sefer::getVarisYeri(){
    return this->VarisYeri;
}

// sefer bilgilerini ekrana yazma fonksiyonu
void sefer::seferYaz(){
    cout<<getSeferNo()<<"\t"<<getKoltukSayisi()<<"\t"<<getKalkisYeri()<<"\t"<<getVarisYeri()<<endl;
}
