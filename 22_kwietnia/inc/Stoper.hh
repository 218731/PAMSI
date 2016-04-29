#ifndef STOPER_HH
#define STOPER_HH

#include "IStoper.hh"

class Stoper:public IStoper
{
public:
	time_t t_start, t_stop;
	
	virtual void start(){	t_start = clock();	}
	virtual void stop(){	t_stop = clock();	}
	virtual double getTime(){	return (t_stop-t_start)/(double)CLOCKS_PER_SEC;	}
};

#endif