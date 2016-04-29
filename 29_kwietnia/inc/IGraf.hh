#ifndef IGRAF_HH
#define IGRAF_HH

class IGraf
{
	virtual void dodaj_wierzcholek(int v) = 0;
	virtual void dodaj_krawedz(int v1, int v2) = 0;
	virtual void zwroc_sasiadow(int v) = 0;
	virtual void jest_polaczony(int v1, int v2) = 0;
};

#endif