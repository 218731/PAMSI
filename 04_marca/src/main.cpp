#include <iostream>
#include <ctime>

#include "tablica.h"

using namespace std;


int main()
{
	time_t start, stop;
	//srand(time(NULL));
	//int liczba;
	Tablica dyn;
	int zakresy[]={10,100,1000,1000000,1000000000};
	for(int j=0;j<(int)(sizeof(zakresy)/sizeof(zakresy[0]));j++)
		{
			cout<<"Wpisywanie "<<zakresy[j]<<" liczb, krok: 1 "<<endl;
			start=clock();		
			for(int i=0; i<zakresy[j]; i++)
	{
		//liczba=rand();
		dyn.dodajElem(1, 1);
	}
			stop=clock();
			cout<<"Wpisanie zajęło: "<<(stop-start)/(double)CLOCKS_PER_SEC<<" sek"<<endl<<endl;
			dyn.reset();
		}
}
