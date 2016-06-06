#ifndef LISTA_HH
#define LISTA_HH

#include "tab.hh"

/* Klasa implementuj±ca listê */

template <class T> class Lista {

private:
  Tablica <T> *lista;

public:
  void add (T element, int position);  // throws outOfRangeException;
  void remove (int position);
  T get (int position);
  int size ();
  Lista();
  ~Lista(); 
  int search (T element);
  class outOfRangeException{};
};	   
template<class T> Lista<T>::Lista() {
  lista = new Tablica <T>;
}
template<class T>Lista<T>::~Lista() {
  delete[] lista;
}

template<class T> void Lista<T>::add (T element, int position) {
    lista->dodaj(element, position);
}

template<class T>void Lista<T>::remove (int position) {
  lista->usun(position);
}

template<class T>T Lista<T>::get (int position) {
  return lista->wyswietl(position);
}

template<class T> int Lista<T>::size () {
      return lista->rozmiar();
}

template<class T> int Lista<T>::search (T element) {
  int position;
  for (int a=0; a<lista->rozmiar(); a++) {
    T checker = get(a);
    if (element==checker){
      position=a+1;
     }
  }
  if (position>0) {
       return position;
  } else return 0;
}



#endif
