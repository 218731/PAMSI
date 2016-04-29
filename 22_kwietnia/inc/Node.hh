#ifndef NODE_HH
#define NODE_HH
#include <iostream>

class Node
{
	Node *lewy, *prawy, *ojciec;
	int wartosc;
	
	Node()
	{
		ojciec = NULL;
		lewy = NULL;
		prawy = NULL;
	}

	friend class Drzewo;
};

#endif