#ifndef NODE_HH
#define NODE_HH
#include <iostream>

class Node
{
	Node *lewy, *prawy;
	int wartosc;
	
	Node()
	{
		lewy = NULL;
		prawy = NULL;
	}

	friend class Drzewo;
};

#endif