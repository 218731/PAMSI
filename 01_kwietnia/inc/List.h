#include "IList.h"

class List : public IList
	{
	private:
		int rozmiar;
		Node *poczatek, *koniec;
		friend class Stack;
	public:
	
	List();
	
	int add(int elem, int position);
	
	Node remove(int position);
	
	Node get(int position);
	
	void wypisz();
	
	int size();
	
	int wyszukaj(int szukana);
};
