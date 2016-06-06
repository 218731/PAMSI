#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include "../tinyxml/tinyxml.h"
#include "../inc/Graph.hh"
#define TIXML_USE_STL

using namespace std;

int main()
{
	Graph graf;
	TiXmlDocument doc;
	fstream plik;
	string nazwa_linii, sciezka, lista_przystankow[1000];
	int licznik = 0;
	bool bylo;
	
	system("ls ./baza/ > ./baza/pliki.txt");		//polecenie generujace liste plikow
	plik.open("baza/pliki.txt", std::ios::in | std::ios::out);
	if(plik.good()) cout<<"Jest plik. Mamy to Mietek!"<<endl;
	getchar();
	do
	{					//glowna petla po wszystkich plikach
		getline(plik, nazwa_linii);
		sciezka = "./baza/" + nazwa_linii + "/" + nazwa_linii + ".xml";
		cout<<sciezka<<endl;
		bool loadOkay = doc.LoadFile(sciezka.c_str());

		if(loadOkay)
			printf("open success\n");
		else
			printf("Failed to load file\n");

		TiXmlElement *przystanek;

		TiXmlElement *pRoot = doc.FirstChildElement("linie");
		przystanek = pRoot->FirstChildElement("linia")->FirstChildElement("wariant")->FirstChildElement("przystanek")->FirstChildElement("czasy")->FirstChildElement("przystanek");
		if(!pRoot) cout<<"Brak";
			else cout<<"Jest korzen"<<endl;

			do
			{
				char *start, *stop;
				int start_czas, stop_czas;
				start = (char*)przystanek->Attribute("nazwa");
				bylo = 0;
				for(int i=0; i<licznik; i++)			//sprawdzenie czy przystanek istnieje w bazie
				{
					if(lista_przystankow[i] == start) bylo = 1;
				}
				if(bylo == 0)		//brak przystanku w bazie
				{
					lista_przystankow[licznik++] = start;		//dodanie przystanku do tablicy w celu unikniecia powtorzen
					graf.addVertex(nazwa);		//dodanie nowego przystanku do bazy
				}
				start_czas = atoi((char*)przystanek->Attribute("czas"));
				przystanek = przystanek->NextSiblingElement();
				if(przystanek)
				{
					cout<<start<<" > ";
					stop = (char*)przystanek->Attribute("nazwa");
					cout<<stop;
					stop_czas = atoi((char*)przystanek->Attribute("czas"));
					cout<<"	"<<stop_czas - start_czas<<" minut"<<endl;
				}
			}while(przystanek);		//petla kreci sie dla kazdej linii
		getchar();
	}while(!plik.eof());
}