#ifndef IGRAF_HH
#define IGRAF_HH
#include "Queue.h"
#include "Stack.h"

class IGraf
{
public:
	virtual int dodaj_wierzcholek() = 0;
	virtual void dodaj_krawedz(int v1, int v2) = 0;
	virtual bool jest_polaczony(int v1, int v2) = 0;
	virtual void wypisz() = 0;
	virtual Queue zwrocSasiadow(int v) = 0;
	virtual int branchAndBound(int start, int stop) = 0;
	virtual int branchAndBoundExtendedList(int start, int stop) = 0;
};

#endif