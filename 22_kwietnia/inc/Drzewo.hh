#ifndef DRZEWO_HH
#define DRZEWO_HH
#include "Node.hh"


class Drzewo
{
private:
	Node *korzen;
	Node wartownik;
	int wysokosc;
	
public:
	Drzewo();
	void dodaj(int element);
	void wypisz(Node *wezel);
	void wypisz();
	int znajdz(int szukana);
	void reset();
	void reset(Node *wezel);
};

#endif