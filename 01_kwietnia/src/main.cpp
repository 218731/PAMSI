#include <iostream>
#include "Stack.h"

using namespace std;


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