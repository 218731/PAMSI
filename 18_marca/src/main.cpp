#include "Tablica.hh"
#include "Stoper.hh"
#include <iostream>
#define LICZBA_PROB 1

using namespace std;

int main()
{
	Tablica tablica;
	int zakresy[]={10,100,1000,100000,1000000};
	double czas_sredni;
	Stoper czasomierz;
	
	for(int n=0; n<(int)(sizeof(zakresy)/sizeof(zakresy[0])); n++)
	{
		cout<<"Czas dla zakresu: "<<zakresy[n];
		for (int i=0;i<LICZBA_PROB;i++)
		{
			tablica.reset();															//przygotowanie tablicy do wpisania danych
			czasomierz.start();													  //start pomiaru czasu
			for(int j=0; j<zakresy[n]; j++)	
			{
				tablica.dodajElem(1, 0);	//dodawanie liczby 1 do tablicy; zwiekszanie rozmiaru o 100 elementow
			}
			czasomierz.stop();														//stop pomiaru czasu
			czas_sredni+=czasomierz.getTime();						//zbieranie danych do obliczenia sredniej
		}
		czas_sredni/=LICZBA_PROB;																	//obliczenie sredniego czasu
		cout<<" "<<czas_sredni<<" sekund"<<endl;	//zwrocenie na ekranie zmierzonego czasu w sekundach
		getchar();
	}
}