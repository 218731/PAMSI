#include <iostream>
#include <cstdlib>
#include <ctime>
#include "List.h"
#include "Stoper.h"

using namespace std;

int main()
{
  srand(time(NULL));
	Stoper czasomierz;
	List lista;
	double zakres;
	double liczba;
	cin>>zakres;
	for(double i=0; i<zakres; i++)
	{
		//liczba = i;
		liczba = (rand()%10000000)+0;
		lista.add(liczba,i+1);
	}
	cout<<lista.get(zakres).element<<endl;
	cin>>liczba;
	czasomierz.start();
	lista.wyszukaj(liczba);
	czasomierz.stop();
	cout<<czasomierz.getTime()<<" sekund"<<endl;

}
