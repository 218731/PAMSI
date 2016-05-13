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
	Queue zwroc_sasiadow_BFS(int v);
	Stack zwroc_sasiadow_DFS(int v);
	bool jest_polaczony(int v1, int v2);
	void przeszukaj_wszerz(int v);
	void przeszukaj_wglab(int v);
	void wypisz();
	void wczytaj_macierz();
};

#endif