#include <iostream>
#include <cstdio>
#include "List.h"

using namespace std;

	
	List::List() { poczatek=nullptr; koniec=nullptr; rozmiar=0; }
	
	int List::add(int elem, int position)
	{
		Node *temp = new Node();
		temp->element = elem;
		
		if(position == 1)
		{
			temp->nastepny = poczatek;
			poczatek = temp;
			if(rozmiar == 0) { rozmiar++; koniec = temp; }
			return 0;
		}
		else
		{
			if(position == rozmiar+1)
			{
				koniec->nastepny = temp;
				koniec = temp;
				rozmiar++;
				return 0;
			}
			else
			{
				if(position<=rozmiar)
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
		return *zwrot;
	}
	
	Node List::get(int position)
	{
		Node *temp = nullptr;
		if(position <= rozmiar)
		{
			temp = poczatek;
			for (int i=1; i<position; i++)
				temp = temp->nastepny;
		}
		return *temp;
	}
	
	void List::wypisz()
	{
		Node *temp = poczatek;
		for (int i=1; i<=rozmiar; i++)
		{
			cout<<i<<": "<<temp->element<<endl;
			temp = temp->nastepny;
		}
	}
	
	int List::size() { return rozmiar; }

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
		






