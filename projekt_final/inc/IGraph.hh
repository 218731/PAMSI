#ifndef IGRAPH_HH
#define IGRAPH_HH

#include <string>
#include <iostream>
#include <fstream>
#include "queue.hh"
#include "List.hh"

class IGraph {
public:
  virtual void addVertex (std::string Vertex) = 0;
  virtual void addEdge (int vertex1, int vertex2, int distance) = 0;
  virtual List getNeighbours (std::string Vertex) = 0;
  virtual bool isConnected (std::string vertex1, std::string vertex2) = 0;
  virtual std::string getName (int number) = 0;
  virtual int getNumber (std::string name) = 0;
};

#endif
