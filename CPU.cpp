#include "CPU.h"

void CPU::run()
{
	int type;
	//DELETE THIS
	//components.setPC(10);

	while (components.PC >= 0 && components.PC < 11){

		cout << "PC: " << components.PC << endl;
		cout << "  BEGINNING OF CYCLE:" << endl;
		printAll();

		instruction = components.instr_mem.instruction_array[components.PC];

		//find opcode
		opcode = (instruction & 0xFC000000);	//0b11111100000000000000000000000000
		opcode >>= 26;

		type = opcode >> 3;

		//R-format
		if (opcode == 0)
		{
			context.setType(R);
		}
		//I-format BEQ
		//else if (opcode == 4)
		//	;
		//I-format ANDi, ORi, XORi, Addi, Subi
		else if (type == 1)
			context.setType(I);
		//I-format lw
		else if (type == 4)		//100
			context.setType(I_lw);
		//I-format sw
		else if (type == 5)		//101
			context.setType(I_sw);
		//I-format JUMP
		else if (type == 0)
			context.setType(J);

		context.run(opcode, instruction, &components);

		cout << "\n  END OF CYCLE:" << endl;
		printAll();
		cout << endl;

		system("pause");
	}

}

void CPU::printAll()
{
	cout << "\tREGISTERS"
		<< "\t\t\t" << "MEMORY" << endl;

	for (int i = 0; i < 16; i++)
	{
		components.registers.printThisRegister(i);
		cout << "\t\t";
		components.registers.printThisRegister(i + 16);
		cout << "\t\t";
		components.data_mem.printThisMemory(i);
		cout << "\t\t";
		components.data_mem.printThisMemory(i + 16);
		cout << endl;
	}
}