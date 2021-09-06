#ifndef MARKET_H
#define MARKET_H

#include <string>
using namespace std;

class Market{
	
	friend ostream& operator<<(ostream& , const Market&) ;
	friend istream& operator>>(istream&, Market& );
	
	private:
	
		int urunSize;
		int *idPtr;
		int *adetPtr;
		double *fiyatPtr;
		string *urunPtr;
		
		double toplam_fiyat;
	
	public:
	
		Market();
		Market(int,int,int);
		Market& operator=(const Market&);
		
		double operator[]( int ) const; 
		void set_urunPtr(string[],int);
		void set_fiyatPtr(double[],int);
		void set_adetPtr(int[],int);
		void set_idPtr(int[],int);
		
		int get_adetPtr(int);//Kullanýcý almak istedigi adeti girdiginde elimizde o kadar adet olup olmadýðýný kontrol edecek fonksiyon
		void kalan_adet(int,int);//kullanýcýnýn seçtiði ürün ilk parametre, aldýðý adet 2. parametre. Kullanýcý eðer bir daha seçim yapmak isterse adet azaltarak gidecek
		int get_urunSize();
		string get_urunPtr(int);
		
		
		void show_Market();
};

class Market_alinanlar: public Market{
	
	public:
		
		Market_alinanlar();		
		Market_alinanlar& operator=(Market&);
		void show_Markett();
		void alisveris_listesi();//son çýktý
		void set_urunAdetPtr(int,int);
		
		void set_toplam_fiyat(double);
		double get_toplam_fiyat();
		int urunlerSize; 
		string *urunlerPtr;
		int *urunAdetPtr;
		double toplam_fiyat;		
		
	private:

};

#endif



