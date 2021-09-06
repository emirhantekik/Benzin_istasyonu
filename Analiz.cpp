#include "Analiz.h"
#include "Market.h"
#include "Akaryakit.h"
using namespace std;
#include <iostream>
analiz::analiz(){
	randomnumber=0;
	otoGelir=0;
}
void analiz::showAllPurchases(){
	for(int i=0;i<ma1.urunlerSize;i++){
		if(ma1.urunAdetPtr[i]!=0){
			cout<<ma1.urunlerPtr[i]<<" "<<ma1.urunAdetPtr[i]<<" kere satildi."<<endl;	}
	}
	return;
}



void analiz::showMostPurchased(){
	int temp=0;int tempid=0;int i=0;
	while( i<5){
		if(ma1.urunAdetPtr[i]>temp){
			temp=ma1.urunAdetPtr[i];
			tempid=i;
		}
		i++;
	}
	cout<<"En cok satilan urun: "<<ma1.urunlerPtr[tempid]<<" ("<<ma1.urunAdetPtr[tempid]<<")"<<endl;
	return;
}
analiz& analiz::operator+=(double i){
	randomnumber=randomnumber+i;
	return *this;
}
ostream& operator<<(ostream &output, const analiz& p1){
	output<<"Market bolumu toplam gelir: "<<p1.randomnumber<<" tl."<<endl;
	return output;
}

void analiz::akaryakit_analiz(Akaryakit* ptr,int a){
        double total=0,lpg=0,benzin=0,motorin=0,lpg_lt=0,benzin_lt=0,motorin_lt=0;
        int benz_ch=0,lpg_ch=0,mot_ch=0;
        for(int i=0;i<=a;i++){
            if(ptr[i].get_choice()==1){
                benzin+=ptr[i].get_tl();
                benzin_lt+=ptr[i].get_litre();
                benz_ch++;
            }
            if(ptr[i].get_choice()==2){
                motorin+=ptr[i].get_tl();
                motorin_lt+=ptr[i].get_litre();
                mot_ch++;
            }
            if(ptr[i].get_choice()==3){
                lpg+=ptr[i].get_tl();
                lpg_lt+=ptr[i].get_litre();
                lpg_ch++;
            }
            total=total+ptr[i];
        }
        cout<<endl<<"Toplam "<<benzin_lt<<" litre, "<<benzin<<" TL Benzin alinmis. "<<benz_ch<<" kere tercih edilmis."<<endl;
        cout<<"Toplam "<<motorin_lt<<" litre, "<<motorin<<" TL Benzin alinmis. "<<mot_ch<<" kere tercih edilmis."<<endl;
        cout<<"Toplam "<<lpg_lt<<" litre, "<<lpg<<" TL Benzin alinmis. "<<lpg_ch<<" kere tercih edilmis."<<endl;
        cout<<"\tToplam akaryakit harcamasi: "<<total<<"TL"<<endl<<endl;
}

oto_yikama::oto_yikama(){
	thisPurchase=0;
	icSayi=0;
	disSayi=0;
	kopukSayi=0;}
double oto_yikama::get_Purchase(){
	return thisPurchase;}
void oto_yikama::purchase(){
	int choice;
	cout<<"1.Kopuk: 10 tl"
		<<"\n2.Ic Yikama: 20 tl"
		<<"\n3.Dis Yikama: 5 tl"
		<<"\nLutfen seceneginizi giriniz."<<endl;
	cin>>choice;
	
	try{
		if(choice!=1&&choice!=2&&choice!=3){throw(choice);}
	}
	catch(int a){
		cin.clear();
		cin.ignore(100,'\n');
		if(choice!=1&&choice!=2&&choice!=3){
			while(choice!=1&&choice!=2&&choice!=3){
				cout<<"Gecerli bir islem girin."<<endl;
				cin>>choice;
			}
		}
	
	}
	switch(choice){
		case 1:{
			
			kopukSayi++;
			cout<<"Tutar: 10 tl"<<endl;
			thisPurchase=10;
			break;}
		case 2:{
		
			icSayi++;
			cout<<"Tutar: 20 tl"<<endl;
			thisPurchase=20;
			break;}
		case 3:{
		
			disSayi++;
			cout<<"Tutar: 5 tl"<<endl;
			thisPurchase=5;
			break;}
	}
}
int oto_yikama::get_icSayi(){return icSayi;}
int oto_yikama::get_disSayi(){return disSayi;}
int oto_yikama::get_kopukSayi(){return kopukSayi;}


void analiz::oto_analiz(){
	otoGelir=oy.get_disSayi()*5+oy.get_icSayi()*20+oy.get_kopukSayi()*10;
	cout<<"Kopuk yikama sayisi: "<<oy.get_kopukSayi()
		<<"\nIc yikama sayisi: "<<oy.get_icSayi()
		<<"\nDis yikama sayisi: "<<oy.get_disSayi()
		<<"\nToplam yikama geliri: "<<otoGelir<<"TL"<<endl;
	return;
}
musteri::musteri(){
	toplamTutar=0;
}
musteri& musteri::operator=(const musteri& p1){
	toplamTutar=p1.toplamTutar;
	return *this;
}
musteri& musteri::operator+=(double i){
	toplamTutar= toplamTutar+i;
	return*this;

}
double musteri::get_Tutar(){return toplamTutar;}
ostream& operator<<(ostream &output, const musteri& p1){
	output<<"Toplam tutariniz: "<<p1.toplamTutar<<" tl"<<endl;
	return output;
}

