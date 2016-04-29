#include "Drzewo.hh"

using namespace std;

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
		nowy->ojciec = NULL;
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
				if(pozycja->prawy != NULL) pozycja = pozycja->prawy;
				else
				{
					pozycja->prawy = nowy;
					if(i>=wysokosc) wysokosc++;
					nowy->ojciec = pozycja;
				}
			}
			else
			{
				if(element < (pozycja->wartosc))
				{
					if(pozycja->lewy != NULL) pozycja = pozycja->lewy;
					else
					{
						pozycja->lewy = nowy;
						if(i>=wysokosc) wysokosc++;
						nowy->ojciec = pozycja;
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
		if(wezel->lewy != NULL) wypisz(wezel->lewy);
		std::cout<<wezel->wartosc<<endl;
		if(wezel->prawy != NULL) wypisz(wezel->prawy);
	}
}

void Drzewo::wypisz()
{
	wypisz(korzen);
}

int Drzewo::znajdz(int szukana)
{
	Node *wezel = korzen;
	do
	{
		if(szukana > wezel->wartosc) wezel = wezel->prawy;
		if(szukana < wezel->wartosc) wezel = wezel->lewy;
	}while(wezel->wartosc != szukana);
	return wezel->wartosc;
}

void Drzewo::reset()
{
	reset(korzen);
}

void Drzewo::reset(Node *wezel)
{
	if(wezel != NULL)
	{
		if(wezel->lewy != NULL) reset(wezel->lewy);
		if(wezel->prawy != NULL) reset(wezel->prawy);
		delete wezel;
	}
	korzen = NULL;
	wysokosc = 0;
}