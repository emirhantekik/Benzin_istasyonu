#include "Akaryakit.h"

Akaryakit::Akaryakit(){
	litre=0;
	tl=0;
	choice=0;
}
Akaryakit::Akaryakit(const Akaryakit& obj){
	litre=obj.litre;
	tl=obj.tl;
	choice=obj.choice;
}

Akaryakit& Akaryakit::operator=(const Akaryakit& obj){
	litre=obj.litre;
	tl=obj.tl;
	choice=obj.choice;
	return *this;
}
double operator+( Akaryakit& obj1, Akaryakit& obj2){
	return (obj1.get_tl()+obj2.get_tl());
}
double operator+(double a, Akaryakit& obj){
	return(a+obj.get_tl());
}
ostream& operator<<(ostream& o, const Akaryakit& obj){
	switch(obj.choice){
			case 1:
				o<<endl<<obj.tl<<" TL tutarinda "<<obj.litre<<" litre benzin aldiniz."<<endl;
				break;
			case 2:
				o<<endl<<obj.tl<<" TL tutarinda "<<obj.litre<<" litre motorin aldiniz."<<endl;
				break;
			case 3:
				o<<endl<<obj.tl<<" TL tutarinda "<<obj.litre<<" litre LPG aldiniz."<<endl;
				break;
		}
	return o;
}
	
void Akaryakit::satis(){
	double temp;
	string s;
	cout<<"\n1-Benzin\t"<<benzin<<endl<<"2-Motorin\t"<<motorin<<endl<<"3-LPG\t\t"<<lpg<<endl;
	cout<<"Hangi tur akaryakit almak istiyorsunuz? ";
	cin>>choice;
	try{
		if(choice!=1&&choice!=2&&choice!=3){throw(choice);}
	}
	catch(int a){
		cin.clear();
		cin.ignore(100,'\n');	
		cout<<"Lutfen gecerli bir deger giriniz! "<<endl;
		cin>>choice;
		if(choice!=1&&choice!=2&&choice!=3){
			while(choice!=1&&choice!=2&&choice!=3){
				cin.clear();
				cin.ignore(100,'\n');
				cout<<"Gecerli bir sayi giriniz!!"<<endl;
				cin>>choice;
			}
		}
	}
	cout<<"Ne kadar almak istiyorsunuz?(orn: '50 tl','5 lt')  ";
	cin>>temp;
	try{
		if(temp<=0){throw(temp);}
	}
	catch(double b){
		cin.clear();
		cin.ignore(100,'\n');
		cout<<"Gecerli bir sayi giriniz!!"<<endl;
		cin>>temp;
		if(temp<=0){
			while(temp<=0){
				cin.clear();
				cin.ignore(100,'\n');
				cout<<"Gecerli bir sayi giriniz!!"<<endl;
				cin>>temp;
			}
		}
	}
	cin>>s;
	try{
		if(!(s=="lt"||s=="tl")){throw(s);}
	}
	catch(string ss){
		cin.clear();
		cin.ignore(100,'\n');
		cout<<"Gecerli bir secim girin(tl/lt) ";
		cin>>s;
		if(!(s=="lt"||s=="tl")){
			while(!(s=="lt"||s=="tl")){
				cin.clear();
				cin.ignore(100,'\n');
				cout<<"Gecerli bir secim girin(tl/lt) ";
				cin>>s;
				
			}
		}
	}
	if(s=="lt"){
		litre=temp;
		switch(choice){
			case 1:
				tl=benzin*litre;
				break;
			case 2:
				tl=motorin*litre;
				break;
			case 3:
				tl=lpg*litre;
				break;
			default:
				break;
		}
	}
	else{
		tl=temp;
		switch(choice){
			case 1:
				litre=tl/benzin;
				break;
			case 2:
				litre=tl/motorin;
				break;
			case 3:
				litre=tl/lpg;
				break;
			default:
				break;
		}
	}
}
double Akaryakit::get_litre(){return litre;}
double Akaryakit::get_tl(){return tl;}
int Akaryakit::get_choice(){return choice;}
