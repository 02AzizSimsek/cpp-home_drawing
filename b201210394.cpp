

                              /****************************************************************************
                              **					SAKARYA ÜNÝVERSÝTESÝ
                              **				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
                              **				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
                              **
                              **				ÖDEV NUMARASI…...: ÖDEV 2;
                              **				ÖÐRENCÝ ADI...............: AZÝZ ÞÝMÞEK
                              **				ÖÐRENCÝ NUMARASI.: B201210394
                              **				DERS GRUBU…………: A GRUBU
                              ****************************************************************************/



#include <iostream>
#include<Windows.h>

using namespace std;

//Komut(console da) satýrýnda istenilen koordinata gitmek için bu fonksiyonu kullanýldý.

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Cati
{
protected:

	int genislik = 0;
	int yukseklik = 0;
	int catininYuksekligi = 0;
	int konumx = 0;
	int konumy = 0;
	int sayi = 0;

public:
	void CatiCizelim()
	{
		//girilen "Cati Yuksekligi" degeri ile hangi ölcüde aþagý inene kadar basmayý yapar
		for (int i = 0; i < catininYuksekligi; i++)
		{
			gotoxy(konumx, konumy + i);

			// "*" larýn öncesindeki boþlugu oluþturmayý saglýyor 
			for (int j = 0; j < catininYuksekligi - i - 1; j++)
			{
				cout << " ";
			}
			
		
			//çatýnýn her katýndaki karakter sayýsýný ayarlýyor  			
			for (int k = 0; k < genislik - 2 * (catininYuksekligi - 1 - i); k++)
			{
				cout << "*";
				
			}
			cout << "\n";
			
		}
		
	}
};

class Kapi :public Cati
{
public:

	void KapiCizelim()
	{
		//Girilen yukseklik deger sonucu kapýnýn yüksekligini  bastýrýr.		
		for (int i = 0; i < yukseklik / 2; i++)
		{
			gotoxy(konumx + genislik / 2, konumy + catininYuksekligi + yukseklik / 2 + i);
			
			//Girilen genislik degeri sonucu kapýnýn geniþlik boyutunu bastýrýr.			
			for (int j = 0; j < genislik / 3; j++)
			{			
				cout << "#"; //(char)sayi;				
			}
		}
	}
};

class Kat : public Kapi
{
public:
	void KatCizelim()
	{
		gotoxy(konumx, konumy + catininYuksekligi);
		
		// KatCizelim() de üst kýsmý yazdýrýyor istenen geniþlikte		
		for (int i = 0; i < genislik; i++)
		{
			cout << (char)219;
		}
		
		// KatCizelim() de sag kýsmý yazdýrýyor istenen yükseklikte		
		for (int i = 0; i < yukseklik; i++)
		{
			gotoxy(konumx + genislik - 1, konumy + i + catininYuksekligi);
		
			cout << (char)219;
			
		}

		// KatCizelim() de alt kýsmý yazdýrýyor istenen geniþlikte
				for (int i = 0; i < genislik; i++)
		{
			gotoxy(konumx + genislik - i - 1, konumy + yukseklik - 1 + catininYuksekligi);
		
			cout << (char)219;
		}
		
		// KatCizelim() de sol kýsmý yazdýrýyor istenen yükseklikte		
		for (int i = 0; i < yukseklik; i++)
		
		{
		
			gotoxy(konumx, konumy + yukseklik - 1 - i + catininYuksekligi);
			
			cout << (char)219;
		}
	}
};


class Ev : public Kat
{
public:
	void EvCizelim()
	{
		cout << "Yuksekiligi Giriniz:"; cin >> yukseklik;//istenilen kat yukseklik degeri

		cout << "Genislik Giriniz:"; cin >> genislik;//istenilen kat geniþligi

		cout << "Cati Yuksekligi:"; cin >> catininYuksekligi;//istenilen çati yüksekligi

		cout << "X degeri :"; cin >> konumx;//konum yatayda 

		cout << "Y degeri:"; cin >>konumy;//konum düþeyde 

		CatiCizelim();

		KatCizelim();

		KapiCizelim();

		gotoxy(konumx, konumy + catininYuksekligi + yukseklik + 1);
		
		cin.get();
	}
};
int main()
{

	Ev ev;
	ev.EvCizelim();

}