#ifndef TAB_ASC_H
#define TAB_ASC_H

#include <cstdlib>
#include <iostream>
#include "List.h"
#include "tablica.h"

using namespace std;

class Tablica_asc
{
private:
	Tablica buckets;	//przeimplementowac tablice do przetrzymywania objektow typu Tom!
	
public:
	Tom & operator[] (string nazwisko);
	void wypisz();
	void dodaj(int numer, std::string nazwisko);
	int szukaj(std::string nazwisko);
};

#endif