#include <iostream>
#include <fstream>
#include "Graf.hh"
#include "Stoper.h"
#include <ctime>

#define ROZMIAR 100

using namespace std;

int main()
{
	srand(time(NULL));
	Graf graf;
	Stoper czasomierz;
	int start, stop;
	double timeBB[ROZMIAR], timeBBEx[ROZMIAR];
	graf.wczytaj_macierz();
	graf.wypisz();
	cout<<endl;
	/*
	cout<<"Start: ";
	cin>>start;
	cout<<"Stop: ";
	cin>>stop;
	*/
	
	for(int i=0; i<5; i++)
	{
		start = rand()%ROZMIAR + 1;
		stop = rand()%ROZMIAR + 1;
		cout<<start<<", "<<stop<<"	";
		czasomierz.start();
		graf.branchAndBound(start, stop);
		czasomierz.stop();
		timeBB[i] = czasomierz.getTime();
		
		czasomierz.start();
		graf.branchAndBoundExtendedList(start, stop);
		czasomierz.stop();
		timeBBEx[i] = czasomierz.getTime();
	}
	cout<<endl<<"Branch & Bound"<<endl;
	for(int i=0; i<5; i++)
		cout<<i+1<<". "<<timeBB[i]<<" sekund"<<endl;
	cout<<"Branch & Bound with extended list"<<endl;
	for(int i=0; i<5; i++)
		cout<<i+1<<". "<<timeBBEx[i]<<" sekund"<<endl;
	//cout<<"Czas znalezienia sciezki wyniosl: "<<czasomierz.getTime()<<" sekund"<<endl<<endl;
	
	
}