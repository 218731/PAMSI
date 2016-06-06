#include <iostream>
#include "parser.hh"
#include "Graph.hh"
#include "queue.hh"

using namespace std;

int main(int argc, char* argv[]) {
/*
  if (argc == 1) {
    std::cout << "Brak argumentow wywolania! Dodaj przystanek poczatkowy i koncowy" << std::endl;
  } else {
    string start = (string)argv[1];
    string stop = (string)argv[2];
*/
	string start, stop;
	cout<<"Podaj przystanki:"<<endl;
	cout<<"Start: ";
	getline(cin, start);
	cout<<"Stop: ";
	getline(cin, stop);
	Graph* graf = new Graph;
	parseAll (graf);
	//graf->listVertices();
	//getchar();
	//List sasiedzi = graf->getNeighbours("Stanki");
	//sasiedzi.wypisz();
	//getchar();

	graf->getTheShortestPath(start, stop);
//}
}
