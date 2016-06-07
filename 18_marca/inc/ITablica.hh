#ifndef ITABLICA_HH
#define ITABLICA_HH

class ITablica
{
	virtual void dodajElem(int liczba, int tryb) = 0;
	virtual void reset() = 0;
	virtual int jaki_rozmiar() = 0;
};

#endif