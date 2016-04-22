#include <iostream>
#include <fstream>
#include "tab_asc.h"
#include "Stoper.h"
#include "Queue.h"

using namespace std;

int main()
{
	string test;
	Stoper czasomierz;
	int zakresy[] = {10, 100, 10000, 1000000, 1000000000};
	string nazwiska[] = {"Klocek", "Dorosz", "Leszko", "sabg"};
	fstream plik;
	
  plik.open( "nazwiska.txt", std::ios::in | std::ios::out );
	
	cout<<"Czasy wpisywania:"<<endl;
	for(int j=0; j<(int)(sizeof(zakresy)/sizeof(zakresy[0]))-1; j++)
	{
		Tablica_asc ksiazka;
		czasomierz.start();
		for(int i=0; i<zakresy[j]; i++)
		{
			getline(plik, test);
			ksiazka.dodaj(123456, test);
		}
		czasomierz.stop();
		//ksiazka.wypisz();
		cout<<"Zapis "<<zakresy[j]<<" elementow: "<<czasomierz.getTime()<<" sekund. Dzieki, dzieki, siema!"<<endl;
		getchar();
		czasomierz.start();
		cout<<"Numer do '"<<nazwiska[j]<<"': "<<ksiazka.szukaj(nazwiska[j])<<endl;
		czasomierz.stop();
		cout<<"Czas szukania w "<<zakresy[j]<<" elementach: "<<czasomierz.getTime()<<" sekund"<<endl;
		getchar();
		ksiazka.reset();
		
	}
}