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
	fstream plik;
	
  plik.open( "nazwiska.txt", std::ios::in | std::ios::out );
	
	for(int j=0; j<(int)(sizeof(zakresy)/sizeof(zakresy[0])); j++)
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
		cout<<czasomierz.getTime()<<" sekund. Dzieki, dzieki, siema!"<<endl;
		getchar();
		ksiazka.reset();
		
	}
	
	/*
	czasomierz.start();
	cout<<ksiazka.szukaj("partyka22")<<endl;
	czasomierz.stop();
	cout<<czasomierz.getTime()<<" sekund"<<endl;

*/
}