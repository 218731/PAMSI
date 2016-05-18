#include "tab_asc.h"

Tom & Tablica_asc::operator[] (std::string nazwisko)
{
	int i=0;
	while(i<buckets.size())
	{
		if(buckets.tab[i].litera == nazwisko[0])
		{
			return buckets.tab[i];
		}
		i++;
	}
	throw "Brak tomu dla takiego nazwiska ---> dodaj je do ksiazki";
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
	if((i>=buckets.size()) || (znalazlem == 1)) stop = 1;
	while(stop == 0)
	{
		if(buckets.tab[i].litera == nazwisko[0])
		{
			znalazlem = 1;
			temp_Tom = &buckets.tab[i];
		}
		i++;
		if((i>=buckets.size()) || (znalazlem == 1)) stop = 1;
	}
	
	
	if(znalazlem == 0)
	{
		temp_Tom = new Tom;
		temp_Tom->litera = nazwisko[0];
		buckets.dodajElem(*temp_Tom, 1);
		cout<<buckets.size()<<endl;
		i++;
	}
	
	buckets.tab[i-1].elementy.add(numer, nazwisko, temp_Tom->elementy.size()+1);
}

void Tablica_asc::wypisz()
{
	for(int i=0; i<buckets.size(); i++)
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
	for(int i=0; i<buckets.size(); i++)
	{
		if(buckets.tab[i].litera == nazwisko[0])
		{
			znalazlem = 1;
			temp_Tom = &buckets.tab[i];
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


