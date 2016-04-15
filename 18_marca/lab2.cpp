#include <iostream>
#include <ctime>

using namespace std;

class Tablica
{
public:
	int rozmiar, licznik;
	int *tab;
	
	Tablica() //konstruktor ustawiajajacy poczatkowy rozmiar tablicy na 2 elementy i alokujacy pamiec
	{
		rozmiar=2;
		licznik=0;
		tab = new int[rozmiar];
	}

	~Tablica() //destruktor dealokujacy pamiec po tablicy
	{
		delete[] tab;
		tab = NULL;
	}
	
	/*metoda dodajaca element do tablicy i w razie braku miejsca zwiekszajaca jej rozmiar
		int liczba - zmienna do dodania do tablicy
		int tryb - liczba elementow o jaka ma sie zwiekszyc rozmiar tablicy
	*/
		
	void dodajElem(int liczba, int tryb)
	{
		if(licznik>=rozmiar) zwieksz_rozmiar();
		tab[licznik]=liczba;
		licznik++;		
		//cout<<licznik<<endl;
	}
		
	void zwieksz_rozmiar()
	{
		//rozmiar=rozmiar+tryb;
		rozmiar=2*rozmiar;														 //podwojenie rozmiaru tablicy w razie braku miejsca
		int *temp_tablica = new int[rozmiar];
			
		for(int i=0;i<licznik;i++)
			temp_tablica[i]=tab[i];
		delete[] tab;
		tab = temp_tablica;
		temp_tablica = NULL;
	}
	
	void reset()	//metoda do dealokacji pamieci po tablicy i alokacja nowej z domyslnym rozmiarem tablicy 2 elementow
	{
		delete[] tab;
		rozmiar=2;
		licznik=0;
		tab = new int[rozmiar];
	}
	
	int jaki_rozmiar()	//funkcja testowa do podania ilosci elementow w tablicy po zakonczeniu jeje wypelniania
	{
		return rozmiar;
	}
};

class IRunnable	//interfejs klasy Runnalbe
{
public:
	virtual void przygotuj() = 0;
	virtual void uzupelnij(int zakres) = 0;
};

class IStoper	//interfejs klasy Stoper
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual double getTime() = 0;
};

/*klasa do obslugi funkcji pomiaru czasu wykonania operacji uzupelniania tablicy
	start() - pobranie czasu systemowego bezposrednio przed rozpoczeciem operacji
	stop() - pobranie czasu systemowego bezposrednio po zakonczeniu operacji
	getTime() - wyliczenie czasu wykonania operacji i zwrocenie go w sekundach
	*/

class Stoper:public IStoper
{
public:
	time_t t_start, t_stop;
	
	virtual void start(){	t_start = clock();	}
	virtual void stop(){	t_stop = clock();	}
	virtual double getTime(){	return (t_stop-t_start)/(double)CLOCKS_PER_SEC;	}
};

/*
	Glowna klasa obslugujaca zadanie.
	przygotuj() - przygotowuje tablice do uzupelnienia
	uzupelnij(int n) - wypelnienie tablicy n-iloscia elementow i zwrocenie informacji o jej rozmiarze koncowym
*/

class Runnable:public IRunnable
{
public:
	Tablica dyn;
	
	virtual void przygotuj()
	{
		dyn.reset();
	}
	
	virtual void uzupelnij(int n)
	{
		for(int i=0; i<n; i++)
			dyn.dodajElem(1, 100);	//dodawanie liczby 1 do tablicy; zwiekszanie rozmiaru o 100 elementow
		
		//cout<<"Rozmiar tablicy to: "<<dyn.jaki_rozmiar()<<endl;			 //testowe wypisanie koncowego rozmiaru tablicy
	}
	
};

int main()
{
	int zakresy[]={10,100,1000,1000000,1000000000};
	double czas_sredni;
	
		
	Runnable program;
	Stoper czasomierz;
	for (int i=0;i<10;i++)
	{
			program.przygotuj();													//przygotowanie tablicy do wpisania danych
			czasomierz.start();													 //start pomiaru czasu
			program.uzupelnij(zakresy[4]);								//wypelnienie tablicy zadana iloscia elementow
			czasomierz.stop();														//stop pomiaru czasu
			czas_sredni+=czasomierz.getTime();						//zbieranie danych do obliczenia sredniej
	}
	czas_sredni/=10;																	//obliczenie sredniego czasu
	cout<<czas_sredni<<" sekund"<<endl;	//zwrocenie na ekranie zmierzonego czasu w sekundach
}


