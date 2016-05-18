#ifndef NODE_HH
#define NODE_HH
#include <iostream>

class Node
{
	Node *lewy, *prawy, *ojciec;
	int wartosc;
	bool kolor;			// 1 - czerwony, 0 - czarny
	
	Node()
	{
		ojciec = NULL;
		lewy = NULL;
		prawy = NULL;
		kolor = 0;
	}

	friend class Drzewo;
};

#endif