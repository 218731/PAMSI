#ifndef GRAF_HH
#define GRAF_HH
#include "IGraf.hh"

class Graf : public IGraf
{
	int liczba_wierzcholkow;
	int *sasiedzi;
	int rozmiar;
	
public:
	Graf();
};

Graf::Graf()
{
	liczba_wierzcholkow = 0;
	rozmiar = 10;
	sasiedzi = new int [rozmiar][rozmiar];
}

void Graf::dodaj_wierzcholek()
{
	int wierzcholki, krawedzie;
	cout<<"Podaj liczbe wierzcholkow do dodania: ";
	cin>>wierzcholki;
	do
	{
		cout<<"Podaj liczbe krawedzi: ";
		cin>>krawedzie;
	}while(krawedzie >= wierzcholki-1);
	
	if(liczba_wierzcholkow + wierzcholki) > rozmiar)
		//powieksz macierz sasiedztwa
		
	for(int i=0; i<krawedzie; i++)
	{
		//wczytanie krawedzi
		//dodanie rekordu do macierzy
	}
}

#endif