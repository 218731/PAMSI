#ifndef TAB_ASC_H
#define TAB_ASC_H

#include <cstdlib>
#include <iostream>
#include "List.h"
#include "tab_hash.h"

using namespace std;

class Tablica_asc : public Tablica_hash
{
public:
	void wypisz();
	void dodaj(int numer, std::string nazwisko);
	int szukaj(std::string nazwisko);
};

#endif