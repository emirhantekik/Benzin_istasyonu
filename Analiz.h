#ifndef Analiz_H
#define Analiz_H
#include "Market.h"
#include "Akaryakit.h"
class oto_yikama{
	public:
		oto_yikama();
		oto_yikama(double);
		void purchase();
		double get_Purchase();
		int get_kopukSayi();
		int get_icSayi();
		int get_disSayi();
		
	private:
		double kopukFiyat = 10;
		double icYikama = 20;
		double disYikama = 5;
		double thisPurchase;
		
		int kopukSayi;
		int icSayi;
		int disSayi;
};
class analiz{
	public:
		analiz();
		Market_alinanlar ma1;
		oto_yikama oy;
		void akaryakit_analiz(Akaryakit* ptr,int a);
		void oto_analiz();
		void showMostPurchased();
		void showAllPurchases();
		void showStock();
		analiz& operator+=(double i);
		friend ostream& operator<<(ostream &output, const analiz& p1);
	private:
		double randomnumber;
		double otoGelir;
};


class musteri{
	public:
		musteri();
		musteri& operator=(const musteri& p1);
		musteri& operator+=(double i);
		friend ostream& operator<<(ostream &output, const musteri& p1);
		double get_Tutar();
	private:
		double toplamTutar;
};
#endif
