#include "Analiz.h"

int main(){
	int x=10, a=0;
	double total=0;
	Market m1;
	analiz A;
	int sayac;
	int analiz_choice;
	string Markett[]= {"Cikolata","Deterjan","Biskuvi","Kolonya","Mendil"};
	double Markett_fiyat[] = {2.5,17.25,3.25,5.75,1.25};
	int Markett_adet[] = {200,300,400,500,600};
	int Markett_id[]={1,2,3,4,5};
	
	/*Dinamik hafýzaya aktarýldý*/
	m1.set_urunPtr(Markett,5);
	m1.set_fiyatPtr(Markett_fiyat,5);
	m1.set_adetPtr(Markett_adet,5);
	m1.set_idPtr(Markett_id,5);
	

	/* *************************** */
	
	A.ma1=m1;
	Akaryakit *Aptr= new Akaryakit[10];
	musteri *mustPtr= new musteri[10];
	int j=0;
	
	cout<<"\n\tHOSGELDINIZ"<<endl<<"1-Market"<<endl<<"2-Akaryakit"<<endl<<"3-Oto yikama"<<endl<<"4-Istatistik"<<endl<<endl<<"Cikmak icin '9' girin"<<endl<<"Yapmak istediginiz islemi secin--> ";
	while(x!=9){
		
		cin>>x;
		try{
		if(x!=1&&x!=2&&x!=3&&x!=4&&x!=5&&x!=9){throw(x);}
		}
	catch(int b){
		cin.clear();
		cin.ignore(100,'\n');
		cout<<"Gecerli bir islem girin."<<endl;
		cin>>x;
		while(x!=1&&x!=2&&x!=3&&x!=4&&x!=5&&x!=9){
			cin.clear();
			cin.ignore(100,'\n');
			cout<<"Gecerli bir islem girin."<<endl;
			cin>>x;
		}
	}
		switch(x){
			case 1:{
				
			int secim;
			int secim1;
			int secim2;
			string throwStr="Lutfen 1-5 arasindaki urunlerden birini giriniz!!!"; // exception-handling için hata mesajý
			string throwStrr="Elimizde o kadar urun yoktur!!!";
			string throwStrrr="Lutfen dogru secim giriniz!!!";
	
			bool done = false;//while döngüsünden çýkabilmek için kullanýlacaktýr.

			do{
				try{
					cout<<"\nMarkette bulunan urunler ve bilgileri asagidaki gibidir\n\n";
					cout<<m1;
					cout<<"\nLutfen almak istediginiz urunu giriniz:";
					cin>>secim;
					if(!cin || secim>=6 || secim<0){throw throwStr;}
					else throw(secim);
				}//try sonu
	
				catch(string& s){
				cerr<<s<<endl;
				cin.clear();
				cin.ignore(100,'\n');
				}//catch sonu
		
				catch(...){

					try{
						cout<<"Kac adet almak istiyorsunuz?"<<endl;
						cin>>secim2;
						if(secim2>m1.get_adetPtr(secim-1) || secim2<0){
						throw throwStrr;
						}
						else if(!cin){throw(throwStrrr);}
						else {
						throw(secim2);
						}
				
					}//catch içindeki try sonu
					catch(string& s){
					cerr<<s<<endl;
					cin.clear();
					cin.ignore(100,'\n');
					}//try-catch içindeki catch sonu
			
					catch(...){
					cout<<"Alisveris listenize eklenmistir.\n";
					m1.kalan_adet(secim-1,secim2);
					A.ma1.set_toplam_fiyat(m1[secim-1]*secim2);
					cout<<"Alisveris sepetiniz su anda "<<A.ma1.get_toplam_fiyat()<<" TL tutmaktadir."<<endl;
					A.ma1.set_urunAdetPtr(secim-1,secim2);
				
					}//try-catch içindeki catch sonu
		
			
		
			
		}//catch sonu
		
		basadonn:
		
		cout<<"\nBaska islem yapmak istiyor musunuz? \n1)EVET 2)HAYIR"<<endl;
		cin>>secim1;
		if(!cin || secim1>2) goto basadonn;
		else if(secim1==1) done=false;
		else done=true;
		}while(!done);
	
		A.ma1.alisveris_listesi();
		cout<<"Market alisverisiniz "<<A.ma1.get_toplam_fiyat()<<" TL tutmaktadir.\n\n";
		A+=A.ma1.get_toplam_fiyat();
		mustPtr[j]+=A.ma1.get_toplam_fiyat();
				break;}
			case 2:{
				Aptr[a].satis();
				cout<<Aptr[a];
				total=total+Aptr[a];
				mustPtr[j]+=Aptr[a].get_tl();
				a++;
				break;}
			case 3:{
				A.oy.purchase();
				mustPtr[j]+=A.oy.get_Purchase();
				break;}
			case 4:{
				cout<<"1.Market analiz"
					<<"\n2.Yikama analiz"
					<<"\n3.Akaryakit analiz\n?"<<endl;
				cin>>analiz_choice;
				cout<<endl;
					try{
				if(analiz_choice!=1&&analiz_choice!=2&&analiz_choice!=3){throw(analiz_choice);}
					}
				catch(int m){
				cin.clear();
				cin.ignore(100,'\n');	
				while(analiz_choice!=1&&analiz_choice!=2&&analiz_choice!=3){
					cout<<"Gecerli bir islem girin."<<endl;
					cin>>analiz_choice;
					} 
				}
				switch(analiz_choice){
					case 1:{
						A.showAllPurchases();
						A.showMostPurchased();
					//	A.showStock();
						cout<<A<<endl;
						break;
					}
				
					case 2:{
						A.oto_analiz();
						break;
					} 
					case 3:{
						A.akaryakit_analiz(Aptr,a);
						break;
					}
			}
			break;
			}
			case 5: {
				cout<<mustPtr[j]<<endl;
				break;
			}
			case 9:
				break;
		}
		cout<<endl<<"1-Market"<<endl<<"2-Akaryakit"<<endl<<"3-Oto yikama"<<endl<<"4-Istatistik"<<endl<<"5-Toplam harcama"<<endl<<endl<<"Cikmak icin '9' girin"<<endl<<"Yapmak istediginiz islemi secin--> ";
			
	}
	return 0;
}


