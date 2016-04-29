#include <iostream>
#include <ctime>
#include "Drzewo.hh"
#include "Stoper.hh"

using namespace std;

int main()
{
	int liczba;
	int zakresy[] = {10, 100, 10000, 1000000, 10000000, 1000000000};
	Drzewo drzewo;
	Stoper czasomierz;
	
	for(int j=0; j<(int)(sizeof(zakresy)/sizeof(zakresy[0])); j++)
	{
		cout<<"Wpisanie "<<zakresy[j]<<" liczb zajelo: ";
		czasomierz.start();
		for(int i=0; i<zakresy[j]; i++)
		{
			liczba = rand()%zakresy[j];
			drzewo.dodaj(liczba);
		}
		czasomierz.stop();
		cout<<czasomierz.getTime()<<" sekund"<<endl;
		//cout<<"Twoje drzewo wyglada tak:"<<endl;
		//drzewo.wypisz();
		cout<<endl;
		cout<<"Znalazlem: ";
		czasomierz.start();
		liczba = drzewo.znajdz(liczba);
		czasomierz.stop();
		cout<<liczba<<". Zajelo to "<<czasomierz.getTime()<<" sekund"<<endl<<endl;
		drzewo.reset();
	}
}