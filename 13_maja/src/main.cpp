#include <iostream>
#include <fstream>
#include "Graf.hh"
#include "Stoper.h"

using namespace std;

int main()
{
	Graf graf;
	Stoper czasomierz;
	double czas = 0;
	int v1;
	graf.wczytaj_macierz();
	cout<<endl;
	cout<<"Od ktorego zaczac przeszukanie?: ";
	cin>>v1;

	
	cout<<"**************************BFS**************************"<<endl;
	for(int i=0; i<10; i++)
	{
		czasomierz.start();
		graf.przeszukaj_wszerz(v1);
		czasomierz.stop();
		czas += czasomierz.getTime();
	}
	czas = czas/10.0;
	cout<<"Czas przeszukania BFS: "<<czas<<" sekund"<<endl;
	
	czas = 0;
	
	cout<<"**************************DFS**************************"<<endl;
	for(int i=0; i<10; i++)
	{
		czasomierz.start();
		graf.przeszukaj_wglab(v1);
		czasomierz.stop();
		czas += czasomierz.getTime();
	}
	czas = czas/10.0;
	cout<<"Czas przeszukania DFS: "<<czas<<" sekund"<<endl;
	
}