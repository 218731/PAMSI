#include "Graph.hh"

using namespace std;

Graph::Graph () {
  rozmiar = 1000;
  matrix = new int* [rozmiar];    // Tworzymy tablicê wska¼ników

  for(int i = 0; i < rozmiar; i++)
    matrix[i] = new int [rozmiar]; // Tworzymy wiersze

  // Macierz wype³niamy zerami
  
  for(int i = 0; i < rozmiar; i++) {
    for(int j = 0; j < rozmiar; j++) {
      matrix[i][j] = -1;
    }
  }

  // Tworzymy tablicê przystankow
  listOfVertices = new std::string[rozmiar];
	licznik = 0;
  
  }

Graph::~Graph() {
  for(int i = 0; i < amountOfMatrix; i++) {
    delete [] matrix[i];
  }
  delete [] matrix;
  delete [] listOfVertices;
}

void Graph::listVertices()
{
	for (int i = 0; i < licznik; i++)
		cout<<i+1<<". "<<listOfVertices[i]<<endl;
}

void Graph::addVertex (std::string Vertex) {
	if(licznik > rozmiar)
	{
		rozmiar *= 10;
		std::string *temp = new std::string [rozmiar];
		for(int i=0; i<licznik; i++)
			temp[i] = listOfVertices[i];		//skopiowanie tablicy do wiekszej
		delete [] listOfVertices;
		listOfVertices = temp;
		
		int **newMatrix = new int* [rozmiar];
		for(int i=0; i<licznik; i++)
		{
			newMatrix[i] = new int[rozmiar];
		}																	//alokacja nowej macierzy sasiedztwa
		
		for(int i=0; i<rozmiar; i++)
			for(int j=0; j<rozmiar; j++)
				newMatrix[i][j] = -1;
		
		for(int i=0; i<rozmiar; i++)
			for(int j=0; j<rozmiar; j++)
				newMatrix[i][j] = matrix[i][j];		//skopiowanie starej macierzy do nowej
			
		for(int i=0; i<rozmiar; i++)
			delete [] matrix[i];
			
		delete [] matrix;				//dealokacja pamieci po starej macierzy
		matrix = newMatrix;
	}
	listOfVertices[licznik++] = Vertex;		//dodanie nowego wierzcholka do tablicy
	
	/*
  bool full = true;   //sprawdzenie, czy jest zaalokowana pamiec na nowy wierzcholek
  for (int i=0; i<amountOfMatrix; i++) {
    if (listOfVertices[i] == "") {
      listOfVertices[i] = Vertex;
      full = false;
    }
    }
  if (full == true) {
    amountOfMatrix*=100;   //bo najbardziej wydajne
    std::string * newListOfVertices = new std::string [amountOfMatrix];
    for (int i=0; i<amountOfMatrix; i++) {
      newListOfVertices[i] = listOfVertices[i];
    }
    delete [] listOfVertices;
    listOfVertices = newListOfVertices;
    addVertex (Vertex);
    
    int ** newMatrix = new int* [amountOfMatrix];    // Tworzymy tablicê wska¼ników

  for(int i = 0; i < amountOfMatrix; i++)
    newMatrix[i] = new int [amountOfMatrix]; // Tworzymy wiersze

  // Macierz wype³niamy zerami
  
  for(int i = 0; i < amountOfMatrix; i++) {
    for(int j = 0; j < amountOfMatrix; j++) {
      newMatrix[i][j] = 0;
    }
  }

  for(int i = 0; i < amountOfMatrix; i++) {
    delete [] matrix[i];
  }
  delete [] matrix;

  // !!!
  //nie jestem pewien czy to zadziala w przypadku tablicy dwuwymiarowej
  matrix = newMatrix;
      
  }
	*/
}  

void Graph::addEdge (int vertex1, int vertex2, int distance) {
  matrix[vertex1][vertex2] = distance;
   matrix[vertex2][vertex1] = distance;
  
}

List Graph::getNeighbours (std::string Vertex) {
  int numberOfVertex = getNumber(Vertex);
  List Neighbours;
  for (int i=0; i<amountOfMatrix; i++) {
    if (matrix[numberOfVertex][i] > 0) {
      Neighbours.add(i, Neighbours.size()+1);
    }
  }
  return Neighbours;
}

bool Graph::isVertex(std::string Vertex)		//metoda zwraca 1, gdy przystanek jest w bazie
{
	bool istnieje = 0;
	for(int i=0; i<licznik; i++)
		if(listOfVertices[i] == Vertex) istnieje = 1;
	return istnieje;
}

bool Graph::isConnected (std::string vertex1, std::string vertex2) {
  bool checker = false;
  if (matrix[getNumber(vertex1)][getNumber(vertex2)] > 0){  
    checker = true;
    }

  return checker;
}
float Graph::heuristicFunction (std::string Vertex, std::string Stop) {
  float function = sqrt (pow(Coordinates[getNumber(Vertex)].getX() - Coordinates[getNumber(Stop)].getX(), 2) + pow (Coordinates[getNumber(Vertex)].getY() - Coordinates[getNumber(Stop)].getY(), 2)); //norma eukliesowa

  return function;
}

int Graph::getNumber (std::string Vertex) {
  int number = -2;
  
  try 
	{
    for (int i = 0; i < amountOfMatrix; i++) 
		{
      if (listOfVertices[i] == Vertex) {
				number = i;
      }
    }
    if (number != -2) {
      return number;
    } else throw Exception();  
  } 
	catch (Exception) {
    std::cout << "Przystanku nie ma na liscie" << std::endl;
    exit(1);
  }
}
    
std::string Graph::getName (int numberOfVertex) {
      std::string nameOfVertex = listOfVertices[numberOfVertex];
      return nameOfVertex;
  }

int Graph::getEdge (std::string vertex1, std::string vertex2) {
    int Number1 = getNumber (vertex1);
    int Number2 = getNumber (vertex2);
    
    return matrix[Number1][Number2];
  }
  
int Graph::heuristicFunction (std::string Vertex) {
    int minimum = 100;
		std::string sasiad;
    List neighbours = getNeighbours(Vertex);
    for (int i = 1; i<=neighbours.size() ; i++) 
		{
			sasiad = getName(neighbours.get(i).element);
      if (getEdge(Vertex, sasiad) < minimum) {
				minimum = getEdge(Vertex, sasiad);
      }
      //if (neighbours.get(i).element == 0) break;
    }
    //minimum *= 1/2;
    return minimum;
  }

void Graph::getTheShortestPath (std::string Start, std::string Stop) {
    std::string *listOfStops;
    listOfStops = aStarAlgorithm (Start, Stop);

    std::cout << "Najkrotsza sciezka z " << Start << " do " << Stop << " przebiega przez: " << std::endl;
    for (int i=0; ; i++) {
      if (listOfStops[i] == "") {
	break;
      }
      std::cout << listOfStops[i] << " " << std::endl;
    }
    std::cout << " i wynosi: " << shortestPath << std::endl;
  }

std::string* Graph::aStarAlgorithm (std::string Start, std::string Stop)
{
	int distance = 0;   //dystans od startu do obecnego
	List toCheck;   //kolejka sasiadow wierzcholka do sprawdznie
	List Checked;   //lista juz sprawdzonych
	int distances[licznik];	//lista dystansow dla wierzcholkow
	int parents[licznik]; 	//lista rodzicow dla wierzcholkow
	std::string lastChecked = Start; //trzeba pamietac kogo ostatnio sprawdzalismy
	int tryDistance;  // wszystko bedzie od niego mniejsze na poczatku, a potem bedzie sie samo regulowac
	int pretender;  //wierzcholek ktory ma najmniejsza odleglosc, szukam go w petli

	toCheck.add(getNumber(Start), toCheck.size()+1);
	while((toCheck.size() > 0) && (pretender != getNumber(Stop)))
	{
		tryDistance = 1000;
		for(int i=1; i<=toCheck.size(); i++)
		{
		  int newTryDistance = distance + heuristicFunction(getName(toCheck.get(i).element), Stop) + getEdge (lastChecked, getName(toCheck.get(i).element));
			if (newTryDistance < tryDistance)
			{
				pretender = toCheck.get(i).element;
				tryDistance = newTryDistance;
			}
		}
		Checked.add(pretender, Checked.size()+1);
		toCheck.remove(1);
		
		List neighbours = getNeighbours(getName(pretender));
		for(int i=1; i<=neighbours.size(); i++)
		{
			int sasiad = neighbours.get(i).element;
			bool isChecked = 0;
			for(int n=1; n<=Checked.size(); n++)		//sprawdzenie czy sasiad jest na liscie zamknietych
			{
				if(sasiad == Checked.get(n).element) isChecked = 1;
			}
			
			if(isChecked == 0)
			{
				bool isToCheck = 0;
				for(int j=1; j<=toCheck.size(); j++)
				{
					if(toCheck.get(j).element == sasiad) isToCheck = 1;
				}
				
				if(isToCheck == 0)
				{
					toCheck.add(sasiad, toCheck.size()+1);
					parents[sasiad] = pretender;
					distances[sasiad] = tryDistance + getEdge(getName(pretender), getName(sasiad));
				}
				else
				{
					if((tryDistance + getEdge(getName(pretender), getName(sasiad))) < distances[sasiad+1])
					{
						distances[sasiad] = tryDistance + getEdge(getName(pretender), getName(sasiad));
						parents[sasiad] = pretender;
					}
				}
			}
		}
		//cout<<"Koszt "<<getName(pretender)<<"->"<<lastChecked<<" = "<<getEdge(getName(pretender), lastChecked)<<endl;
		//cout<<"Koszt "<<"Pretficza -> Krucza = "<<getEdge("Krucza", "Pretficza")<<endl;
		distance += getEdge(getName(pretender), lastChecked);
		lastChecked = getName(pretender);
	}
	
	
	//cofaj sie po sasiadach
	toReturn[0] = Stop;
	int parent = pretender, nextParent = getNumber(Stop);
	int i = 1;
	shortestPath = 0;
	do
	{
		parent = parents[parent];
		toReturn[i++] = getName(parent);
		if(nextParent != getNumber(Start))
		{
			shortestPath += getEdge(getName(parent), getName(nextParent));
		}
		nextParent = parent;
	}while(parent != getNumber(Start));
	
	return toReturn;
	
	
	/*
	//daje sasiadow wierzcholka start do kolejki i sprawdzam kazdego z nich, potem bede powtarzal te procedure do skutku
	List neighbours = getNeighbours (Start);
	neighbours.wypisz();
	for (int i = 1; i<=neighbours.size() ; i++)
	{
		toCheck.enqueue(neighbours.get(i).element);
	}

	//petla dziala poki nie znajde sciezki
	while (toCheck.size() > 0)
	{
		std::string Checker = getName(toCheck.dequeue());
		std::cout<<"Checker = "<<Checker<<" ID: "<<getNumber(Checker)<<std::endl;
		getNeighbours(Checker).wypisz();
		getchar();
		if (Checker == Stop)
		{
			distance = distance + heuristicFunction(Checker) + getEdge (lastChecked, Checker);
    }
		else 
		{
			for(int i=1; i<=neighbours.size() ; i++)
			{
				int newTryDistance = distance + heuristicFunction(getName(neighbours.get(i).element)) + getEdge (lastChecked, getName(neighbours.get(i).element));
				if (newTryDistance < tryDistance)
				{
					pretender = neighbours.get(i).element;
					tryDistance = newTryDistance;
	  		}
			}
			std::cout << "WYJSCIE Z PETLI 1" <<std::endl;
			Checked.add (pretender,Checked.size()+1);

			int toCheck_size = toCheck.size();
			for (int i =0; i< toCheck_size;i++)
			{
				toCheck.dequeue(); //petla powinna sie nie skonczyc, bo na koncu iteracji kolejka nie bedzie pusta
			}
			std::cout << "WYJSCIE Z PETLI 2" <<std::endl;
			List neighboursX = getNeighbours (getName (pretender));
			int neighboursX_size = neighboursX.size();
			for (int i=1; i <= neighboursX_size; i++)
			{
				toCheck.enqueue(neighbours.get(i).element);
			}
			lastChecked = getName(pretender);
    }
	}
  std::cout << "WYJSCIE Z PETLI 3" <<std::endl;   
	shortestPath = distance;   //zapisuje sciezke
	//std::string * result;
	//for(int i=0; i<Checked.size(); i++) {
	//  result[i] = Checked.get(i).element;
	//}
	std::cout << "WYJSCIE Z PETLI 4" <<std::endl;
	int Checked_size = Checked.size();
	for(int i=0; i<Checked_size; i++)
	{
		toReturn [i] = getName(Checked.remove(1).element);
	}
	std::cout << "WYJSCIE Z PETLI 5" <<std::endl;
	return toReturn;
*/

}

void Graph::loadCoordinates()
{
	fstream gpsData;
	char znak;
	string przystanek, bufor, daneGPS;
	int i;
	float dlugosc, szerokosc;
	
	gpsData.open("GTFS_data/stops.csv", ios::in | ios::out);
	if(gpsData.good())
	{
		do
		{
			i=0;
			getline(gpsData, bufor);
			do
			{
				znak = bufor[i++];
				przystanek += znak;
			}while(znak != ';');

			do
			{
				znak = bufor[i++];
				daneGPS += znak;
			}while(znak != ';');
			dlugosc = atof(daneGPS.c_str());
			daneGPS.clear();
			
			do
			{
				znak = bufor[i++];
				daneGPS += znak;
			}while(i < (int)bufor.length());
			szerokosc = atof(daneGPS.c_str());
			daneGPS.clear();

			przystanek.pop_back();
			
			Coordinates[getNumber(przystanek)].setX(dlugosc);
			Coordinates[getNumber(przystanek)].setY(szerokosc);
						
			cout<<przystanek<<" GPS: "<<dlugosc<<" N, "<<szerokosc<<" E"<<endl;
			getchar();
			przystanek.clear();
		}while(!gpsData.eof());
	}
}
 
