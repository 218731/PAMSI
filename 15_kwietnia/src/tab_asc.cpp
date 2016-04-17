#include "tab_asc.h"

Tom & Tablica_asc::operator[] (std::string nazwisko)
{
	int i=0;
	while(i<buckets.size())
	{
		if(buckets.tab[i].litera == nazwisko[0])
		{
			return buckets[i];
		}
		i++;
	}
	Tom temp_Tom;
	temp_Tom.litera = nazwisko[0];
	buckets.dodajElem(temp_Tom, 1);
	return buckets[i+1];
}
