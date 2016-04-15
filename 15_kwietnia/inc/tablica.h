class Tablica
{
	int rozmiar, licznik;
	Tom *tab;

public:
	Tablica();

	~Tablica();

	void dodajElem(int liczba, int tryb);

	void reset();
	
	int rozmiar();
};