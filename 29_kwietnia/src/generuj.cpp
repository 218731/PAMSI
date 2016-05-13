#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	cout<<"GENERATOR GRAFU"<<endl;
	fstream plik;
	int liczebnosc_grafu, sasiad;
	int **macierz;
	
	plik.open("graf.txt", std::ios::in | std::ios::out | std::ios::trunc);
	if(plik.good())
	{
		cout<<"Ile wierzcholkow: ";
		cin>>liczebnosc_grafu;
		
		macierz = new int *[liczebnosc_grafu];
		for(int i=0; i<liczebnosc_grafu; i++)
		{
			macierz[i] = new int[liczebnosc_grafu];
			for(int j=0; j<liczebnosc_grafu; j++)
				macierz[i][j] = 0;
		}
		
		plik<<liczebnosc_grafu<<endl;		//liczba wierzcholkow
		for(int i=0; i<liczebnosc_grafu; i++)		//ustalenie sasiadow dla wszystkich wierzcholkow
		{
			for(int j=0; j<liczebnosc_grafu; j++)
			{
				if(i == j) sasiad = 0;
				else sasiad = rand()%2;
				macierz[i][j] = sasiad;
				for(int k=0; k<i; k++)
				{
					macierz[i][k] = macierz[k][i];
				}
			}
		}
		/*
			for(int i=0; i<liczebnosc_grafu; i++)		//testowe wypisanie macierzy oraz wpisanie jej do pliku
			{
				for(int j=0; j<liczebnosc_grafu; j++)
				{
					cout<<macierz[i][j]<<" ";
					plik<<macierz[i][j]<<" ";
				}
				cout<<endl;
				plik<<endl;
			}
		*/
	}
	
	/*
	{
		cout<<"Ile wierzcholkow: ";
		cin>>liczebnosc_grafu;
		plik<<"Liczba wierzcholkow: "<<liczebnosc_grafu<<endl;		//liczba wierzcholkow
		for(int i=0; i<liczebnosc_grafu; i++)		//ustalenie sasiadow dla wszystkich wierzcholkow
		{
			liczba_sasiadow = rand()%liczebnosc_grafu + 1;
			plik<<"Liczba krawedzi dla "<<i<<" : "<<liczba_sasiadow<<endl;
			for(int j=0; j<liczba_sasiadow; j++)
			{
				do
				{
					sasiad = rand()%liczebnosc_grafu;		//losowanie sasiada
				}while(sasiad == i);
				if(sasiad == i) cout<<sasiad<<" == "<<i<<" NOPE!"<<endl;
				else
					plik<<"Sasiad: "<<sasiad<<endl;
			}
		}
	}
	
	*/
}