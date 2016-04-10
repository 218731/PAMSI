#include <iostream>
#include <cstdlib>
#include <ctime>
#include "List.h"
#include "Queue.h"
#include "Stoper.h"

using namespace std;

int main()
{
	srand(time(NULL));
	List lista;
	Queue zakresy;
	Stoper czasomierz;
	int aktualny_zakres, ilosc_elementow;
	
	zakresy.push(10);
	zakresy.push(100);
	zakresy.push(1000);
	zakresy.push(1000000);
	zakresy.push(1000000000);
	
	
	ilosc_elementow = zakresy.size();
	for (int i=0; i<ilosc_elementow; i++)
	{
		aktualny_zakres = zakresy.pop().element;
		cout<<"aktualny zakres: "<<aktualny_zakres<<endl;
		for (int j=0; j<aktualny_zakres; j++)
		{
			lista.add(j, j+1);
		}
		czasomierz.start();
		lista.wyszukaj(rand()%aktualny_zakres);
		czasomierz.stop();
		cout<<"Wyszukanie losowego elementu zajelo: "<<czasomierz.getTime()<<" sekund"<<endl;
		lista.wyczysc();
	}
}