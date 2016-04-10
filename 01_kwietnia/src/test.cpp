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
	cout<<"Podaj ilosc liczb do wpisania: ";
	cin>>zakres;
	for(double i=0; i<zakres; i++)						//uzupelnianie listy liczbami w ilosci podanej w zmiennej zakres
	{
		//liczba = i;
		cin >> liczba;
		lista.add(liczba,i+1);
	}
	cout<<"To jest ostatnia wpisana liczba: "<<lista.get(zakres).element<<endl;
	lista.wypisz();
	cout<<endl;
	
	cin>>liczba;
	lista.add(liczba, 2);
	cout<<endl;
	lista.wypisz();
	/*cout<<"Jakiej liczby szukac? :";
	cin>>liczba;
	czasomierz.start();
	lista.wyszukaj(liczba);
	czasomierz.stop();
	cout<<"Czas wyszukania to "<<czasomierz.getTime()<<" sekund"<<endl;
*/
}
