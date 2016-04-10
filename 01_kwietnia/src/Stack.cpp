#include <iostream>
#include "Stack.h"

using namespace std;

int Stack::push(int elem)
{
		return List::add(elem,1);
}

int Stack::pop()
{
		if(List::size()==0) cout<<"Pusty stos!"<<endl;
		else return List::remove(1).element;
	  throw "Nie da rady\n";
}

int Stack::size()
{
		return List::size();	 
}	





