#include "InstructionMemory.h"
#include <iostream>
using namespace std;

InstructionMemory::InstructionMemory()
{
	opcode = rs = rt = rd = shamt = funct = immediate = address = 0;

	instruction_array[0] = 0x02324020;	// 00000010001100100100000000100000 Rtype add $t0, $s1, $s2		//add 8, 17, 18*
	instruction_array[1] = 0x02744822;	// 00000010011101000100100000100010 Rtype sub $t1, $s3, $s4		//sub 9, 19, 20
	instruction_array[2] = 0x11090003;	// 00010001000010010000000000000011 Itype beq $t0, $t1, 3		//beq 8, 9, 3*
	instruction_array[3] = 0x11080003;	// 00010001000010000000000000000011 Itype beq $t0, $t1, 3		//beq 8, 8, 3*
	instruction_array[4] = 0x01095024;	// 00000001000010010101000000100100 Rtype and $t2, $t0, $t1
	instruction_array[5] = 0xAE6A0003;	// 10101110011010100000000000000011 Itype sw $t2, 3[$s3]		//sw 10, 3[19]*
	instruction_array[6] = 0x8E490002;	// 10001110010010010000000000000010 Itype lw $t1, 2[$s2]		//lw 9, 2[18]*
	instruction_array[7] = 0x08000002;	// 00001000000000000000000000000010 Jtype j to index 2			// j to instruction 2*
	instruction_array[8] = 0x01335825;	// 00000001001100110101100000100101 Rtype or $t3, $t1, $s3
	instruction_array[9] = 0x0272602A;	// 00000010011100100110000000101010 Rtype slt $t4, $s3, $s2
	instruction_array[10] = 0x20620003;	// 0010 0000 0110 0010 0000 0000 0000 0011	Itype addi 2, 3, 3
	/*instruction_array[9] = ;
	instruction_array[10] = ;
	instruction_array[11] = ;
	instruction_array[12] = ;
	instruction_array[13] = ;
	instruction_array[14] = ;
	instruction_array[15] = ;
	instruction_array[16] = ;*/
}


void
InstructionMemory::FetchInstruction(int pc)
{
	//is_rtype_ = is_itype_ = is_jtype_ = false;
	unsigned int instruction = instruction_array[pc];

	//find opcode
	opcode = (instruction & 0xFC000000);	//0b11111100000000000000000000000000
	opcode >>= 26;

	//breaks instruction for R-type
	rs = (instruction & 0x03E00000);
	rs >>= 21;
	rt = (instruction & 0x1F0000);
	rt >>= 16;
	rd = (instruction & 0xF800);
	rd >>= 11;
	shamt = (instruction & 0x7C0);
	shamt >>= 6;
	funct = (instruction & 0x3F);

	//for I-type
	immediate = (instruction & 0x0000FFFF);

	//for J-type
	address = (instruction & 0x3FFFFFF);

}