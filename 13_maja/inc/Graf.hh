#ifndef GRAF_HH
#define GRAF_HH
#include <fstream>
#include "IGraf.hh"

class Graf : public IGraf
{
private:
	int liczba_wierzcholkow;
	int **sasiedzi;
	int rozmiar;
	
public:
	Graf();
	int dodaj_wierzcholek();
	void dodaj_krawedz(int v1, int v2);
	bool jest_polaczony(int v1, int v2);
	void wypisz();
	void wczytaj_macierz();
	Queue zwrocSasiadow(int v);
	int branchAndBound(int start, int stop);
	int branchAndBoundExtendedList(int start, int stop);
};

#endif