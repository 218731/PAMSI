#include <iostream>
#include "Drzewo.hh"

using namespace std;

int main()
{
	int liczba;
	Drzewo drzewo;
	for(int i=0; i<10; i++)
	{
		cin>>liczba;
		drzewo.dodaj(liczba);
	}
	drzewo.wypisz();
}