#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
	Node *nastepny;
	int element;	
};

class IList
{
public:
	virtual int add(int elem, int position) = 0;
	virtual Node remove(int position) = 0;
	virtual Node get(int position) = 0;
	virtual int size() = 0;
};

class List : public IList
	{
	private:
		int rozmiar;
		Node *poczatek, *koniec;
	public:
	
	List();
	
	int add(int elem, int position);
	
	Node remove(int position);
	
	Node get(int position);
	
	void wypisz();
	
	int size();
};
	
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
};

using namespace std;

class Stack: private List
{
public:
	int push(int elem)
	{
			return IList::add(elem,0);
	}

	int pop()
	{
			if(IList::size()==0) cout<<"Pusty stos!"<<endl;
			else return IList::remove(0).element;
	}

	int size()
	{
			return IList::size();	 
	}	
};

int main()
{

	Stack stos;
	int a;
	for(int i=0; i<5; i++)
	{
		cin>>a;
		stos.push(a);
	}
	for(int i=5; i>0; i--)
		cout<<stos.pop()<<endl;
	
}












