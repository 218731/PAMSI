#ifndef TAB_HASH_H
#define TAB_HASH_H

#include "Tom.h"
#include <string>

class Tablica_hash
{
private:
	int rozmiar, licznik;
	Tom *buckets;

	friend class Tablica_asc;
public:
	Tablica_hash();
	~Tablica_hash();
	Tom & operator[] (std::string nazwisko);
	Tom & zwroc(std::string nazwisko);
	void dodajElem(Tom rekord, int tryb);
	void reset();
	int size();
};

#endif