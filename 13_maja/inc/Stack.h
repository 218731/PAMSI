#include "List.h"

class Stack: private List
{
public:
	int push(int elem);

	int pop();

	int size();
};