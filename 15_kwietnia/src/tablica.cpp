#include "tablica.h"
#include <cstdio>


Tablica::Tablica()
	{
		rozmiar=2;
		licznik=0;
		tab = new Tom[rozmiar];
	}

Tablica::~Tablica()
	{
		delete[] tab;
		tab = NULL;
	}

void Tablica::dodajElem(int liczba, int tryb)
	{
		if(licznik>=rozmiar)
			{ 
				rozmiar=rozmiar+tryb;
				int *temp_tablica = new int[rozmiar];
				for(int i=0;i<licznik;i++)
				temp_tablica[i]=tab[i];
				delete[] tab;
				tab = temp_tablica;
				temp_tablica=NULL;
			}
		tab[licznik]=liczba;
		licznik++;		
	}


void Tablica::reset()
	{
		delete[] tab;
		rozmiar=2;
		licznik=0;
		tab = new int[rozmiar];
	}

int rozmiar()
{
	return rozmiar;
}