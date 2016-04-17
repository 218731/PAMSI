#ifndef TAB_ASC_H
#define TAB_ASC_H

#include <cstdlib>
#include "List.h"
#include "tablica.h"

using namespace std;

class Tablica_asc
{
private:
	Tablica buckets;	//przeimplementowac tablice do przetrzymywania objektow typu Tom!
	
public:
	Tom & operator[] (string nazwisko);
};

#endif