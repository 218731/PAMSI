#include <iostream>
#include <string>
#include "Graf.hh"
#include "PQueue.h"

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
	sasiedzi[v1-1][v2-1] = 1;
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
	cout<<"Macierz sasiedztwa:"<<endl;
	for(int i=0; i<liczba_wierzcholkow; i++)
	{
		for(int j=0; j<liczba_wierzcholkow; j++)
			cout<<sasiedzi[i][j]<<" ";
		cout<<endl;
	}
}

bool Graf::jest_polaczony(int v1, int v2)
{
	if(sasiedzi[v1-1][v2-1] != 0) return 1;
	else return 0;
}

Queue Graf::zwrocSasiadow(int v)
{
	Queue listaSasiadow;
	for(int i=0; i<liczba_wierzcholkow; i++)
		if(sasiedzi[v][i] > 0) listaSasiadow.push(i);
	return listaSasiadow;
}

int Graf::branchAndBound(int start, int stop)
{
	start -=1; stop -= 1;		//dostosowanie wirzcholkow do indeksu w macierzy
	
	PQueue toCheck;		//lista do sprawdzenia
	PQueue distances;	//dystans od startu do obecnego
	int actualCost, lowestCost = 0;
	int actualVert;
	int numberOfExtentions = 0;
	
	toCheck.push(start, 0);		//dodanie startowego wierzcholka do odwiedzenia
	distances.push(0, 0);
	
	while(toCheck.size() > 0)
	{
		actualVert = toCheck.pop().element;
		actualCost = distances.pop().element;
		if(actualVert == stop)
		{
			lowestCost = actualCost;
			break;		//znaleziono trase pierwszy raz
		}
		
		Queue listaSasiadow = zwrocSasiadow(actualVert);		//sasiedzi aktualnego wierzcholka
		while(listaSasiadow.size() > 0)
		{
			int sasiad = listaSasiadow.pop().element;
			toCheck.push(sasiad, actualCost + sasiedzi[actualVert][sasiad]);
			numberOfExtentions++;
			distances.push(actualCost + sasiedzi[actualVert][sasiad], actualCost + sasiedzi[actualVert][sasiad]);
		}
	}
	
	while(toCheck.size() > 0)
	{
		actualVert = toCheck.pop().element;
		actualCost = distances.pop().element;
		
		if(actualCost < lowestCost)
		{
			if(actualVert == stop) lowestCost = actualCost;
			else
			{
				Queue listaSasiadow = zwrocSasiadow(actualVert);		//sasiedzi aktualnego wierzcholka
				while(listaSasiadow.size() > 0)
				{
					int sasiad = listaSasiadow.pop().element;
					toCheck.push(sasiad, actualCost + sasiedzi[actualVert][sasiad]);
					numberOfExtentions++;
					distances.push(actualCost + sasiedzi[actualVert][sasiad], actualCost + sasiedzi[actualVert][sasiad]);
				}
			}
		}
		else break;		//bo jezeli kolejka jest priorytetowa, a ten warunek nie jest spelniony
	}								//to juz nigdy nie bedzie
	cout<<"Extentions: "<<numberOfExtentions<<"		";
	return lowestCost;
}

int Graf::branchAndBoundExtendedList(int start, int stop)
{
	start -=1; stop -= 1;		//dostosowanie wirzcholkow do indeksu w macierzy
	
	PQueue toCheck;		//lista do sprawdzenia
	PQueue distances;	//dystans od startu do obecnego
	List extendedList;
	int actualCost, lowestCost = 0;
	int actualVert;
	int numberOfExtentions = 0;
	bool Checked;
	
	toCheck.push(start, 0);		//dodanie startowego wierzcholka do odwiedzenia
	distances.push(0, 0);
	
	while(toCheck.size() > 0)
	{
		actualVert = toCheck.pop().element;
		actualCost = distances.pop().element;
		if(actualVert == stop)
		{
			lowestCost = actualCost;
			break;		//znaleziono trase pierwszy raz
		}
		
		Checked = 0;
		for(int i=1; i<extendedList.size()+1; i++)
		{
			if(extendedList.get(i).element == actualVert) Checked = 1;
		}
		if(Checked == 0)
		{
			extendedList.add(actualVert, extendedList.size()+1);
			Queue listaSasiadow = zwrocSasiadow(actualVert);		//sasiedzi aktualnego wierzcholka
			while(listaSasiadow.size() > 0)
			{
				int sasiad = listaSasiadow.pop().element;
				toCheck.push(sasiad, actualCost + sasiedzi[actualVert][sasiad]);
				numberOfExtentions++;
				distances.push(actualCost + sasiedzi[actualVert][sasiad], actualCost + sasiedzi[actualVert][sasiad]);
			}
		}
	}
	
	while(toCheck.size() > 0)
	{
		actualVert = toCheck.pop().element;
		actualCost = distances.pop().element;
		
		if(actualCost < lowestCost)
		{
			if(actualVert == stop) lowestCost = actualCost;
			else
			{
				Checked = 0;
				for(int i=1; i<extendedList.size()+1; i++)
				{
					if(extendedList.get(i).element == actualVert) Checked = 1;
				}
				if(Checked == 0)
				{
					Queue listaSasiadow = zwrocSasiadow(actualVert);		//sasiedzi aktualnego wierzcholka
					while(listaSasiadow.size() > 0)
					{
						int sasiad = listaSasiadow.pop().element;
						toCheck.push(sasiad, actualCost + sasiedzi[actualVert][sasiad]);
						numberOfExtentions++;
						distances.push(actualCost + sasiedzi[actualVert][sasiad], actualCost + sasiedzi[actualVert][sasiad]);
					}
				}
			}
		}
		else break;		//bo jezeli kolejka jest priorytetowa, a ten warunek nie jest spelniony
	}								//to juz nigdy nie bedzie
	cout<<"Extentions: "<<numberOfExtentions<<endl;
	return lowestCost;
}

