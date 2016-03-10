#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
using namespace std;

class Control
{
public:
	//Control(int, int);
	Control();
	//in
	int opCode;
	int function;	//only applicable to R-type
	//out
	bool RegDst;
	bool Branch;
	bool MemRead;
	bool MemtoReg;
	int ALUOp;
	bool MemWrite;
	bool ALUSrc;
	bool RegWrite;

	void setOpCode(int, int);

private:
	void clearControlSignals();
	void setControlSignals(int, int);	//sets all out signals according to opcode
};

#endif