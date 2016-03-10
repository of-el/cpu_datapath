#include "Control.h"

//set all initial values to 0
Control::Control()
{
	opCode = 0;
	clearControlSignals();
}


//sets opCode and turns on corresponding signals
void Control::setOpCode(int instruction, int func)
{
	opCode = instruction;
	function = func;
	clearControlSignals();
	setControlSignals(opCode, function);
}

//clears all controlSignals
void Control::clearControlSignals()
{
	RegDst = Branch = MemRead = MemtoReg = ALUOp = MemWrite = ALUSrc = RegWrite = false;
}


//turns on signals based on type and opcode
void Control::setControlSignals(int opCode, int function)
{
	int type = opCode >> 3;

	//R-format AND, OR, XOR, Add, Sub 
	if (opCode == 0)
	{
		RegDst = true;
		RegWrite = true;
		ALUOp = (function & 0x00000007);	//right most 3 bits

	}
	//I-format BEQ
	else if (opCode == 4)		//000100
	{
		Branch = true;
		ALUOp = 2;		//010 for subtraction
	}
	//I-format ANDi, ORi, XORi, Addi, Subi
	else if (type == 1)		//001
	{
		RegWrite = true;
		ALUSrc = true;		//chooses value b
		ALUOp = (opCode & 0x00000007);	//right most 3 bits
	}
	//I-format lw
	else if (type == 4)		//100
	{
		ALUSrc = true;
		MemtoReg = true;
		RegWrite = true;
		MemRead = true;
		ALUOp = 0;		//000 for addition
	}
	//I-format sw
	else if (type == 5)		//101
	{
		ALUSrc = true;
		MemWrite = true;
		ALUOp = 0;		//000 for addition
	}
	//J-format - JUMP
	else if (type == 0)	//000
	{
		Branch = true;
	}
	else
	{
		cout << "Wrong opcode." << endl;
	}
}