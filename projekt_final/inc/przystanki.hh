//funkcja sluzaca do stworzenia listy przystankow
#include <string>
#include <fstream>

using namespace std;

void generuj_przystanki(string nazwa_pliku)
{
	fstream plik;
	char znak = '\0';
	string przystanek, bufor;
	string lista[1000];
	int licznik = 0;
	bool bylo = 0;
	
	plik.open(nazwa_pliku, std::ios::in | std::ios::out);
	if(plik.good())
	{
		do
		{
			do
			{
				plik>>znak;
			}while(znak!='"');		//zczytywanie pomijajace numer linii
			do
			{
				bylo = 0;
				przystanek.clear();
				znak = '\0';
				do
				{
					przystanek += znak;
					plik>>std::noskipws>>znak;
				}while((znak!='-') && (znak!='|'));		//zczytanie pojedynczego przystanku
				//cout<<"Wczytany przystanek: "<<przystanek<<endl;
				if(znak!='|') plik>>std::noskipws>>znak;		//zczytanie zbednej spacji
				
				przystanek.erase(0,1);
				przystanek.erase(przystanek.length()-1, 1);
				
				for(int i=0; i<licznik; i++)
				{
					if(lista[i] == przystanek) bylo=1;					
				}
				if(bylo == 0) lista[licznik++] = przystanek;		//dodanie do tablicy przystankow
			}while(znak!='|');		//zczytywanie calej linii
		getline(plik, bufor);		//zczytanie reszty linijki i przejscie do kolejnej
		}while(!plik.eof());
	}
	plik.close();
	
	plik.open("lista.txt", ios::out);
	for(int i=0; i<licznik; i++)
	{
		plik<<lista[i]<<endl;
	}
}