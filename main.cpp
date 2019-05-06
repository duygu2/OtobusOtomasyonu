/* 
 * File:   main.cpp
 * Author: Suat BAYIR
 *
 */

// library definition
#include <cstdlib>
#include <iostream>
#include <string>
#include "sefer.h"
#include "yolcu.h"
#include "sofor.h"
#include <locale.h>
#include <fstream>
#include <sstream>

// prototype functions
int anaMenu();
int seferMenu();
int yolcuMenu();
int soforMenu();
void seferIslem();
void yolcuIslem();
void soforIslem();
void seferEkle(sefer seferler[],int boyut);
void seferListele(sefer seferler[],int boyut);
void seferSil(sefer seferler[],int boyut);
void seferGuncelle(sefer seferler[],yolcu yolcular[],int boyut);
void biletSatis(sefer seferler[],yolcu yolcular[],int boyut);
void seferOku(sefer seferler[],int boyut);
void seferYaz(sefer seferler[],int boyut);
void yolcuOku(sefer seferler[],yolcu yolcular[],int boyut);
void yolcuYaz(sefer seferler[],yolcu yolcular[],int boyut);
void yolcuSeferYaz(sefer seferler[],yolcu yolcular[],int boyut);
void yolcuSil(yolcu yolcular[],int boyut);
void soforListesi(sofor soforler[],int boyut);
void soforEkle(sofor soforler[],int boyut);
void soforSil(sofor soforler[],int boyut);
void soforYaz(sofor soforler[],int boyut);
void sadeceYolcuListele(yolcu yolcular[],int boyut);
int seferSayisi();

// global object arrays
sefer seferler[100];	
yolcu yolcular[100];	
sofor soforler[100];

using namespace std;

// ANA MENU
int anaMenu(){
	string secilen;
	int sec=0;
	cout<<endl;
	cout<<"**********************************"<<endl;
	cout<<"*****         ANA MENU       *****"<<endl;
	cout<<"*****   1-)Sefer Islemleri   *****"<<endl;
	cout<<"*****   2-)Yolcu Islemleri   *****"<<endl;
	cout<<"*****   3-)Sofor Islemleri   *****"<<endl;
	cout<<"*****   4-)Bilet Islemleri   *****"<<endl;
	cout<<"*****   5-)Cikis             *****"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"Secim : ";
	cin>>secilen;
	stringstream(secilen)>>sec;	// string degeri secim olan int'e aktarma
	return sec;
}

// sefer islemleri menu
int seferMenu(){
	string secilen;
	int sec=0;
	cout<<endl;
	cout<<"**********************************"<<endl;
	cout<<"*****       SEFER MENUSU     *****"<<endl;
	cout<<"*****   1-)Sefer Listeleme   *****"<<endl;
	cout<<"*****   2-)Sefer Ekleme      *****"<<endl;
	cout<<"*****   3-)Sefer Silme       *****"<<endl;
	cout<<"*****   4-)Sefer Güncelleme  *****"<<endl;
	cout<<"*****   5-)Ana Menuye Don    *****"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"Secim : ";
	cin>>secilen;
	stringstream(secilen)>>sec;	// string degeri secim olan int'e aktarma
	return sec;	
}

// yolcu islemleri menu
int yolcuMenu(){
	string secilen;
	int sec=0;
	cout<<endl;
	cout<<"*************************************"<<endl;
	cout<<"*****        YOLCU MENUSU       *****"<<endl;
	cout<<"*****   1-)Yolcu-Sefer Listesi  *****"<<endl;
	cout<<"*****   2-)Yolcu Listesi        *****"<<endl;
	cout<<"*****   3-)Yolcu Sil            *****"<<endl;
	cout<<"*****   4-)Ana Menuye Don       *****"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"Secim : ";
	cin>>secilen;
	stringstream(secilen)>>sec;	// string degeri secim olan int'e aktarma
	return sec;	
}

// sofor islemleri menusu
int soforMenu(){
	string secilen;
	int sec=0;
	cout<<endl;
	cout<<"**********************************"<<endl;
	cout<<"*****      SOFOR MENUSU      *****"<<endl;
	cout<<"*****   1-)Sofor Listele     *****"<<endl;
	cout<<"*****   2-)Sofor Ekle        *****"<<endl;
	cout<<"*****   3-)Sofor Sil         *****"<<endl;
	cout<<"*****   4-)Ana Menuye Don    *****"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"Secim : ";
	cin>>secilen;
	stringstream(secilen)>>sec;	// string degeri secim olan int'e aktarma
	return sec;	
}

// toplam sefer sayisini hesaplayan fonksiyon
int seferSayisi(int boyut){
	int seferSay=0;
	for(int i=1;i<=boyut;i++){
		if(seferler[i].getSeferNo()!=0)
			seferSay++;
	}
	return seferSay;
}

// sefer ekleme fonksiyonu
void seferEkle(sefer seferler[],int boyut){
	string ky,vy;
	int ks,sn,bulundu=0,indis=0;
	// bos indisi bul
	for(int i=1;i<=boyut;i++){
		if(seferler[i].getSeferNo()==0){
			indis=i;
			break;
		}
	}
	// daha önce alýnmamýþ sefer no bul
		do{
			bulundu=0;
			cout<<"Sefer no : ";
			cin>>sn;
			if(sn<=0){
				cout<<"Sefer numarasý 0 veya küçük olamaz"<<endl;
				bulundu=1;
			}
			if(sn>0){
				for(int i=1;i<=boyut;i++){
					// sefer no daha onceden alinmis mi ?
					if(seferler[i].getSeferNo()==sn){
						cout<<"Bu sefer daha onceden alinmis"<<endl;
						bulundu=1;
					}
				}
			}
		}while(bulundu==1);
	
	
	// bos sefer no'ya kullanýcýdan alýnan verileri gir
	seferler[indis].setSeferNo(sn);
	cout<<"Kalkis yeri : ";
	cin>>ky;
	seferler[indis].setKalkisYeri(ky);
	cout<<"Varis yeri : ";
	cin>>vy;
	seferler[indis].setVarisYeri(vy);
	// koltuk sayisini kontrol et
	do{
		cout<<"Koltuk sayisi : ";
		cin>>ks;
		if(ks<=0){
			cout<<"Koltuk Sayisi 0'dan büyük olmalidir.."<<endl;
		}
		else if(ks>50){
			cout<<"Koltuk sayisi 50 veya daha az olmalilidir.."<<endl;
		}
	}while(ks<=0 || ks>50);
	

	seferler[indis].setKoltukSayisi(ks);
	seferler[indis].seferYaz();
	cout<<"YUKARIDAKI BILGILERE SAHIP YENI SEFER KAYDI OLUSTURULDU"<<endl<<endl;
	
	seferListele(seferler,100);
}

// sefer listeleme fonksiyonu
void seferListele(sefer seferler[],int boyut){
	int seferSay=seferSayisi(100);
	if(seferSay!=0){
		cout<<endl<<"SEFER NO   KOLTUK SAYISI  KALKIS YERI  VARIS YERI"<<endl<<endl;
		for(int i=1;i<=boyut;i++){
			if(seferler[i].getSeferNo()!=0){
				seferler[i].seferYaz();
			}
		}
	}
	else
		cout<<"SEFER KAYDI BULUNAMADI"<<endl;
}

// sefer silme fonksiyonu
void seferSil(sefer seferler[],int boyut){
	int seferSay=0;
	for(int i=1;i<=boyut;i++){
		if(seferler[i].getSeferNo()!=0)
			seferSay++;
	}
	if(seferSay!=0){
		seferListele(seferler,100);
		int silSn,silindi=0,silIndis=-1;
		cout<<"Silinecek sefer numarasi : ";
		cin>>silSn;
		// sefer no 0 dan büyükse kontrol et
		if(silSn>0){	
			// silinicek seferi ara eger varsa indise ata
			for(int i=1;i<=boyut;i++){
				if(silSn == seferler[i].getSeferNo()){
					silIndis=i;
					break;		
				}
			}
			// gelen indis'teki bilgileri sil
			if(silIndis!=-1){
					seferler[silIndis].setSeferNo(0);
					seferler[silIndis].setKoltukSayisi(0);
					seferler[silIndis].setKalkisYeri("");
					seferler[silIndis].setVarisYeri("");
					cout<<"SEFER SILINDI !!!"<<endl;
					silindi=1;
			}
			
			// sefer silindiyse o sefer den bilet alan yolcularý da sil
			if(silindi==1){
				for(int i=1;i<=boyut;i++){
					if(silSn==yolcular[i].getSeferNo()){
						yolcular[i].setSeferNo(0);
						yolcular[i].setKalkisYeri("");
						yolcular[i].setKoltukNo(0);
						yolcular[i].setSoyad("");
						yolcular[i].setAd("");
						yolcular[i].setYolcuNo(0);
						yolcular[i].setVarisYeri("");
					}
				}
			}
			
			// sefer yoksa mesaj dönder
			if(silindi!=1)
				cout<<"Bu numaraya ait sefer bulunamadi!!!"<<endl;
		}
		else
			cout<<"Sefer Numarasý 0 ' dan büyük olmalýdýr"<<endl;
	}
	else
		cout<<"SEFER KAYDI BULUNAMADI"<<endl;
}

// sefe güncelleme fonksiyonu
void seferGuncelle(sefer seferler[],yolcu yolcular[],int boyut){
	int seferSay=seferSayisi(100);
	
	if(seferSay!=0){
		seferListele(seferler,100);
		int sn,bulundu=0,bulundu2=0,i=1,indis=-1;
		// guncellenecek degerin gecici degiskenleri
		int yks;
		string yvy,yky;
		// girilen sefer no'ya ait kayýt var mý diye kontrol et
		cout<<"Guncellenecek sefer numarasi : ";
		cin>>sn;
		
		if(sn>0){
			// sefer var mi diye kontrol et
			for(int i=1;i<=boyut;i++){
				if(sn==seferler[i].getSeferNo()){
					indis=i;
					bulundu=1;	
				}
			}
			// degistirilicek numaraya ait kayit bulunamadi
			if(bulundu==0)
				cout<<"Bu numaraya ait sefer kaydi bulunamadi!!"<<endl;
			// eger deðiþtirilicek kayýt bulunduysa içeriye dallan
			if(bulundu==1){
					do{
						cout<<"Yeni Koltuk Sayisi : ";
						cin>>yks;
						if(yks<=0)
							cout<<"Koltuk sayisi 0 veya küçük olamaz"<<endl;
						else if(yks>50)
							cout<<"Koltuk sayisi 50'den büyük olamaz"<<endl;
					}while(yks<=0 || yks>50);
		
					seferler[indis].setKoltukSayisi(yks);
					cout<<"Yeni Kalkis Yeri : ";
					cin>>yky;
					seferler[indis].setKalkisYeri(yky);
					cout<<"Yeni Varis Yeri : ";
					cin>>yvy;
					seferler[indis].setVarisYeri(yvy);
					cout<<"DEGISIKLIKLER BASARIYLA GERCEKLESTIRILDI"<<endl;
					
					// sefer kaydi degisince musteri bilgilerini'De buna göre degistir
					for(int i=1;i<=boyut;i++){
						if(yolcular[i].getYolcuNo()!=0 && yolcular[i].getSeferNo()==sn){
							yolcular[i].setSeferNo(sn);
							yolcular[i].setKalkisYeri(yky);
							yolcular[i].setVarisYeri(yvy);
						}
					}
			}
		}
		else
			cout<<"Sefer no 0'dan büyük olmalýdýr"<<endl;
	}
	else
		cout<<"SEFER KAYDI BULUNAMADI"<<endl;
}

// bilet satis fonksiyonu
void biletSatis(sefer seferler[],yolcu yolcular[],int boyut){
	int sn,yno,kno,i=1,bulundu=0,satisIndis=-1;
	string ad,soyad;
	cout<<endl<<endl;
	seferListele(seferler,100);
	cout<<endl<<endl;
	cout<<"Lutfen bilet almak istediginiz sefer no'yu giriniz : ";
	cin>>sn;
	
	if(sn>0){
		// indisi bul
		for(int i=1;i<=boyut;i++){
			if(seferler[i].getSeferNo()==sn){
				satisIndis=i;
				break;
			}
		}
		
		// sefer' deki tüm koltuklar dolu mu ?
		int koltukSay=0;
		for(int i=1;i<=boyut;i++){
			if(yolcular[i].getSeferNo()==sn)
				koltukSay++;
		}
		if(koltukSay>=seferler[satisIndis].getKoltukSayisi())
			cout<<"BU SEFERDEKÝ TÜM KOLTUKLAR SATILMIS"<<endl;
		else{
			// boyle bir sefer var demektir
			if(satisIndis!=-1){
				// bos olan yolcu numarasýný bul
				for(int i=1;i<=boyut;i++){
					if(yolcular[i].getYolcuNo()==0){
						yno=i;
						break;
					}
				}
				yolcular[yno].setYolcuNo(yno);
				cout<<"Adýnýz : ";
				cin>>ad;
				yolcular[yno].setAd(ad);
				cout<<"Soyadiniz : ";
				cin>>soyad;
				yolcular[yno].setSoyad(soyad);
				
				cout<<"Toplam "<<seferler[satisIndis].getKoltukSayisi()<<" adet koltugumuz bulunmaktadir.."<<endl;
				do{
					bulundu=0;
					cout<<"Koltuk numaraniz : ";
					cin>>kno;
					if(kno>0){
						for(int i=1;i<=boyut;i++){
							// koltuk daha onceden alinmis mi ?
							if(yolcular[i].getKoltukNo()==kno && yolcular[i].getSeferNo()==sn){
								cout<<"Bu koltuk daha onceden alinmis"<<endl;
								bulundu=1;
							}
							// girilen deger uygun mu ?
							if(kno>seferler[satisIndis].getKoltukSayisi() || kno<0){
								bulundu=2;
							}
						}
					}
					else
						cout<<"Koltuk no 0'dan büyük olmalidir"<<endl;
					if(bulundu==2) cout<<"Bu numarada koltuk bulunmamaktadir!!"<<endl;
				}while( kno<=0 || bulundu==1 || bulundu==2);
		
				yolcular[yno].setKoltukNo(kno);
		
				// sefer bilgilerini yolcu bilgilerine kaydet
				yolcular[yno].setSeferNo(sn);
				yolcular[yno].setKalkisYeri(seferler[satisIndis].getKalkisYeri());
				yolcular[yno].setVarisYeri(seferler[satisIndis].getVarisYeri());
				yolcular[yno].yolcuKayitYaz();
				cout<<endl<<"Yukaridaki bilgilere ait bilet satis islemi basariyla gerceklesti..\nYine bekleriz.."<<endl;
			}
			else
				cout<<"Boyle bir sefer yok"<<endl;
		}
	}
	else if(sn<=0)
		cout<<"Sefer no 0' dan büyük olmalidir"<<endl;
}

// yolcu listesini yazan fonksiyon
void yolcuListesi(sefer seferler[],yolcu yolcular[],int boyut){
	// toplam sefer sayýsý kadar dön
	int yolcuSay=0;
	for(int i=1;i<=boyut;i++){
		if(seferler[i].getSeferNo()!=0){
			cout<<"------------------------------------------------------"<<endl;
			cout<<"SeferNo - KoltukSayisi - KalkisYeri - VarisYeri"<<endl;
			seferler[i].seferYaz();
			// o sefere ait yolcu saysýný bul
			for(int j=1;j<=boyut;j++){
				if(yolcular[j].getYolcuNo()!=0 && yolcular[j].getSeferNo()==seferler[i].getSeferNo()){
					yolcuSay++;
				}
			}
			// eðer yolcu varsa yaz
			if(yolcuSay>0)
				cout<<endl<<"Ad - Soyad - KoltukNo"<<endl;
			else
				cout<<"BU SEFER AÝT YOLCU KAYDI BULUNAMADI"<<endl;
			// o seferdeki toplam yolcu sayýsý kadar dön
			for(int j=1;j<=boyut;j++){
				if(yolcular[j].getYolcuNo()!=0 && yolcular[j].getSeferNo()==seferler[i].getSeferNo()){
					yolcular[j].yolcuYaz();
				}
			}
			cout<<endl;
		}
	}
}

// sadece yolcu bilgilerini listeleyen fonksiyon
void sadeceYolcuListele(yolcu yolcular[],int boyut){
	int yolcuSay=0;
	// yolcu var mi diye kontrol et
	for(int i=1;i<=boyut;i++){
		if(yolcular[i].getYolcuNo()!=0)
			yolcuSay++;
	}
	if(yolcuSay>0)
		cout<<endl<<"YolcuNo - SeferNo - Ad - Soyad - KoltukNo"<<endl;
	else
		cout<<"KAYITLI YOLCU BULUNAMADI"<<endl;
	for(int i=1;i<=boyut;i++){
		if(yolcular[i].getYolcuNo()!=0){
			cout<<yolcular[i].getYolcuNo()<<"\t"
				<<yolcular[i].getSeferNo()<<"\t"
				<<yolcular[i].getAd()<<"\t"
				<<yolcular[i].getSoyad()<<"\t"
				<<yolcular[i].getKoltukNo()<<endl;
		}
	}
}

// yolcu silme fonksiyonu
void yolcuSil(yolcu yolcular[],int boyut){
	
	int yolcuSay=0;
	// yolcu var mi diye kontrol et
	for(int i=1;i<=boyut;i++){
		if(yolcular[i].getYolcuNo()!=0)
			yolcuSay++;
	}
	// kayýtlý yolcu varsa
	if(yolcuSay>0){
		int silYno=-1,silIndis=-1;
		
		sadeceYolcuListele(yolcular,100);
			
		cout<<"Silmek istediginiz yolcu no : ";
		cin>>silYno;
		
		if(silYno<=0){
			cout<<"yolcu numarasi 0 veya küçük olamaz"<<endl;
		}
		else{
			// silinecek yolcunun dizi indisi bul
			for(int i=0;i<=boyut;i++){
				if(yolcular[i].getYolcuNo()==silYno){
					silIndis=i;
				}
			}
			// yolcu bilgilerini sil
			if(silIndis!=-1){
				yolcular[silIndis].setYolcuNo(0);
				yolcular[silIndis].setKalkisYeri(" ");
				yolcular[silIndis].setKoltukNo(0);
				yolcular[silIndis].setSeferNo(0);
				yolcular[silIndis].setSoyad(" ");
				yolcular[silIndis].setVarisYeri(" ");
				cout<<"YOLCU BASARIYLA SILINDI!!"<<endl;
			}
			else
				cout<<"BOYLE BIR YOLCU YOK!!"<<endl;
		}
	}
	else
		cout<<"KAYITLI YOLCU BULUNAMADI"<<endl;
}

// sefer bilgilerini dosyadan okuyan fonksiyon
void seferOku(sefer seferler[],int boyut){
	ifstream seferOku("seferler.txt",ios::in);
	// dosya yoksa olustur
	if(!seferOku){
		ofstream seferOlustur("seferler.txt",ios::out);
		// dosya olusturulamadýysa hata bas
		if(!seferOlustur){
			cout<<"SEFER OKU DOSYA ACILAMADI!!"<<endl;
			exit(1);
		}
	}
	// gecici degiskenler
	int no,ks,x=1,seferSayisi=0;
	string ky,vy;
	// dosyadan oku seferler nesne dizisine yaz
	while(seferOku>>no>>ks>>ky>>vy){
		sefer gecici(no,ks,ky,vy);
		seferler[x]=gecici;
		x++;
	}
	seferOku.close();
	cout<<"SEFERLER DOSYADAN OKUNDU";
	// toplam sefer sayýsýný bul
	for(int i=1;i<=boyut;i++){
		if(seferler[i].getSeferNo()!=0)
			seferSayisi++;
	}
	// sefer bilgilerini yaz
	cout<<endl<<"TOPLAM "<<seferSayisi<<" ADET SEFER BULUNMAKTADIR";
}

// sefer bilgilerini dosyaya yazan fonksiyon
void seferYaz(sefer seferler[],int boyut){
	ofstream seferYaz("seferler.txt",ios::out);
	// seferler yazýlamadýysa
	if(!seferYaz){
		cout<<"SEFER YAZ DOSYA ACILAMADI!!"<<endl;
		exit(1);
	}

	// sefer bilgilerini dosyaya yaz
	for(int i=1;i<=boyut;i++){
		if(seferler[i].getSeferNo()!=0){
			seferYaz<<seferler[i].getSeferNo()<<" "
					<<seferler[i].getKoltukSayisi()<<" "
					<<seferler[i].getKalkisYeri()<<" "
					<<seferler[i].getVarisYeri()<<endl;	
		}
	}
	seferYaz.close();
}

// yolcu bilgilerini dosyadan okuyan fonksiyon
void yolcuOku(sefer seferler[],yolcu yolcular[],int boyut){
	// yolcularý dosyadan oku dosya yoksa olustur
	ifstream yolcuOku("yolcular.txt",ios::in);
	if(!yolcuOku){
		ofstream yolcuOlustur("yolcular.txt",ios::out);
		if(!yolcuOlustur){
			cout<<"YOLCU OKU DOSYA ACILAMADI!!"<<endl;
			exit(1);
		}
	}
	// dosyadan yolcularý okuyup yerlestir
	int yn,kn,sn,x=1,yolcuSay=0;
	string ky,vy,ad,soyad;
	while(yolcuOku>>sn>>yn>>ky>>vy>>kn>>ad>>soyad){
		yolcu gecici(sn,yn,ky,vy,kn,ad,soyad);
		yolcular[x]=gecici;
		x++;
	}
	cout<<endl<<"YOLCULAR DOSYADAN OKUNDU"<<endl;
	for(int i=1;i<=boyut;i++){
		if(yolcular[i].getYolcuNo()!=0)
			yolcuSay++;
	}
	cout<<"TOPLAM "<<yolcuSay<<" ADET YOLCUNUZ BULUNMAKTADIR"<<endl;
}

// yolcu bilgilerini dosyaya yazan fonksiyon
void yolcuYaz(sefer seferler[],yolcu yolcular[],int boyut){
	// yolcular dosyasýný olustur
	ofstream yolcuYaz("yolcular.txt",ios::out);
	if(!yolcuYaz){
		cout<<"YOLCULAR DOSYASI ACILAMADI"<<endl;
		exit(1);
	}
	
	int yolcuSay=0;
	// toplam yolcu sayýsýný bul
	for(int i=1;i<=boyut;i++){
		if(yolcular[i].getYolcuNo()!=0)
			yolcuSay++;
	}
	// yolcu bilgilerini dosyaya yaz
	for(int i=1;i<=yolcuSay;i++){
		// yolcu no'su bos degilse yolcu var demektir onu dosyaya yaz
		if(yolcular[i].getYolcuNo()!=0){
			yolcuYaz<<yolcular[i].getSeferNo()<<" "
					<<yolcular[i].getYolcuNo()<<" "
					<<yolcular[i].getKalkisYeri()<<" "
					<<yolcular[i].getVarisYeri()<<" "
					<<yolcular[i].getKoltukNo()<<" "
					<<yolcular[i].getAd()<<" "
					<<yolcular[i].getSoyad()<<" "<<endl;
		}
	}
	yolcuYaz.close();
}

// yolcu ve sefer bilgilerini birlikte dosyaya yazan fonksiyon
void yolcuSeferYaz(sefer seferler[],yolcu yolcular[],int boyut){
	ofstream yolcuSeferYaz("yolcuSefer.txt",ios::out);
	// yolcu dosyasý olusmadýysa
	if(!yolcuSeferYaz){
		cout<<"DOSYA OLUSTURULAMADI"<<endl;
		exit(1);
	}
	// sefer ve yolcularý dosyaya yazan dongü
	for(int i=1;i<=boyut;i++){
		if(seferler[i].getSeferNo()!=0){
			yolcuSeferYaz<<"------------------------------------------------------"<<endl;
			yolcuSeferYaz<<"SeferNo - KoltukSayisi - KalkisYeri - VarisYeri"<<endl;
			yolcuSeferYaz<<seferler[i].getSeferNo()<<"   "
						 <<seferler[i].getKoltukSayisi()<<"   "
						 <<seferler[i].getKalkisYeri()<<"   "
						 <<seferler[i].getVarisYeri()<<endl;
			yolcuSeferYaz<<endl<<"Ad - Soyad - KoltukNo"<<endl;
			// o seferdeki toplam yolcu sayýsý kadar dön
			for(int j=1;j<=boyut;j++){
				if(yolcular[j].getYolcuNo()!=0 && yolcular[j].getSeferNo()==i){
					yolcuSeferYaz<<yolcular[j].getAd()<<"   "
								 <<yolcular[j].getSoyad()<<"   "
								 <<yolcular[j].getKoltukNo()<<endl;
				}
			}
			yolcuSeferYaz<<endl;
		}
	}
}

// soforleri ekrana yazan fonksiyon
void soforListesi(sofor soforler[],int boyut){
	int soforSay=0;
	// sofor sayisini bul
	for(int i=1;i<=boyut;i++){
		if(soforler[i].getSoforNo()!=0)
			soforSay++;
	}
	// sofor varsa
	if(soforSay>0){
		cout<<endl<<"SoforNo - Ad - Soyad - Maas"<<endl;
		// sofor listesini ekrana yaz
		for(int i=1;i<=boyut;i++){
			if(soforler[i].getSoforNo()!=0)
				soforler[i].soforYaz();
		}
	}
	else
		cout<<"KAYITLI SOFOR BULUNAMADI"<<endl;
	

}

// sofor ekleme fonksiyonu
void soforEkle(sofor soforler[],int boyut){
	int soforIndis=-1,maas,bulundu=0,sn;
	string ad,soyad;
	// boþ sofor indisini bul
	for(int i=1;i<=boyut;i++){
		if(soforler[i].getSoforNo()==0){
			soforIndis=i;
			break;
		}
	}
	
	// daha önce alýnmamýþ sofor no bul
		do{
			cout<<"Sofor no : ";
			cin>>sn;
			if(sn<=0){
				cout<<"sofor no 0 veya küçük olamaz"<<endl;
				bulundu=1;
			}
			else{
				bulundu=0;
				for(int i=1;i<=boyut;i++){
					// sefer no daha onceden alinmis mi ?
					if(soforler[i].getSoforNo()==sn){
						cout<<"Bu sofor no daha onceden alinmis"<<endl;
						bulundu=1;
					}
				}
			}
		}while(bulundu==1);
	
	// boþ indis'e þofor bilgilerini ekle
	if(soforIndis!=-1){
		cout<<"Sofor Ad : ";
		cin>>ad;
		cout<<"Sofor Soyad : ";
		cin>>soyad;
		// maasý kontrol et	
		do{
			cout<<"Maas : ";
			cin>>maas;
			if(maas<2000)
				cout<<"MAAS ASGARI UCRETTEN KUCUK OLAMAZ(2000 TL)"<<endl;
		}while(maas<2000);
		soforler[soforIndis].setSoforNo(sn);
		soforler[soforIndis].setSoyad(soyad);
		soforler[soforIndis].setAd(ad);
		soforler[soforIndis].setMaas(maas);
	}
	soforler[soforIndis].soforYaz();
	cout<<"YUKARIDAKÝ BÝLGÝLERE AÝT ÞOFOR KAYDI TAMAMLANDI"<<endl;
}

// sofor silme fonksiyonu
void soforSil(sofor soforler[],int boyut){
	int soforSay=0;
	// sofor sayisini bul
	for(int i=1;i<=boyut;i++){
		if(soforler[i].getSoforNo()!=0)
			soforSay++;
	}
	
	if(soforSay>0){
		int sn,silIndis=-1;
		soforListesi(soforler,100);
		cout<<"Silinecek sofor no : ";
		cin>>sn;
		if(sn>0){
			// silinecek indisi bul
			for(int i=1;i<=boyut;i++){
				if(soforler[i].getSoforNo()==sn){
					silIndis=i;
					break;
				}
			}
			// sofor bilgilerini sil
			if(silIndis!=-1){
				soforler[silIndis].setAd(" ");
				soforler[silIndis].setMaas(0);
				soforler[silIndis].setSoforNo(0);
				soforler[silIndis].setSoyad(" ");
				cout<<"SOFOR BILGILERI SILINDI"<<endl;
			}	
			else
				cout<<"Böyle bir sofor yok"<<endl;
		}
		else if(sn<=0)
			cout<<"Sofor no 0'dan küçük olamaz"<<endl;
	}
	else
		cout<<"KAYITLI SOFOR BULUNAMADI"<<endl;
		
}

// sofor bilgilerin dosyadan okuyan fonksiyon
void soforOku(sofor soforler[],int boyut){
	// soforler dosyasýný okuma modunda aç yoksa oluþtur
	ifstream soforOku("soforler.txt",ios::in);
	if(!soforOku){
		ofstream soforOlustur("soforler.txt",ios::out);
		if(!soforOlustur){
			cout<<"SOFOR OKU DOSYA ACILAMADI"<<endl;
			exit(1);
		}
	}
	// geçici deðiþkenler
	int sn,maas,x=1,soforSay=0;
	string ad,soyad;
	// dosyadan soforleri oku
	while(soforOku>>sn>>ad>>soyad>>maas){
		sofor gecici(sn,ad,soyad,maas);
		soforler[x]=gecici;
		x++;
	}
	soforOku.close();
	cout<<"SOFORLER DOSYADAN OKUNDU"<<endl;
	
	// sofor sayýsýný bul
	for(int i=1;i<=boyut;i++){
		if(soforler[i].getSoforNo()!=0)
			soforSay++;
	}
	
	cout<<"TOPLAM "<<soforSay<<" ADET SOFOR KAYDI BULUNMAKTADIR"<<endl;
}

// soforleri dosyaya yazan fonksiyon
void soforYaz(sofor soforler[],int boyut){
	ofstream soforYaz("soforler.txt",ios::out);
	if(!soforYaz){
		cout<<"SOFOR YAZ DOSYA ACILAMADI"<<endl;
		exit(1);
	}
	// soforleri dosyaya yaz
	for(int i=1;i<=boyut;i++){
		if(soforler[i].getSoforNo()!=0){
			soforYaz<<soforler[i].getSoforNo()<<" "
					<<soforler[i].getAd()<<" "
					<<soforler[i].getSoyad()<<" "
					<<soforler[i].getMaas()<<endl;
		}
	}
	soforYaz.close();
}

// sefer iþlemlerini yöneten switch
void seferIslem(){
	int secim=0;
	do{
		secim=seferMenu();
		switch(secim){
			case 1: seferListele(seferler,100);
					break;
			case 2: seferEkle(seferler,100);
					seferYaz(seferler,100);
					break;
			case 3: seferSil(seferler,100);
					seferYaz(seferler,100);
					break;
			case 4: seferGuncelle(seferler,yolcular,100);
					seferYaz(seferler,100);
					break;
			case 5: cout<<"ANA MENUYE DONULUYOR!!\n"<<endl;
					seferYaz(seferler,100);
					break;
			default: cout<<"Yanlis Secim Yaptiniz.."<<endl;
					break;
		}
	}while(secim!=5);
}

// yolcu iþlemlerini yöneten switch
void yolcuIslem(){
	int secim=0;
	do{
		secim=yolcuMenu();
		switch(secim){
			case 1: yolcuListesi(seferler,yolcular,100);
					break;
			case 2: sadeceYolcuListele(yolcular,100);
					break;
			case 3: yolcuSil(yolcular,100);
					yolcuYaz(seferler,yolcular,100);
					yolcuSeferYaz(seferler,yolcular,100);
					break;
			case 4: cout<<"ANA MENUYE DONULUYOR\n"<<endl;
					yolcuYaz(seferler,yolcular,100);
					yolcuSeferYaz(seferler,yolcular,100);
					break;
			default: cout<<"YANLIS SECIM YAPTINIZ!!"<<endl;
					break;
		}
	}while(secim!=4);
}

// sofor iþlemlerini yöneten switch
void soforIslem(){
	int secim=0;
	do{
		secim=soforMenu();
		switch(secim){
			case 1: soforListesi(soforler,100);
					break;
			case 2: soforEkle(soforler,100);
					soforYaz(soforler,100);
					break;
			case 3: soforSil(soforler,100);
					soforYaz(soforler,100);
					break;
			case 4: cout<<"ANA MENUYE DONULUYOR\n"<<endl;	
					break;
			default: cout<<"YANLIS SECIM YAPTINIZ!!"<<endl;
					break;
		}
	}while(secim!=4);
}

// main program
int main(){
	setlocale(LC_ALL,"Turkish");	// türkçe karekter 
	int secim=0;
	// program baslangicinda dosyadaki verileri oku
	seferOku(seferler,100);
	yolcuOku(seferler,yolcular,100);
	soforOku(soforler,100);
	do{
		secim=anaMenu();
		switch(secim){
			case 1: seferIslem();
					break;
			case 2: yolcuIslem();
					break;
			case 3: soforIslem();
					break;
			case 4: biletSatis(seferler,yolcular,100);
					seferYaz(seferler,100);
					yolcuYaz(seferler,yolcular,100);
					break;
			case 5: cout<<"Program Kapaniyor!!"<<endl;
					seferYaz(seferler,100);
					soforYaz(soforler,100);
					yolcuYaz(seferler,yolcular,100);
					yolcuSeferYaz(seferler,yolcular,100);
					break;
			default: cout<<"YANLIS SECIM LUTFEN YENIDEN SECIM YAPIN!!"<<endl<<endl;
			break;
		}
	}while(secim!=5);
	return 0;
}
