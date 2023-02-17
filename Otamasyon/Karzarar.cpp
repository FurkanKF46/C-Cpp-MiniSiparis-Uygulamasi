
#include<iostream>
#include <string>
#include <cstdlib>
#include<time.h>
#include<math.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include <sstream> 
#include <cstring>
#include <windows.h>
using namespace std;
void AnaTema(void);
void Gunsonugorme(void);
void yeniurun(void);
void guncelleme(void);
void gelir(void);
void ayarlar(void);
static int konum=1;
void renk(void);
void siparis(void);
void hesapsip(void);
int toplam=0;
static int k1=0;
static int tg=0;
static int gso=0;
static int k2=0;
int toplam1;
int kod;
static int h=0;
static int r=0;
string Renk="Varsayýlan";
int rapor[7];
static int p=0;
int secim1;
static int toplam4=0;
string adi;
string fiyat;
int ekstra;
static	 int e=0;
int	hesapfiyat[20];
static int siparisadet[100];
static int okuma=0;
static int okuma2=0;
int t=0;
static int hp=0;
static int carpim[100];
string hesapurun[20];
int n;
string yfiyat;
void gotoxy(short x,short y)
{
COORD pos={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main () {
	setlocale(LC_ALL, "Turkish");
do {
	AnaTema();
	for (int y=3;y<23;y++)
{
gotoxy(5,y);
cout<<"|";
gotoxy(70,y);
cout<<"|";
}
	gotoxy(25,3);
	cout<<"******************************"<<endl;
	gotoxy(25,4);cout<<"*                            *"<<endl;
	gotoxy(25,5);cout<<"*         HOÞGELDÝN          *"<<endl;
	gotoxy(25,6);cout<<"*                            *"<<endl;
	gotoxy(25,7);cout<<"******************************"<<endl;
	cout<<endl;
	gotoxy(14,9);
    cout<<"Yapmak istediðiniz iþlem için iþlemin kodunu giriniz: "<<endl;
	gotoxy(20,12);cout<<"Fiyat Listesine yeni ürün eklemek için: 1"<<endl;
	gotoxy(20,14);cout<<"Fiyat listesini güncellemek için: 2"<<endl;
	gotoxy(20,16);cout<<"Gün sonu kasa hesaplamasý için: 3"<<endl;
	gotoxy(20,18);cout<<"Sipariþ girmek için: 4"<<endl;
	gotoxy(20,20);cout<<"Tüm gelirleri görmek için: 5"<<endl;
	gotoxy(20,22);cout<<"Sistem ayarlarý için: 6"<<endl;
	gotoxy(20,24);cout<<"Çýkýþ yapmak için: 0"<<endl;
	cin>>secim1;
	if(secim1==1) {
		system("cls");
		AnaTema();
		yeniurun();
		getch();
		system("cls");
	}
	else if(secim1==2) {
		system("cls");
		AnaTema();
		guncelleme();
		getch();
			system("cls");
	}
	else if(secim1==3) {
		system("cls");
		AnaTema();
		gelir();
		getch();
			system("cls");
	}
else if(secim1==4) {
        system("cls");
        AnaTema();
        siparis();
	
}
	else if(secim1==6) {
		ayarlar();
	}
	else if(secim1==5) {
		system("cls");
		AnaTema();
		Gunsonugorme();
	}
} 
while(0<secim1);
	exit(0);
}
//                                      MENÜ RENGÝ AYARI
void renk()
{
	
	
char colorcode;
AnaTema();
string MenuItem[5];
MenuItem[0]="Lütfen Renk Seçimizi yapýnýz.";
MenuItem[1]="1-] Kýrmýzý";
MenuItem[2]="2-] Mavi";
MenuItem[3]="3-] Yeþil";
MenuItem[4]="4-] Beyaz";
for (int menu=0;menu<5;menu++)
cout<<MenuItem[menu]<<endl;
cout<<"Yapmak istediðiniz iþlemi seçiniz:";
colorcode=getch();
switch(colorcode)
{
case '1': system("color 4");
Renk="Kýrmýzý";
break;
case '2': system("color 1");
Renk="Mavi";
break;
case '3': system("color 2");
Renk="Yeþil";
break;  
case '4': system("color 7");
Renk="Beyaz";
break;  
    }


}
//                                  ANA MENÜ AYARI
void AnaTema()
{
system("CLS");
/*cout<<system("echo %date%")<<endl;*/
time_t now=time(0);
cout<<ctime(&now);

gotoxy(57,0);
cout<<"Sistem Rengi:"+Renk<<endl;
cout<<" "<<endl;
}
//                                           YENÝ ÜRÜN EKLEME AYARI
void yeniurun() {
	cout<<"Kaç tane yeni ürün girmek istiyorsunuz:"<<endl;
	cin>>n;
	char liste[n][20];
	for(int i=0;i<n;i++) {
		cout<<i+1<<". yeni ürünü giriniz"<<endl;
		cin>>liste[i];
	}
	ofstream list;
	list.open("Fiyatlar.txt",ios::app);
	for(int i=0;i<n;i++){
		cout<<liste[i]<<" ürünün fiyatini giriniz: "<<endl;
		cin>>yfiyat;
		list<<endl<<liste[i]<<setw(20)<<yfiyat; 
	}
	list.close();
	cout<<"Ýþlem tamamlandý. Üst menüye dönmek için Enter tuþuna basýnýz."<<endl;


}
//                                            FÝYAT GÜNCELLEME AYARI
 void guncelleme() {
 	if(k2==1) {
 		cout<<"Fiyatý güncelleyebilmek için programý yeniden baþlatýnýz";
	 }
	 else {
	 
    char urunler[20][10];
    char fiyatlar[20][10];
    int yeni;
    int a;
    static int s=0;
	ifstream urun("Fiyatlar.txt");
	if(!urun) {
	cout<<"Fiyat Listesi bulunamadý!!!! Fiyat listesi giriniz"<<endl<<" Üst menüye dönmek için enter tuþuna basýnýz"<<endl;
	return;
}
	else {
	
    while(!(urun.eof())) {
    	urun>>urunler[s]>>fiyatlar[s];
    	s++;
	}
	urun.close();
		remove("Fiyatlar.txt");
	ofstream yaz("Fiyatlar.txt",ios::app);
	for(int i=0;i<s;i++) {
	cout<<urunler[i]<<" ürünün kodu: "<<i+1<<setw(20);
	if(i%3==0)
	cout<<""<<endl;
}
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
		cout<<"Deðiþtirmek istediðiniz ürünün numarasýný giriniz:"<<endl;
	cin>>a;
	for(int i=0;i<s;i++) {
		if(i==a){
	cout<<urunler[i]<<" ürünün eski fiyatý:"<<fiyatlar[i]<<endl;
	cout<<"Yeni fiyati giriniz: "<<endl;
	cin >>fiyatlar[i];
	}
}
		for(int j=0;j<s;j++) {
			yaz<<endl<<urunler[j]<<setw(20)<<fiyatlar[j];
	}
	yaz.close();
	k2++;
	cout<<"Ýþlem tamamlandý. Üst menüye dönmek için Enter tuþuna basýnýz."<<endl;
}
}
}
//                                                  GELÝR HESAPLAMA AYARI
void gelir() {
int toplamf[20];
int toplamgelir=0;
ifstream Gelir("gelir.txt");
while(!(Gelir.eof())) {
	Gelir>>toplamf[e];
	e++;
}
Gelir.close();
while(tg<e-1) {
	toplamgelir= toplamgelir+toplamf[tg];
	tg++;
	cout<<toplamgelir<<endl;
}
time_t now=time(0);
ofstream gunsonu("gunsonu.txt",ios::app);
gunsonu<<ctime(&now)<<"Tarihli gelir: "<<toplamgelir<<endl;
gunsonu.close();
cout<<"Bugünkü þimdiye kadar ki toplam gelir:"<<toplamgelir<<endl;
toplamgelir=0;
cout<<"Üst menüye dönmek için enteer tuþuna basýnýz.";
}
//                                          GÜN SONU GÖRME
void Gunsonugorme() {
	string gunsonuoku[100];
	int gsosayac=0;
	ifstream Gunsonuokuma("gunsonu.txt");
	while(!(Gunsonuokuma.eof())) {
		getline(Gunsonuokuma, gunsonuoku[gso]);
		gso++;
	}
		Gunsonuokuma.close();
	for(int gsos=0;gsos<gso;gsos++) {
		if(gsos%2==0)
		cout<<""<<endl;
		cout<<gunsonuoku[gsos]<<" ";
	}
	getch();
}
//                                         SÝPARÝÞ SEÇME
void siparis() {
ifstream hsap("Fiyatlar.txt");
if(!hsap) {
cout<<"Ürünler ve Fiyatlarý bulunamadý!!!!!"<<endl<<" Üst menüye dönmek için enter tuþuna basýnýz"<<endl;
getch();
return;	
}
if(okuma==0) {
while(!(hsap.eof())) {
hsap>>hesapurun[h]>>hesapfiyat[h];
h++;	
}
okuma++;
}
hsap.close();
system("cls");
AnaTema();	
cout<<""<<endl;
cout<<"Sipariþ edilen ürünü seçmek için ürünün kodunu giriniz:"<<endl;
	cout<<"Kodu girin hesaplamak için 0'a basýn"<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
for(t=0;t<h;t++) {
	cout<<hesapurun[t]<<":"<<t+1<<setw(20);
	if(t%3==0)
	cout<<""<<endl;

}
t=0;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
do {
cout<<"Ürün kodunu giriniz: "<<endl;
cin>>kod;
switch(kod){
	case 1:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[0]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 2:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[1]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 3:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[2]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 4:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[3]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 5:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[4]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 6:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[5]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 7:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[6]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 8:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[7]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 9:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[8]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 10:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[9]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 11:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[10]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 12:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];
		carpim[hp]=hesapfiyat[11]*siparisadet[hp];	
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 13:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
	carpim[hp]=hesapfiyat[12]*siparisadet[hp];
	toplam1=toplam1+carpim[hp];
	hp++;
	break;
	case 14:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[13]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 15:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[14]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 16:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[15]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 17:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[16]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 18:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];	
		carpim[hp]=hesapfiyat[17]*siparisadet[hp];
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 19:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];
		carpim[hp]=hesapfiyat[18]*siparisadet[hp];	
		toplam1=toplam1+carpim[hp];
		hp++;
	break;
	case 20:
	cout<<"Ürün adedini giriniz:"<<endl;
	cin>>siparisadet[hp];
	carpim[hp]=hesapfiyat[19]*siparisadet[hp];	
	toplam1=toplam1+carpim[hp];
	hp++;
	break;
}
}
while(0<kod);
cout<<"HESAP:"<<toplam1<<endl;
ofstream geliryaz("gelir.txt",ios::app);
geliryaz<<toplam1<<endl;
geliryaz.close();
cout<<"Üst menüye dönmek için enter tuþuna basýnýz.";
toplam1=0;
getch();
}
//                               AYARLAR
void ayarlar()
{
	char colorcode;
do {

AnaTema();
string MenuItem[5];
MenuItem[0]="Ayar kodunu seçiniz";
MenuItem[1]="1-] Sistem Rengi";
MenuItem[2]="2-] Tüm dosyalarý sýfýrlama";
MenuItem[3]="3-] Yapýmcýlar";
MenuItem[4]="4-] Üst menüye dön";
for (int menu=0;menu<5;menu++)
cout<<MenuItem[menu]<<endl;
cout<<"Yapmak istediðiniz iþlemi seçiniz:";
colorcode=getch();
switch(colorcode)
{
case '1': 
renk();
break;
case '2': 
remove("gelir.txt");
remove("Fiyatlar.txt");
remove("gunsonu.txt");
break;
case '3':
system("cls");
AnaTema();
gotoxy(29,10);
cout<<"YAPIMCILAR";
gotoxy(25,13); 
cout<<"KODLAMACI:FURKAN KOCA";
gotoxy(25,15);
cout<<"TASARIM:FURKAN KOCA";
gotoxy(25,17);
cout<<"TESTER:FURKAN KOCA";
getch();
break;   
}
}
while(colorcode<4);

}




