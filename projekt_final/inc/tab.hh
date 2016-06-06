#ifndef TAB_HH
#define TAB_HH

#include <cstdlib>
#include <iostream>
#include <cstring>

/* Deklaracja klasy tablica, przechowującej dynamicznie obiekty typu integer.
Zmienne prywatne:
wielkosc - wielkosc tablicy, definiowana w konstruktorze
zajete - liczba wykorzystanych komorek tablicy
*tab - zmienna przechowujaca komorki tablicy
Metody:
Tablica - konstruktor
~Tablica - destruktor
dodajElem - metoda dodajaca jeden element do tablicy
rozmiar - zwraca rozmiar tablicy
*/

template <class T> class Tablica {
private:
  int zajete;     //liczba wykorzystanych komorek tablicy
  T* tab;       //zmienna przechowujaca komorki tablicy
  int wielkosc;   //wielkosc tablicy   

public:
  
  Tablica (const int &rozmiar);         //konstruktor tablicy
  Tablica ();
  virtual void Wyczysc ();
  virtual ~Tablica ();                          //destruktor tablicy
  Tablica (const Tablica & tabl);         //konstruktor kopiujacy
  virtual void dodajElem (const T &elem);     //dodawanie elementu, powiekszanie o 1 w przypadku braku wolnego miejsca
  virtual void dodajElemPlus (const T &elem); //dodawanie elementu, powiekszanie o 100 w przypadku braku wolnego miejsca
  virtual void dodajElemRazy (const T &elem); //dodawanie elementu, powiekszanie razy 2 w przypadku braku wolnego miejsca
  virtual int rozmiar ();                       //zwraca wielkosc tablicy
  virtual void dodaj (const T& element, int miejsce);
  virtual void usun (int miejsce);
  virtual T wyswietl (int miejsce);
  virtual bool szukaj (int szukany);
  class outOfBoundsException {};
};


template <class T> Tablica<T>::Tablica (const int &rozmiar) {
  wielkosc=rozmiar;
  zajete=0;
  tab=new T[rozmiar];
}
template <class T> Tablica<T>::Tablica() {
  wielkosc=1;
  zajete=0;
  tab=new T[wielkosc];
}
template <class T> Tablica<T>::Tablica (const Tablica & tabl) {
  tab=new T[wielkosc];
  memcpy (tab, tabl.tab, wielkosc);
}
  

template <class T> Tablica<T>::~Tablica () {
  delete []tab;
}
template <class T> void Tablica<T>::Wyczysc () {
  delete []tab;
  T* nowaTab = new T[1];
  tab= nowaTab;
}

template <class T> void Tablica<T>::dodajElem (const T &elem) {
  ++zajete;
  if (zajete>wielkosc) {
    T* nowaTab = new T[zajete];
    wielkosc++;
    for (int i=0; i<=(zajete-2); i++) {
      nowaTab[i] = tab[i];
    }		
    nowaTab [zajete-1]=elem;

    delete []tab;
    tab = nowaTab;
  } else tab [zajete-1] = elem;
}
template <class T> void Tablica<T>::dodajElemPlus (const T &elem) {
  ++zajete;
  if (zajete>wielkosc) {
    T* nowaTab = new T[zajete+100];
    wielkosc+=100;
    for (int i=0; i<=(zajete-2); i++) {
      nowaTab[i] = tab[i];
    }
    nowaTab [zajete-1]=elem;
    delete []tab;
    tab = nowaTab;
  } else tab [zajete-1] = elem;
}
template <class T> void Tablica<T>::dodajElemRazy (const T &elem) {
  ++zajete;
  if (zajete>wielkosc) {
    T* nowaTab = new T[zajete*2];
    wielkosc*=2;
    for (int i=0; i<=(zajete-2); i++) {
      nowaTab[i] = tab[i];
    }
    nowaTab [zajete-1]=elem;
    delete []tab;
    tab = nowaTab;
  } else tab [zajete-1] = elem;
}
template <class T> int Tablica<T>::rozmiar() {
    return zajete;
  }

template <class T> void Tablica<T>::dodaj (const T& element, int miejsce) {
 try {
    if ( miejsce < 0) {
      throw outOfBoundsException();
    } else {
      if (miejsce==1) {
	++zajete;
	T* nowaTab = new T[wielkosc+1];
	wielkosc+=1;
	nowaTab[miejsce-1]=element;
	for (int i=(miejsce); i<wielkosc; i++) {
	  nowaTab[i]=tab[i-1];
	}
	delete []tab;
	tab=nowaTab;
      }else if (miejsce == wielkosc || zajete==wielkosc) {
	++zajete;
	T* nowaTab = new T[wielkosc*2];
	wielkosc*=2;
	for (int i=0; i<=(miejsce-2); i++) {
      nowaTab[i] = tab[i];
	}
	nowaTab[miejsce-1]=element;
	for (int i=(miejsce); i<wielkosc; i++) {
	  nowaTab[i]=tab[i-1];
	}
	delete []tab;
	tab=nowaTab;
      } else {
	++zajete;
	T* nowaTab = new T[wielkosc];
	for (int i=0; i<=miejsce-2; i++) {
	  nowaTab[i]=tab[i];
	} 
	nowaTab[miejsce-1] = element;
	for (int i=miejsce; i<wielkosc; i++) {
	  nowaTab[i]=tab[i-1];
	} 
	delete []tab;
	tab=nowaTab;
      }
    }  
  }
  catch (outOfBoundsException) {
    std::cout << "zły indeks"<<std::endl;
    exit(1);
  }
  }

  template <class T> void Tablica <T>::usun (int miejsce) {
    try {
      if (miejsce > wielkosc || miejsce < 0) {
	throw outOfBoundsException();
      } else {
	--zajete;
	T* nowaTab = new T[wielkosc-1];
	wielkosc-=1;
	for (int i=0; i<(miejsce-1); i++) {
	  nowaTab[i] = tab[i];
	}
	for (int i=(miejsce-1); i<wielkosc; i++) {
	  int k=miejsce;
	  nowaTab[i]=tab[k];
	  ++k;
	}
	delete []tab;
	tab = nowaTab;
      }
    }
    catch (outOfBoundsException) {
      std::cout <<"Wyjście poza zakres, koniec "<< std::endl;
    }
  }



    
    template <class T> T Tablica <T>::wyswietl (int miejsce) {
      return tab[miejsce-1];
   }

template <class T> bool Tablica<T>::szukaj (int szukany) {
  bool searched=false;
  for (int i=1; i<=rozmiar(); i++)  {
    if (wyswietl(i) == szukany) {
      searched=true;
      break;
    }
  }
  return searched;
}


#endif
