#ifndef TAB_ASC_H
#define TAB_ASC_H

#include <cstdlib>
#include <iostream>
#include "List.h"
#include "Tom.h"

using namespace std;

class Tablica_asc
{
private:
	int rozmiar, licznik;
	Tom *buckets;
	
public:
	Tom & operator[] (string nazwisko);
	void wypisz();
	void dodaj(int numer, std::string nazwisko);
	int szukaj(std::string nazwisko);
	Tablica_asc();

	~Tablica_asc();

	Tom & operator[](int index)
	{
		return buckets[index];
	}
	
	void dodajElem(Tom rekord, int tryb);

	void reset();
	
	int size();
};

#endif