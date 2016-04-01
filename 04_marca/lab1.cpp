#include <iostream>
#include <ctime>

using namespace std;

class Tablica
{
public:
  int rozmiar, licznik;
  int *tab;
  
  Tablica()
  {
    rozmiar=2;
    licznik=0;
    tab = new int[rozmiar];
  }

  ~Tablica()
  {
    delete[] tab;
    tab = NULL;
  }

  void dodajElem(int liczba, int tryb)
  {
    if(licznik>=rozmiar)
      { 
	rozmiar=rozmiar+tryb;
	int *temp_tablica = new int[rozmiar];
	for(int i=0;i<licznik;i++)
	  temp_tablica[i]=tab[i];
	delete[] tab;
	tab = temp_tablica;
	//delete[] temp_tablica;
	temp_tablica=NULL;
      }
    tab[licznik]=liczba;
    licznik++;    
  }

  void wypisz()
  {
    for(int j=0; j<rozmiar; j++) cout<<tab[j]<<", ";
  }

  void reset()
  {
    delete[] tab;
    rozmiar=2;
    licznik=0;
    tab = new int[rozmiar];
  }
};


int main()
{
  time_t start, stop;
  //srand(time(NULL));
  //int liczba;
  Tablica dyn;
  int zakresy[]={10,100,1000,1000000,1000000000};
  for(int j=0;j<(int)(sizeof(zakresy)/sizeof(zakresy[0]));j++)
    {
      cout<<"Wpisywanie "<<zakresy[j]<<" liczb, krok: 1 "<<endl;
      start=clock();    
      for(int i=0; i<zakresy[j]; i++)
	{
	  //liczba=rand();
	  dyn.dodajElem(1, 1);
	}
      stop=clock();
      cout<<"Wpisanie zajęło: "<<(stop-start)/(double)CLOCKS_PER_SEC<<" sek"<<endl<<endl;
      dyn.reset();
    }
}
