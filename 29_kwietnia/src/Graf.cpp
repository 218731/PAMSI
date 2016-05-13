#include <iostream>
#include <string>
#include "Graf.hh"

using namespace std;

Graf::Graf()
{
	liczba_wierzcholkow = 2;
	rozmiar = 2;
	/*
	sasiedzi = new int *[liczba_wierzcholkow];
	for(int i=0;i<rozmiar;i++)
	{
		sasiedzi[i] = new int[liczba_wierzcholkow];
		for(int j=0; j<rozmiar; j++)
			sasiedzi[i][j] = 0;
	}
	*/
}

int Graf::dodaj_wierzcholek()
{
	if((liczba_wierzcholkow + 1) > rozmiar)		//powiekszenie macierzy sasiedztwa
	{
		rozmiar+=10;
		int **temp = new int *[rozmiar];
		for(int i=0; i<rozmiar-10; i++)
		{
			temp[i] = new int [rozmiar];
			for(int j=0; j<rozmiar-10; j++)
				temp[i][j] = sasiedzi[i][j];
		}
		
		for(int i=liczba_wierzcholkow+1; i<rozmiar; i++)
			for(int j=liczba_wierzcholkow; j<rozmiar; j++)
				temp[i][j] = 0;
		
			
		for(int i=0; i<rozmiar-10; i++)
			delete [] sasiedzi[i];
		delete [] sasiedzi;
		sasiedzi = temp;
	}
	
	liczba_wierzcholkow++;
	return liczba_wierzcholkow;
}

void Graf::dodaj_krawedz(int v1, int v2)
{
	sasiedzi[v1][v2] = 1;
}

void Graf::wczytaj_macierz()
{
	int liczebnosc_grafu=0, sasiad;
	fstream plik;
	
	plik.open("graf.txt", std::ios::in);
	if(plik.good())
	{
		plik>>liczebnosc_grafu;		//liczba wierzcholkow
		liczba_wierzcholkow = liczebnosc_grafu;
		
		sasiedzi = new int *[liczba_wierzcholkow];
		for(int i=0;i<liczba_wierzcholkow;i++)
		{
			sasiedzi[i] = new int[liczba_wierzcholkow];
			for(int j=0; j<liczba_wierzcholkow; j++)
				sasiedzi[i][j] = 0;
		}
		
		for(int i=0; i<liczebnosc_grafu; i++)		//ustalenie sasiadow dla wszystkich wierzcholkow
		{
			for(int j=0; j<liczebnosc_grafu; j++)
			{
				plik>>sasiad;
				sasiedzi[i][j] = sasiad;
			}
		}
	}
	else
	{
		cout<<"blad otwarcia pliku!"<<endl;
		throw "Nie otworzyłem pliku!";
	}
}

void Graf::wypisz()
{
	cout<<"Wypisuje"<<endl;
	for(int i=0; i<liczba_wierzcholkow; i++)
	{
		for(int j=0; j<liczba_wierzcholkow; j++)
			cout<<sasiedzi[i][j]<<" ";
		cout<<endl;
	}
}

bool Graf::jest_polaczony(int v1, int v2)
{
	if(sasiedzi[v1-1][v2-1] == 1) return 1;
	else return 0;
}

Queue Graf::zwroc_sasiadow_BFS(int v)
{
	Queue zwrot;
	for(int i=0; i<liczba_wierzcholkow; i++)
	{
		if(sasiedzi[v][i] == 1) zwrot.push(i);
	}
	return zwrot;
}

Stack Graf::zwroc_sasiadow_DFS(int v)
{
	Stack zwrot;
	for(int i=liczba_wierzcholkow; i>0; i--)
	{
		if(sasiedzi[v][i] == 1) zwrot.push(i);
	}
	return zwrot;
}

void Graf::przeszukaj_wszerz(int v)
{
	Queue do_odwiedzenia, temp;
	bool *odwiedzone = new bool[liczba_wierzcholkow];
	
	
	for(int i=0; i<liczba_wierzcholkow; i++)		//zerowanie tablicy odwiedzonych
	{
		odwiedzone[i] = 0;
	}
	
	for(int i=0; i<liczba_wierzcholkow; i++)		//dodanie do kolejki sasiadow wierzcholka 'v'
	{
		if(sasiedzi[v-1][i] == 1)
		{
			do_odwiedzenia.push(i);
			odwiedzone[i] = 1;
		}
	}
	
	odwiedzone[v-1] = 1;		//odwiedzenie pierwszego wierzcholka
	
	int aktualny_wierzcholek, czy_odwiedzac;
	//cout<<"LET'S BFS!"<<endl;
	//cout<<"Startuje przeszukanie z "<<v<<endl;
	//cout<<"odwiedzilem "<<v<<endl;
	do
	{
		aktualny_wierzcholek = do_odwiedzenia.pop().element;
		odwiedzone[aktualny_wierzcholek] = 1;
		//cout<<"odwiedzilem "<<aktualny_wierzcholek + 1<<endl;		//testowe wypisywanie odzwiedzonych wierzcholkow
		temp = zwroc_sasiadow_BFS(aktualny_wierzcholek);
		
		int temp_rozmiar = temp.size();
		for(int i=0; i<temp_rozmiar; i++)
		{
			czy_odwiedzac = temp.pop().element;
			if(odwiedzone[czy_odwiedzac] == 0)
			{
				odwiedzone[czy_odwiedzac] = 1;
				do_odwiedzenia.push(czy_odwiedzac);
			}
		}
	}while(do_odwiedzenia.size() != 0);
	
	//cout<<"END OF BFS! :D"<<endl;
}

void Graf::przeszukaj_wglab(int v)
{
	Stack do_odwiedzenia, temp;
	int aktualny_wierzcholek, czy_odwiedzac;
	bool *odwiedzone = new bool[liczba_wierzcholkow];
	
	for(int i=0; i<liczba_wierzcholkow; i++)		//zerowanie tablicy odwiedzonych
	{
		odwiedzone[i] = 0;
	}
	
	for(int i=0; i<liczba_wierzcholkow; i++)		//dodanie do stosu sasiadow wierzcholka 'v'
	{
		if(sasiedzi[v-1][i] == 1)
		{
			do_odwiedzenia.push(i);
			odwiedzone[i] = 1;
		}
	}
	
	//cout<<"LET'S DFS!"<<endl;
	//cout<<"Startuje przeszukanie z "<<v<<endl;
	odwiedzone[v-1] = 1;		//odwiedzenie wierzcholka startowego
	
	do
	{
		aktualny_wierzcholek = do_odwiedzenia.pop();
		//cout<<"odwiedzilem "<<aktualny_wierzcholek + 1<<endl;		//testowe wypisywanie odzwiedzonych wierzcholkow
		temp = zwroc_sasiadow_DFS(aktualny_wierzcholek);
		
		int temp_rozmiar = temp.size();
		for(int i=0; i<temp_rozmiar; i++)
		{
			czy_odwiedzac = temp.pop();
			if(odwiedzone[czy_odwiedzac] == 0)
			{
				odwiedzone[czy_odwiedzac] = 1;
				do_odwiedzenia.push(czy_odwiedzac);
			}
		}
		
	}while(do_odwiedzenia.size() != 0);
	//cout<<"END OF DFS! :D"<<endl;
}

