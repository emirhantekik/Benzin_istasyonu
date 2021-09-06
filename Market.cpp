#include <iostream>
#include <string>
#include "Market.h"

using namespace std;

ostream& operator<<(ostream& os, const Market& other) {
	
	for(int i=0;i<other.urunSize;i++){
		os<<"ID:"<<other.idPtr[i]<<" "<<"Urun adi:"<<other.urunPtr[i]<<" "<<"Fiyat:"<<other.fiyatPtr[i]<<"TL "<<other.adetPtr[i]<<" tane "<<endl;;
	}
	
	return os;
}

Market::Market(){
	
	urunSize =5;
	toplam_fiyat=0.00;
	
	urunPtr = new string[ urunSize ]; // create space for pointer-based array
	idPtr = new int[urunSize];
	adetPtr = new int[urunSize];
	fiyatPtr = new double[urunSize];
	
	for ( int i=0;i<urunSize;++i){
		urunPtr[ i ]= "Bilgi Yok";
		idPtr[ i ]= 0;
		adetPtr[ i ]= 0;
		fiyatPtr[ i ]= 0.00;
	}
}

void Market_alinanlar::set_toplam_fiyat(double a){
	toplam_fiyat=toplam_fiyat+a;
}

double Market_alinanlar::get_toplam_fiyat(){
	return toplam_fiyat;
}

void Market::set_urunPtr(string a[],int b){
	
	urunSize=b;
	urunPtr=new string[urunSize];
	
	for(int i=0;i<urunSize;i++){
		urunPtr[i]=a[i];
	}
	
}

void Market::set_fiyatPtr(double a[],int b){
	
	urunSize=b;
	fiyatPtr=new double[urunSize];
	
	for(int i=0;i<urunSize;i++){
		fiyatPtr[i]=a[i];
	}
	
}

void Market::set_adetPtr(int a[],int b){
	
	urunSize=b;
	adetPtr=new int[urunSize];
	
	for(int i=0;i<urunSize;i++){
		adetPtr[i]=a[i];
	}
	
}

void Market::set_idPtr(int a[],int b){
	
	urunSize=b;
	idPtr=new int[urunSize];
	
	for(int i=0;i<urunSize;i++){
		idPtr[i]=a[i];
	}
	
}

/*Kullanýcýnýn seçimini döndürüp toplam tutara ekleyecek*/

double Market::operator[](int gelendeger) const{
	if (gelendeger<0 || gelendeger>=urunSize){
		exit;}
	return fiyatPtr[gelendeger];
}

int Market::get_adetPtr(int a){
	return adetPtr[a];
}

//Kullanýcý ürün aldýktan sonra tekrar kullanýcýya ekran bastýrýldýðýnda üründen kalan adet miktarýný hesaplayacak.
void Market::kalan_adet(int a,int b){
	
	adetPtr[a]=adetPtr[a]-b;
	
}
//fonksiyon sonu


string Market::get_urunPtr(int a){
	return urunPtr[a];
}

int Market::get_urunSize(){
	return urunSize;
}

void Market::show_Market(){
	
	for(int i=0;i<urunSize;i++){
		cout<<"ID:"<<idPtr[i]<<" "<<"Urun adi:"<<urunPtr[i]<<" "<<"Fiyat:"<<fiyatPtr[i]<<"TL "<<adetPtr[i]<<"tane "<<endl;
	}
}

/*marketten alýnanlarý tutan class*/

Market_alinanlar::Market_alinanlar(){
	
	urunlerSize=5;
	urunlerPtr=new string[urunlerSize];
	urunAdetPtr=new int[urunlerSize];
	
	for(int i=0;i<urunlerSize;i++){
		urunlerPtr[i]="Bilgi Yok";
		urunAdetPtr[i]=0;
   	}
}

Market_alinanlar& Market_alinanlar::operator=(Market& other){
	
	urunlerSize=other.get_urunSize();
	
	urunlerPtr=new string[urunlerSize];
	
	for(int i=0;i<urunlerSize;i++){
		urunlerPtr[i]=other.get_urunPtr(i);
	}
	
}

void Market_alinanlar::show_Markett(){
	for(int i=0;i<urunlerSize;i++){
		cout<<urunlerPtr[i]<<" ";
	}
}

void Market_alinanlar::set_urunAdetPtr(int a,int b){
	if(a==0){urunAdetPtr[a]=urunAdetPtr[a]+b;}
	if(a==1){urunAdetPtr[a]=urunAdetPtr[a]+b;}
	if(a==2){urunAdetPtr[a]=urunAdetPtr[a]+b;}
	if(a==3){urunAdetPtr[a]=urunAdetPtr[a]+b;}
	if(a==4){urunAdetPtr[a]=urunAdetPtr[a]+b;}
}

void Market_alinanlar::alisveris_listesi(){
	cout<<"Alisveris listeniz asagidaki gibidir\n";
	for(int i=0;i<urunlerSize;i++){
		if(urunAdetPtr[i]!=0){
			cout<<"Alisveris listenizde "<<urunAdetPtr[i]<<" adet "<<urunlerPtr[i]<<" vardir.\n";
		}
	}
}
