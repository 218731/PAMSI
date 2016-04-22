#ifndef DRZEWO_HH
#define DRZEWO_HH
#include "Node.hh"
#include <iostream>


class Drzewo
{
private:
	Node *korzen;
	int ilosc_wezlow;
	
public:
	Drzewo();
	void dodaj(int element);
	void wypisz();
};

Drzewo::Drzewo()
{
	wysokosc == 0;	
}

void Drzewo::dodaj(int element)
{
	Node *nowy = new Node;
	nowy->wartosc = element;
	Node *pozycja;
	if(wysokosc == 0)
	{
		korzen = nowy;
		wysokosc++;
	}
	else
	{
		pozycja = korzen;
		for(int i=1; i<=wysokosc; i++)
		{
			if(element > (pozycja->wartosc))
			{
				if(pozycja->lewy != NULL) pozycja = lewy;
				else
				{
					pozycja->lewy = nowy;
					if(i>=wysokosc) wysokosc++;
				}
			}
			else
			{
				if(element < (pozycja->wartosc))
				{
					if(pozycja->prawy != NULL) pozycja = prawy;
					else
					{
						pozycja->prawy = nowy;
						if(i>=wysokosc) wysokosc++;
					}
				}
			}
		}
	}
}

void Drzewo::wypisz()
{
	Node *poprzedni = NULL, *nastepny = korzen;
	for(int i=1; i<=wysokosc; i++)
	{
		cout<<
	}
}

#endif