#include "Drzewo.hh"

using namespace std;

Drzewo::Drzewo()
{
	wysokosc = 0;
	wartownik.kolor = 0;
}

void Drzewo::dodaj(int element)
{
	Node *nowy = new Node;
	nowy->wartosc = element;
	Node *pozycja;
	
	if(wysokosc == 0)
	{
		nowy->kolor = 0;
		nowy->ojciec = &wartownik;
		korzen = nowy;
		wysokosc++;
	}
	else
	{
		pozycja = korzen;
		nowy->kolor = 1;
		for(int i=1; i<=wysokosc; i++)
		{
			if(element > (pozycja->wartosc))
			{
				if(pozycja->prawy != &wartownik) pozycja = pozycja->prawy;
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
					if(pozycja->lewy != &wartownik) pozycja = pozycja->lewy;
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
	nowy->prawy = nowy->lewy = &wartownik;
	porzadkuj(nowy);
}

void Drzewo::obrotP(Node *wezel)	
{
	Node *temp = wezel->lewy;
	wezel->lewy = temp->prawy;
	temp->prawy = wezel;
	wezel = temp;	
}

void Drzewo::obrotL(Node *wezel)
{
	Node *temp = wezel->prawy;
	wezel->prawy = temp->lewy;
	temp->lewy = wezel;
	wezel = temp;		
}

void Drzewo::porzadkuj(Node *wezel)
{
	while(wezel->ojciec->kolor == 1)
	{
		if(wezel->ojciec == wezel->ojciec->ojciec->prawy)
		{
			Node *stryj = wezel->ojciec->ojciec->lewy;
			if((stryj != &wartownik) && (stryj->kolor == 1))	//1a
			{
				wezel->ojciec->kolor = 0;
				stryj->kolor = 0;
				wezel->ojciec->ojciec->kolor = 1;
				wezel = wezel->ojciec->ojciec;
			}
			else if(((stryj == &wartownik) || (stryj->kolor == 0)) && (wezel == wezel->ojciec->lewy))	//1b
			{
				wezel = wezel->ojciec;
				obrotP(wezel);

				wezel->kolor = 0;
				wezel->ojciec->kolor = 1;
				wezel = wezel->ojciec;
				obrotL(wezel);
			}
			else if(((stryj == &wartownik) || (stryj->kolor == 0)) && (wezel == wezel->ojciec->prawy))		//1c
			{
				wezel->ojciec->kolor = 0;
				wezel->ojciec->ojciec->kolor = 1;
				obrotL(wezel->ojciec->ojciec);
			}
		}
		if(wezel->ojciec == wezel->ojciec->ojciec->lewy)	//2
		{
			Node *stryj = wezel->ojciec->ojciec->prawy;
			if((stryj != &wartownik) && (stryj->kolor == 1))	//2a
			{
				wezel->ojciec->kolor = 0;
				stryj->kolor = 0;
				wezel->ojciec->ojciec->kolor = 1;
				wezel = wezel->ojciec->ojciec;
			}
			else if((stryj == &wartownik) || (stryj->kolor == 0))	
			{
				if(wezel == wezel->ojciec->prawy)		//2b
				{
					wezel = wezel->ojciec;
					obrotL(wezel);

					wezel->kolor = 0;
					wezel->ojciec->kolor = 1;
					obrotP(wezel->ojciec);
				}
				else if(wezel == wezel->ojciec->lewy)		//2c
				{
					wezel->ojciec->kolor = 0;
					wezel->ojciec->ojciec->kolor = 1;
					obrotP(wezel->ojciec->ojciec);
				}	
			}
		}
		if(wezel->ojciec->kolor == 1)
		{
			cout<<"Wezel:"<<endl;
			cout<<"Wartosc: "<<wezel->wartosc<<", kolor: "<<wezel->kolor<<endl;
			cout<<"Ojciec:"<<endl;
			cout<<"Wartosc: "<<wezel->ojciec->wartosc<<", kolor: "<<wezel->ojciec->kolor<<endl;
		}
		cout<<"Jestem w petli"<<endl;
		//getchar();
		korzen->kolor = 0;
	}
}

void Drzewo::wypisz(Node *wezel)
{
	if(wezel != &wartownik)
	{
		if(wezel->lewy != &wartownik) wypisz(wezel->lewy);
		std::cout<<wezel->wartosc<<", "<<wezel->kolor<<endl;
		if(wezel->prawy != &wartownik) wypisz(wezel->prawy);
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