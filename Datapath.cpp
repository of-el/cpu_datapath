#include "Datapath.h"

Datapath::Datapath()
{
	//PC = 0;
	PC_adder.setB(1);	//1 to increment to next instruction
}

void Datapath::incrementPC()
{
	++PC;
}

void Datapath::setPC(int i)
{
	PC = i;
}

void Datapath::printAll()
{
	cout << "REGISTERS"
		<< "\t" << "MEMORY" << endl;

	for (int i = 0; i < 32; i++)
	{
		registers.printThisRegister(i);
		cout << "\t\t";
		data_mem.printThisMemory(i);
		cout << endl;
	}
}