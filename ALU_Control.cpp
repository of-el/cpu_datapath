#include "ALU_Control.h"

#include <iostream>

ALU_Control::ALU_Control()
{
	opCode = 0;
	outputOperation = AND;	//default
}

void ALU_Control::setALUOp(int op)
{
	switch (op)
	{
	case 0:	//000
		outputOperation = ADD;
		break;
	case 2:	//010
		outputOperation = SUB;
		break;
	case 4:
		outputOperation = AND;
		break;
	case 5:
		outputOperation = OR;
		break;
	case 7:
		outputOperation = NOR;
		break;
	default:
		break;
	}
}

ALU_Control::OPERATION ALU_Control::getOperationType()
{
	return outputOperation;
}