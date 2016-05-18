#include <iostream>
#include "Drzewo.hh"

using namespace std;

int main()
{
	int liczba;
	Drzewo drzewo;
	for(int i=0; i<5; i++)
	{
		cin>>liczba;
		drzewo.dodaj(liczba);
	}
	cout<<"Twoje drzewo wyglada tak:"<<endl;
	drzewo.wypisz();
	cout<<endl;
	//cout<<"Znalazlem: "<<drzewo.znajdz(liczba)<<endl;
}