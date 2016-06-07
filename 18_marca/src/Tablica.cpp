#include <iostream>
#include "Tablica.hh"
#include <iostream>


Tablica::Tablica() //konstruktor ustawiajajacy poczatkowy rozmiar tablicy na 2 elementy i alokujacy pamiec
{
	rozmiar=2;
	licznik=0;
	tab = new int[rozmiar];
}

Tablica::~Tablica() //destruktor dealokujacy pamiec po tablicy
{
	delete[] tab;
	tab = NULL;
}

void Tablica::dodajElem(int liczba, int tryb)
{
	if(licznik>=rozmiar)
	{
		if(tryb != 0) rozmiar=rozmiar+tryb;
		else rozmiar=2*rozmiar;														 //podwojenie rozmiaru tablicy w razie braku miejsca
		int *temp_tablica = new int[rozmiar];

		for(int i=0;i<licznik;i++)
			temp_tablica[i]=tab[i];
		delete[] tab;
		tab = temp_tablica;
		temp_tablica = NULL;
	}
	
	tab[licznik]=liczba;			//dodanie elementu
	licznik++;
	if(licznik%1000==0) std::cout<<licznik<<std::endl;
}

void Tablica::reset()	//metoda do dealokacji pamieci po tablicy i alokacja nowej z domyslnym rozmiarem tablicy 2 elementow
{
	delete[] tab;
	rozmiar=2;
	licznik=0;
	tab = new int[rozmiar];
}

int Tablica::jaki_rozmiar()	//funkcja testowa do podania ilosci elementow w tablicy po zakonczeniu jej wypelniania
{
	return rozmiar;
}