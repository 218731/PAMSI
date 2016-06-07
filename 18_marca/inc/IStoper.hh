#ifndef ISTOPER_HH
#define ISTOPER_HH

class IStoper
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual double getTime() = 0;
};

#endif