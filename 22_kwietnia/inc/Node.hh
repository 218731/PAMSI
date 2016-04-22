#ifndef NODE_HH
#define NODE_HH

struct Node
{
	Node *lewy, *prawy;
	int wartosc;
	
	Node();
};

Node::Node()
{
	lewy = NULL;
	prawy = NULL;
}

#endif