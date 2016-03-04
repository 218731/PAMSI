#include <iostream>

using namespace std;

class Tablica
{
public:
  int* tab;
  int il_el=0;

  int ile()
  {
    return sizeof(tab)/sizeof(tab[0]);
  }

  Tablica();
  ~Tablica();

};


Tablica::Tablica()
{
  Tablica=new int[5];
}
 
Tablica::~Tablica()
{
  delete [] Tablica;
}

ostream & operator << (ostream& out, Tablica const& tab)
{
    for(int i=0; i<tab.il_el; i++)
      out<<tab[i];
    return out;
}

  istream & operator >> (istream& in, Tablica& tab)
  {
    if(tab.ile()<tab.il_el)
      {
    tab.il_el++;
    in>>tab[tab.ile];
      }
      else
    {
      Tablica=new int[tab.il_el+1];
      tab.il_el++;
      in>>tab[tab.il_el];
    }
    return in;
}


int main()
{
  Tablica tab;
  cout<<tab;
}
