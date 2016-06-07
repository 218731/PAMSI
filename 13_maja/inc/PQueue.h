#ifndef PQUEUE_H
#define PQUEUE_H

struct PQNode
{
	int element, priority;
	PQNode *nastepny;
};

class PQueue
{
private:
	int rozmiar;
	PQNode *poczatek;
public:
	PQueue();
	void push(int element, int priority);
	PQNode pop();
	int size();
	void wypisz();
};

#endif