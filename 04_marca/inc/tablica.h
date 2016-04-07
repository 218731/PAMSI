class Tablica
{
	int rozmiar, licznik;
	int *tab;

public:
	Tablica();

	~Tablica();

	void dodajElem(int liczba, int tryb);

	void reset();
};