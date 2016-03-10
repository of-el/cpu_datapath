#ifndef CONTEXT_H
#define CONTEXT_H

#include "AllTypes.h"

class Context
{
public:
	void setType(AllTypes& fmt)
	{
		format = &fmt;
	}

	void run(int op, int inst, Datapath *comp)
	{
		format->run(op, inst, comp);
	}

private:
	AllTypes *format;
};

#endif