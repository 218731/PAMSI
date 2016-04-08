#include <iostream>
#include <cstdio>
#include "List.h"

using namespace std;

	
	List::List() { poczatek=nullptr; koniec=nullptr; rozmiar=0; }
	
/* Metoda dodajaca liczbe 'elem' do listy na pozycji 'position'
 * Dla przyspieszenia calego procesu zostaly wydzielone dwa szczegolne przypadki:
 * - dodawanie na poczatku listy,
 * - dodawanie na koncu listy.
 *
 * Jezeli funkcji nie uda sie dodac elementu zwroci ona wartosc -1. W przeciwnym razie
 * zakonczy sie zwroceniem wartosci 0.
 */
	int List::add(int elem, int position)
	{
		Node *temp = new Node();						//inicjacja elementu do dodania
		temp->element = elem;
		
		if(position == 1)										//dodanie na poczatku listy
		{
			temp->nastepny = poczatek;
			poczatek = temp;
			if(rozmiar == 0) { rozmiar++; koniec = temp; }
			return 0;
		}
		else
		{
			if(position == rozmiar+1) 				//dodawnie na koncu listy
			{
				koniec->nastepny = temp;
				koniec = temp;
				rozmiar++;
				return 0;
			}
			else
			{
				if(position<=rozmiar)						//dodanie w srodku listy
				{
					temp = poczatek;
					Node *index = new Node();
					for(int i=0; i<position; i++)
						index = index->nastepny;
					temp->nastepny = index->nastepny;
					index->nastepny = temp;
					rozmiar++;
					return 0;
				}
				else return -1;
			}
				
		}
	}
	/* Funkcja do usuwania elementow z listy z miejsca 'position'
	 * Funkcja zwraca element listy po jego usunieciu lub w razie niepowodzenia 
	 * komunikat o bledzie i zerowy element.
	 */
	Node List::remove(int position)
	{
		Node *zwrot = new Node ();
		zwrot->nastepny = nullptr;
		if(position<=rozmiar+1)
		{
			Node *temp = poczatek;
			for (int i=1; i<position-1; i++)
				temp = temp->nastepny;
			zwrot = temp;
			temp->nastepny = (temp->nastepny)->nastepny;
			rozmiar--;
		}
		else 
		{
			cout<<"Nie ma takiego elementu! Pozycja > rozmiru listy."<<endl;
			return *zwrot;
		}
	}
	/*Funkcja zwracajaca element listy na danej pozycji listy.
		W razie niepowodzenia wyswietli sie komunikat o bledzie i zwrocony zostanie
		element zerowy.
	 */
	Node List::get(int position)
	{
		Node *temp = nullptr;
		if(position <= rozmiar)
		{
			temp = poczatek;
			for (int i=1; i<position; i++)
				temp = temp->nastepny;
		}
		else 
		{
			cout<<"Nie ma takiego elementu! Pozycja > rozmiru listy."<<endl;
			return *temp;
		}
	}
	/* Funkcja wypisujaca wszystkie elementy listy */
	void List::wypisz()
	{
		Node *temp = poczatek;
		for (int i=1; i<=rozmiar; i++)
		{
			cout<<i<<": "<<temp->element<<endl;
			temp = temp->nastepny;
		}
	}
	
//Funkcja zwracajaca rozmiar listy
	int List::size() { return rozmiar; }


/*Funkcja wyszukujaca liczbe 'szukana' na liscie. W przypadku powodzenia liczba ta jest zwracana.
W przeciwnym wypadku wyswietlany jest komunikat o bledzie i zwracana jest wartosc -1.
*/
	int List::wyszukaj(int szukana)
	{
 		Node *temp = poczatek;
 		for (int i=1; i<=rozmiar; i++)
 		{
 			if(temp->element == szukana) return temp->element;
 			temp = temp->nastepny;
 		}
 		cout<<"Nie znaleziono zadanej liczby!"<<endl;
 		return -1;
 	}
		






