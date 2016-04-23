#ifndef DRZEWO_HH
#define DRZEWO_HH
#include "Node.hh"


class Drzewo
{
private:
	Node *korzen;
	int wysokosc;
	
public:
	Drzewo();
	void dodaj(int element);
	void wypisz(Node *wezel);
	void wypisz();
};

#endif