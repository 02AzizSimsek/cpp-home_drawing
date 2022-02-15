

                              /****************************************************************************
                              **					SAKARYA �N�VERS�TES�
                              **				    B�LG�SAYAR M�HEND�SL��� B�L�M�
                              **				          PROGRAMLAMAYA G�R��� DERS�
                              **
                              **				�DEV NUMARASI�...: �DEV 2;
                              **				��RENC� ADI...............: AZ�Z ��M�EK
                              **				��RENC� NUMARASI.: B201210394
                              **				DERS GRUBU����: A GRUBU
                              ****************************************************************************/



#include <iostream>
#include<Windows.h>

using namespace std;

//Komut(console da) sat�r�nda istenilen koordinata gitmek i�in bu fonksiyonu kullan�ld�.

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
		//girilen "Cati Yuksekligi" degeri ile hangi �lc�de a�ag� inene kadar basmay� yapar
		for (int i = 0; i < catininYuksekligi; i++)
		{
			gotoxy(konumx, konumy + i);

			// "*" lar�n �ncesindeki bo�lugu olu�turmay� sagl�yor 
			for (int j = 0; j < catininYuksekligi - i - 1; j++)
			{
				cout << " ";
			}
			
		
			//�at�n�n her kat�ndaki karakter say�s�n� ayarl�yor  			
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
		//Girilen yukseklik deger sonucu kap�n�n y�ksekligini  bast�r�r.		
		for (int i = 0; i < yukseklik / 2; i++)
		{
			gotoxy(konumx + genislik / 2, konumy + catininYuksekligi + yukseklik / 2 + i);
			
			//Girilen genislik degeri sonucu kap�n�n geni�lik boyutunu bast�r�r.			
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
		
		// KatCizelim() de �st k�sm� yazd�r�yor istenen geni�likte		
		for (int i = 0; i < genislik; i++)
		{
			cout << (char)219;
		}
		
		// KatCizelim() de sag k�sm� yazd�r�yor istenen y�kseklikte		
		for (int i = 0; i < yukseklik; i++)
		{
			gotoxy(konumx + genislik - 1, konumy + i + catininYuksekligi);
		
			cout << (char)219;
			
		}

		// KatCizelim() de alt k�sm� yazd�r�yor istenen geni�likte
				for (int i = 0; i < genislik; i++)
		{
			gotoxy(konumx + genislik - i - 1, konumy + yukseklik - 1 + catininYuksekligi);
		
			cout << (char)219;
		}
		
		// KatCizelim() de sol k�sm� yazd�r�yor istenen y�kseklikte		
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

		cout << "Genislik Giriniz:"; cin >> genislik;//istenilen kat geni�ligi

		cout << "Cati Yuksekligi:"; cin >> catininYuksekligi;//istenilen �ati y�ksekligi

		cout << "X degeri :"; cin >> konumx;//konum yatayda 

		cout << "Y degeri:"; cin >>konumy;//konum d��eyde 

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