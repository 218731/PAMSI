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