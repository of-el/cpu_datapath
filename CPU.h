#include "Datapath.h"
#include "Context.h"
#include "RType.h"
#include "IType.h"
#include "IType_lw.h"
#include "IType_sw.h"
#include "JType.h"

#ifndef CPU_H
#define CPU_H

class CPU
{
public:
	void run();
private:
	unsigned int instruction;
	unsigned int opcode;
	Datapath components;
	Context context;
	RType R;
	IType I;
	IType_lw I_lw;
	IType_sw I_sw;
	JType J;
	void printAll();
};

#endif