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
