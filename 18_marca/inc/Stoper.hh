#ifndef STOPER_HH
#define STOPER_HH
#include "IStoper.hh"
#include <ctime>

class Stoper:public IStoper
{
private:
	time_t t_start, t_stop;

public:
	void start(){	t_start = clock();	}
	void stop(){	t_stop = clock();	}
	double getTime(){	return (t_stop-t_start)/(double)CLOCKS_PER_SEC;	}
};

#endif