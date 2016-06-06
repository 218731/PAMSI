#ifndef GRAPH_HH
#define GRAPH_HH

#include "IGraph.hh"
#include "List.hh"
#include <fstream>
#include <iomanip>
#include <cmath>

struct Coordinate {

 private:
  float x;
  float y;

 public:
  void setX (float newX) {
    x = newX;
  }
  
  void setY (float newY) {
    y = newY;
  }
  
  float getX () {
    return x;
  }
  
  float getY () {
    return y;
  }
};

class Graph : public IGraph {

private:
  Coordinate Coordinates[1000];
  int ** matrix;   //macierz sasiedztwa, poczatkowy rozmiar 100x100
  std::string *listOfVertices;   //tablica z nazwami przystankow odpowiadajacymi indeksom macierzy sasiedztwa
  int amountOfMatrix = 1000;   //initialValue w konstruktorze
  int shortestPath;
	int licznik, rozmiar;		//zmienne informujace o ilosci przystankow oraz rozmiarze tablicy
  std::string toReturn[100];
  
  
public:
  Graph ();  //tworze graf, ktory na poczatku ma pojemnosc 100 wierzcholkow
  ~Graph ();  //usuwam graf
  void listVertices();
  void loadCoordinates();
  float heuristicFunction (std::string Vertex, std::string Stop); //funkcja heurystyczna, liczaca norme euklidesowa dwoch punktow na plaszczyznie
  void addVertex (std::string Vertex); //dodaje wierzcholek do istniejacych (ewentualne powiekszenie tablic matrix i listOfVertices 
  void addEdge (int vertex1, int vertex2, int distance);  //dodaje krawedz doistniejacych
  List getNeighbours (std::string Vertex);  //pobieram sasiadow wierzcholka
	bool isVertex (std::string Vertex);		//sprawdza czy wierzcholek jest w bazie
  bool isConnected (std::string vertex1, std::string vertex2);  //sprawdzam czy jest droga pomiedzy dwoa wierzcholkamie
  int getNumber (std::string name); //z nazwy dostaje indeks do tablic
  std::string getName (int number); //z indeksu do tablic dostaje nazwe
  int getEdge (std::string vertex1, std::string vertex2);  //dostaje odleglosc miedzy dwoma wierzcholkami
  int heuristicFunction (std::string Vertex);  //obliczanie prawdopodobnej sciezki
  std::string* aStarAlgorithm (std::string Start, std::string Stop); //algorytm
  void getTheShortestPath (std::string Start, std::string Stop); //algorytm opakowany w cout
  class Exception{};
}; 

  
#endif
