#ifndef ILIST_H
#define ILIST_H

#include "Node.h"

class IList
{
public:
	virtual int add(int numer, std::string nazwisko, int position) = 0;
	virtual Node remove(int position) = 0;
	virtual Node get(int position) = 0;
	virtual void wypisz() = 0;
	virtual int size() = 0;
	virtual void wyczysc() = 0;
};

#endif