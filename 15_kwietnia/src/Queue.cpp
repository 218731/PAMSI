#include <iostream>
#include "Queue.h"

using namespace std;
	
void Queue::push(int element)
{
	int ostatni = size();
	List::add(element, ostatni+1);
}

Node Queue::pop()
{
	return List::remove(1);
}

int Queue::size()
{
	return List::size();
}


/*
int main()
{
	Queue kolejka;
	int liczba;
	for(int i=0; i<5; i++)
	{
		cin>>liczba;
		kolejka.push(liczba);
	}
	
	for(int i=0; i<5; i++)
		cout<<kolejka.pop().element<<endl;
}

*/