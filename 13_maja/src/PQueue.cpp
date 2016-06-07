#include <iostream>
#include "PQueue.h"

using namespace std;

PQueue::PQueue()
{
	rozmiar = 0;
	poczatek = NULL;
}

void PQueue::push(int elem, int prio)
{
	PQNode *temp = new PQNode;
	temp->element = elem;
	temp->priority = prio;
	temp->nastepny = NULL;
	if(rozmiar == 0)
	{
		poczatek = temp;
	}
	else
	{
		if(rozmiar == 1)
		{
			if(poczatek->priority < temp->priority)
			{
				poczatek->nastepny = temp;
			}
			else
			{
				temp->nastepny = poczatek;
				poczatek = temp;
			}
		}
		else
		{
			PQNode *index = poczatek, *poprzedni = NULL;
			for(int i=1; i<=rozmiar; i++)	
			{
				if(index != NULL)		//jak nieprawda to wstawia na koniec
				{
					if(index->priority < temp->priority)		//szuka miejsca dalej
					{
						poprzedni = index;
						index = index->nastepny;
					}
					else		//wstawia na poczatek
					{
						if(poprzedni == NULL)
						{
							temp->nastepny = poczatek;
							poczatek = temp;
							break;
						}
						else		//wtawia w srodku
						{
							temp->nastepny = index;
							poprzedni->nastepny = temp;
						}
					}
				}
				else
				{
					poprzedni->nastepny = temp;
				}
			}
		}
	}
	rozmiar++;
}

void PQueue::wypisz()
{
	PQNode *temp = poczatek;
	for(int i=1; i<=rozmiar; i++)
	{
		cout<<i<<". "<<temp->element<<endl;
		temp = temp->nastepny;
	}
}

PQNode PQueue::pop()
{
	PQNode *zwrot = poczatek;
	if(rozmiar > 0)
	{
		poczatek = poczatek->nastepny;
		rozmiar--;
		return *zwrot;
	}
	else throw "NOPE!";
}

int PQueue::size()
{
	return rozmiar;
}