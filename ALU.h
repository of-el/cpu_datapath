#include "ALU_Control.h"

#ifndef ALU_H
#define ALU_H

class ALU
{
public:
	ALU();
	void setA(int);
	void setB(int);
	void setOperation(ALU_Control::OPERATION);
	void calculate();
	int getResult();

private:
	int a, b, result;
	bool Zero;
	ALU_Control::OPERATION operation;
};

#endif