#ifndef ISTACK_HH
#define ISTACK_HH

class IStack
{
public:
	virtual int push(Element elem) = 0;
	virtual Element pop() = 0;
	virtual int size() = 0;
};

#endif