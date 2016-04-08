#include <iostream>
#include "List.h"

using namespace std;

class Stack: private List
{
public:
	int push(int elem);

	int pop();

	int size();
};

int Stack::push(int elem)
{
		return List::add(elem,0);
}

int Stack::pop()
{
		if(List::size()==0) cout<<"Pusty stos!"<<endl;
		else return List::remove(0).element;
}

int Stack::size()
{
		return List::size();	 
}	


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




