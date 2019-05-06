/* 
 * File:   sofor.cpp
 * Author: Suat BAYIR
 *
 */
 
#include "sofor.h"
#include <iostream>
using namespace std;

// default constructor
sofor::sofor(){
	this->soforNo=0;
	this->ad=" ";
	this->soyad=" ";
	this->maas=0;
}
// parametreli constructor
sofor::sofor(int sn,string a,string s,int m){
	this->soforNo=sn;
	this->ad=a;
	this->soyad=s;
	this->maas=m;
}
// sofor no set&get fonksiyon
void sofor::setSoforNo(int sn){
	this->soforNo=sn;
}
int sofor::getSoforNo(){
	return this->soforNo;
}
// Ad set&get fonksiyon
void sofor::setAd(string a){
	this->ad=a;
}

string sofor::getAd(){
	return this->ad;
}
// soyad set&get fonksiyon
void sofor::setSoyad(string s){
	this->soyad=s;
}
string sofor::getSoyad(){
	return this->soyad;
}

//maas set&get fonksiyon
void sofor::setMaas(int m){
	this->maas=m;
}
int sofor::getMaas(){
	return this->maas;
}

// soforleri ekrana yazan fonksiyon
void sofor::soforYaz(){
	cout<<getSoforNo()<<"\t"<<getAd()<<"\t"<<getSoyad()<<"\t"<<getMaas()<<endl;
}
