#pragma once

class InstructionMemory
{
public:
	// Instruction variables
	unsigned int opcode, rs, rt, rd, shamt, funct;	// R-type variables
	int immediate;	// opcode, rs, rt, and immediate belong to I-type format
	int address;	// Target address for J-type instruction
	unsigned int instruction_array[17];
	// Constructor & destructor
	InstructionMemory();
	// Function
	void FetchInstruction(int);

private:
	// For simplicity we will deal with basic
	// instruction formats: R-type, I-type, J-type.

	//bool is_rtype_, is_itype_, is_jtype_ = false;
};