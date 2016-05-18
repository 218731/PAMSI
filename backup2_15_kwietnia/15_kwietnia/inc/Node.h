#ifndef NODE_H
#define NODE_H

#include <string>

struct Node
{
	Node *nastepny;
	int numer;
	std::string nazwisko;
};

#endif