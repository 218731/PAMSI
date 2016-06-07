#include <iostream>
#include "PQueue.h"

using namespace std;

int main()
{
	int liczba, prio, rozmiar;
	PQueue kolejka;
	for(int i=1; i<=5; i++)
	{
		cout<<"Liczba: ";
		cin>>liczba;
		cout<<"Prio: ";
		cin>>prio;
		kolejka.push(liczba, prio);
	}
	rozmiar = kolejka.size();
	for(int i=1; i<=rozmiar-3; i++)
		cout<<i<<". "<<kolejka.pop().element<<endl;
	kolejka.wypisz();
	for(int i=1; i<=2; i++)
	{
		cout<<"Liczba: ";
		cin>>liczba;
		cout<<"Prio: ";
		cin>>prio;
		kolejka.push(liczba, prio);
	}
	kolejka.wypisz();
	cout<<kolejka.size()<<endl;
}