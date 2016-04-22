#include "tab_hash.h"

using namespace std;

Tablica_hash::Tablica_hash()
{
	rozmiar=2;
	licznik=0;
	buckets = new Tom[rozmiar];
}

Tablica_hash::~Tablica_hash()
{
	delete[] buckets;
	buckets = NULL;
}

void Tablica_hash::dodajElem(Tom rekord, int tryb)
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


void Tablica_hash::reset()
{
	delete[] buckets;
	rozmiar=2;
	licznik=0;
	buckets = new Tom[rozmiar];
}

int Tablica_hash::size()
{
	return licznik;
}

Tom & Tablica_hash::operator[](std::string nazwisko)
//Tom & Tablica_hash::zwroc(std::string nazwisko)
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