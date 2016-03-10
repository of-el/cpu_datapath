#ifndef Datapath_H
#define Datapath_H

#include "Adder.h"
#include "ALU.h"
#include "ALU_Control.h"
#include "Control.h"
#include "DataMemory.h"
#include "InstructionMemory.h"
#include "Mux.h"
#include "Registers.h"

class Datapath
{
public:
	Datapath();
	int PC;
	InstructionMemory instr_mem;
	Adder PC_adder, branch_adder;
	Control control;
	//Mux inst_mux, alu_mux, data_mux, branch_mux;
	Registers registers;
	ALU_Control alu_control;
	ALU alu;
	DataMemory data_mem;
	void printAll();
	void incrementPC();
	void setPC(int);


//public:
//	Datapath();
//	void Run();
//	void printAll();
};

#endif Datapath_H