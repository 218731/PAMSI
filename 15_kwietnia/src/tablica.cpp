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

void Tablica::dodajElem(Tom rekord, int tryb)
	{
		if(licznik>=rozmiar)
			{ 
				rozmiar=rozmiar+tryb;
				Tom *temp_tablica = new Tom[rozmiar];
				for(int i=0; i<licznik; i++)
					temp_tablica[i]=tab[i];
				delete[] tab;
				tab = temp_tablica;
				temp_tablica=NULL;
			}
		tab[licznik]=rekord;
		licznik++;		
	}


void Tablica::reset()
	{
		delete[] tab;
		rozmiar=2;
		licznik=0;
		tab = new Tom[rozmiar];
	}

int Tablica::size()
{
	return rozmiar;
}