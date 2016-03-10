#ifndef ALLTYPES_H
#define ALLTYPES_H

#include "Datapath.h"

class AllTypes
{
public:
	virtual void run(int, int, Datapath*) = 0;
};

#endif