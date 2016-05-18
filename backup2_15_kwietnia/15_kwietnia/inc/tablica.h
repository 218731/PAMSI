#ifndef TABLICA_H
#define TABLICA_H

#include "Tom.h"

class Tablica
{
	int rozmiar, licznik;
	Tom *tab;
	
	friend class Tablica_asc;
public:
	Tablica();

	~Tablica();

	Tom & operator[](int index)
	{
		return tab[index];
	}
	
	void dodajElem(Tom rekord, int tryb);

	void reset();
	
	int size();
};

#endif