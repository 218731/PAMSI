#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

class Queue : private List
{
public:
	
	void push(int element);
	Node pop();
	int size();
};

#endif