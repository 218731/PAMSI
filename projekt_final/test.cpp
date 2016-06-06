#include <iostream>
#include "queue.hh"

using namespace std;

int main()
{
	cout<<"Test kolejki:"<<endl;
	Queue <int> kolejka;
	for(int i=1; i<6; i++)
	{
		cout<<"i = "<<i<<endl;
		kolejka.enqueue(i);
	}
	
	for(int i=1; i<=kolejka.size(); i++)
	{
		cout<<i<<" element - "<<kolejka.get(i)<<endl;
	}
}