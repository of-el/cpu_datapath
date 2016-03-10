#include "ALU.h"

ALU::ALU()
{
	a = b = result = 0;
	Zero = false;
	operation = ALU_Control::OPERATION::AND;	//default
}

void ALU::setA(int A)
{
	a = A;
}

void ALU::setB(int B)
{
	b = B;
}

void ALU::setOperation(ALU_Control::OPERATION op)
{
	operation = op;
}

void ALU::calculate()
{
	Zero = false;

	switch (operation)
	{
	case ALU_Control::OPERATION::AND:
		result = a & b;
		break;
	case ALU_Control::OPERATION::OR:
		result = a | b;
		break;
	case ALU_Control::OPERATION::XOR:
		result = a ^ b;
		break;
	case ALU_Control::OPERATION::NOR:
		result = ~(a | b);
		break;
	case ALU_Control::OPERATION::ADD:
		result = a + b;
		break;
	case ALU_Control::OPERATION::SUB:
		result = a - b;
		if (result == 0)
			Zero = true;
		break;
	default:
		result = -1;
		break;
	}
}

int ALU::getResult()
{
	return result;
}
