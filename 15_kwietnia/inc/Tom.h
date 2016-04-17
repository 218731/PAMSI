#ifndef TOM_H
#define TOM_H

#include "List.h"

struct Tom
{
	char litera;
	List elementy;		//przeimplementowac liste do przetrzymywania objektow 'int numer' i 'string nazwisko'!
	
public:
	char nazwa_tomu()
	{
		return litera;
	}
};

#endif