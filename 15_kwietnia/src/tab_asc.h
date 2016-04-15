#include <cstdlib>
#include <string.h>
#include "List.h"
#include "tablica.h"

using namespace std;

class Tom
{
	char litera;
	List elementy;		//przeimplementowac liste do przetrzymywania objektow 'int numer' i 'string nazwisko'!
};

class Tablica_asc
{
private:
	Tablica buckets;	//przeimplementowac tablice do przetrzymywania objektow typu Tom!
	
	int & operator[] (string nazwisko);
};

int & operator[] (string nazwisko)
{
	for(int i=0; i<buckets.rozmiar(); i++)
	{
		if(bucket.tab[i].litera == nazwisko[0])
		{
			return i;
		}
	}
	Tom temp_Tom;
	temp_Tom.litera = nazwisko[0];
	buckets.dodajElem(temp_Tom);
}