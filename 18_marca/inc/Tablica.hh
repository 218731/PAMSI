#ifndef TABLICA_HH
#define TABLICA_HH
#include "ITablica.hh"

class Tablica:public ITablica
{
private:
	int rozmiar, licznik;
	int *tab;

public:
	Tablica(); //konstruktor ustawiajajacy poczatkowy rozmiar tablicy na 2 elementy i alokujacy pamiec
	~Tablica(); //destruktor dealokujacy pamiec po tablicy
	
	/*metoda dodajaca element do tablicy i w razie braku miejsca zwiekszajaca jej rozmiar
		int liczba - zmienna do dodania do tablicy
		int tryb - liczba elementow o jaka ma sie zwiekszyc rozmiar tablicy
	*/
	void dodajElem(int liczba, int tryb);
	void reset();	//metoda do dealokacji pamieci po tablicy i alokacja nowej z domyslnym rozmiarem tablicy 2 elementow
	int jaki_rozmiar();	//funkcja testowa do podania ilosci elementow w tablicy po zakonczeniu jeje wypelniania
};

#endif