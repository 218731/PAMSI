#ifndef LIST_H
#define LIST_H
#include "IList.h"

class List : public IList
{
private:
	int rozmiar;
	Node *poczatek, *koniec;				//wskazniki na poczatkowy i ostatni element listy
public:

	List();
	int add(int numer, std::string nazwisko, int position);
	Node remove(int position);
	Node get(int position);
	void wypisz();
	int size();
	int wyszukaj(int szukana);
	void wyczysc();
};

#endif