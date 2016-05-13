#ifndef IGRAF_HH
#define IGRAF_HH
#include "Queue.h"
#include "Stack.h"

class IGraf
{
public:
	virtual int dodaj_wierzcholek() = 0;
	virtual void dodaj_krawedz(int v1, int v2) = 0;
	virtual Queue zwroc_sasiadow_BFS(int v) = 0;
	virtual Stack zwroc_sasiadow_DFS(int v) = 0;
	virtual bool jest_polaczony(int v1, int v2) = 0;
	virtual void wypisz() = 0;
	virtual void przeszukaj_wszerz(int v) = 0;
	virtual void przeszukaj_wglab(int v) = 0;
};

#endif