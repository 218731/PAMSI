#include "tab_asc.h"

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
		//temp_Tom = &zwroc(nazwisko);
		temp_Tom = &buckets[nazwisko];
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


