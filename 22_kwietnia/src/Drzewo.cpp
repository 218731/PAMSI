#include "Drzewo.hh"

Drzewo::Drzewo()
{
	wysokosc = 0;	
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
				if(pozycja->lewy != NULL) pozycja = pozycja->lewy;
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
					if(pozycja->prawy != NULL) pozycja = pozycja->prawy;
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

void Drzewo::wypisz(Node *wezel)
{
	if(wezel != NULL)
	{
		wypisz(wezel->lewy);
		std::cout<<wezel->wartosc<<", ";
		wypisz(wezel->prawy);
	}
	else
		std::cout<<wezel->wartosc<<", ";
}

void Drzewo::wypisz()
{
	wypisz(korzen);
}