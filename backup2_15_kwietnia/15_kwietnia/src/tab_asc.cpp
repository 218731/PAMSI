#include "tab_asc.h"

Tablica_asc::Tablica_asc()
{
	rozmiar=2;
	licznik=0;
	buckets = new Tom[rozmiar];
}

Tablica_asc::~Tablica_asc()
{
	delete[] buckets;
	buckets = NULL;
}

void Tablica_asc::dodajElem(Tom rekord, int tryb)
{
	if(licznik>=rozmiar)
		{ 
			rozmiar=rozmiar+tryb;
			Tom *temp_tablica = new Tom[rozmiar];
			for(int i=0; i<licznik; i++)
				temp_tablica[i]=buckets[i];
			delete[] buckets;
			buckets = temp_tablica;
			temp_tablica=NULL;
		}
	buckets[licznik]=rekord;
	licznik++;		
}


void Tablica_asc::reset()
{
	delete[] buckets;
	rozmiar=2;
	licznik=0;
	buckets = new Tom[rozmiar];
}

int Tablica_asc::size()
{
	return licznik;
}

Tom & Tablica_asc::operator[] (std::string nazwisko)
{
	int i=0;
	while(i<licznik)
	{
		if(buckets[i].litera == nazwisko[0])
		{
			return buckets[i];
		}
		i++;
	}
	throw -1;
	/*
	cout<<"Podaj numer telefonu: ";	
	cin>>temp_numer;
	temp_Tom.litera = nazwisko[0];
	buckets.dodajElem(temp_Tom, 1);
	buckets[i].elementy.add(temp_numer, nazwisko, 1);
	return buckets[i];
	*/
}

void Tablica_asc::dodaj(int numer, std::string nazwisko)
{
	Tom *temp_Tom;
	bool znalazlem = 0, stop = 0;
	int i = 0;
	if((i>=licznik) || (znalazlem == 1)) stop = 1;
	
	while(stop == 0)
	{
		if(buckets[i].litera == nazwisko[0])
		{
			znalazlem = 1;
			temp_Tom = &buckets[i];
		}
		i++;
		if((i>=licznik) || (znalazlem == 1)) stop = 1;
	}
	
	if(znalazlem == 0)
	{
		temp_Tom = new Tom;
		temp_Tom->litera = nazwisko[0];
		dodajElem(*temp_Tom, 1);
		//cout<<licznik<<endl;
		i++;
	}
	
	/*
	try
	{
		temp_Tom = buckets[nazwisko];
	}
	catch (int wyjatek)
	{
		if(wyjatek == -1)
		{
			temp_Tom = new Tom;
			temp_Tom->litera = nazwisko[0];
			dodajElem(*temp_Tom, 1);
		}
	}
	
	*/
	temp_Tom->elementy.add(numer, nazwisko, temp_Tom->elementy.size()+1);
}

void Tablica_asc::wypisz()
{
	for(int i=0; i<licznik; i++)
	{
		cout<<buckets[i].litera<<":"<<endl;
		buckets[i].elementy.wypisz();
		cout<<endl;
	}
}

int Tablica_asc::szukaj(std::string nazwisko)
{
	Tom *temp_Tom;
	bool znalazlem = 0;
	for(int i=0; i<licznik; i++)
	{
		if(buckets[i].litera == nazwisko[0])
		{
			znalazlem = 1;
			temp_Tom = &buckets[i];
		}
	}
	
	if(znalazlem == 0) throw "Nie da rady";
	else
	{
		for(int i=1; i<=temp_Tom->elementy.size(); i++)
		{
			std::string testowe_nazwisko = temp_Tom->elementy.get(i).nazwisko;
			if(testowe_nazwisko.compare(nazwisko) == 0)
			{
				return temp_Tom->elementy.get(i).numer;
			}
		}
		cout<<"Mietek, sorry, nie ma tego"<<endl;
		throw "Nope";
	}
}


