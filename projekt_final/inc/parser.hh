#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include "../tinyxml/tinyxml.h"
#include "../inc/Graph.hh"
#define TIXML_USE_STL

using namespace std;

void parseAll(Graph* graf)
{
  TiXmlDocument doc;
  fstream plik;
  string nazwa_linii, sciezka;
  
  system("ls ./baza/ > ./pliki.txt");		//polecenie generujace liste plikow
  plik.open("./pliki.txt", std::ios::in | std::ios::out);
  getline(plik, nazwa_linii);
  while(!plik.eof())
    {					//glowna petla po wszystkich plikach
      sciezka = "./baza/" + nazwa_linii + "/" + nazwa_linii + ".xml";
			//cout<<"Plik: "<<sciezka<<endl;
      doc.LoadFile(sciezka.c_str());
      //	getchar();
      
			TiXmlElement *przystanek;

			TiXmlElement *pRoot = doc.FirstChildElement("linie");
			przystanek = pRoot->FirstChildElement("linia")->FirstChildElement("wariant")->FirstChildElement("przystanek")->FirstChildElement("czasy")->FirstChildElement("przystanek");
		
			do
			  {
			    char *start, *stop;
			    int start_czas, stop_czas;
			    start = (char*)przystanek->Attribute("nazwa");		//nazwa pierwszego przystanku
					if(!graf->isVertex(start))		//brak przystanku w bazie
				  {
				    graf->addVertex(start);		//dodanie nowego przystanku do bazy
						//cout<<start<<"			ID: ";
						//cout<<graf->getNumber(start)<<endl;		//sprawdzenie czy dodal
				  }
					start_czas = atoi((char*)przystanek->Attribute("czas"));
					przystanek = przystanek->NextSiblingElement();
					if(przystanek)
					{
						stop = (char*)przystanek->Attribute("nazwa");		//nazwa drugiego przystanku
						if(!graf->isVertex(stop))		//brak przystanku w bazie
						{
							graf->addVertex(stop);		//dodanie nowego przystanku do bazy
							//cout<<stop<<"			ID: ";
							//cout<<graf->getNumber(stop);		//sprawdzenie czy dodal;
						}
						if(!graf->isConnected(start, stop))		//jezeli brak polaczenia pomiedzy przystankami w bazie
						{
							stop_czas = atoi((char*)przystanek->Attribute("czas"));
							//cout<<"		czas = "<<stop_czas - start_czas<<endl;
							graf->addEdge(graf->getNumber(start), graf->getNumber(stop), abs(stop_czas - start_czas));		//dodaj krawedz pomiedzy wierzcholkami
						}
					}
			 	}while(przystanek);		//petla kreci sie dla kazdej linii
      getline(plik, nazwa_linii);
    }
}
