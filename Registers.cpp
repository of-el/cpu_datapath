#include "Registers.h"

Registers::Registers()
{
	rs = rt = rd = 0;		//inputs
	rsData = rtData = writeData = 0;
	RegWrite = true;

	//fill registers up with some sample values
	for (int i = 0; i < 32; i++)
	{
		registerArray[i] = i;
	}
}

//sets read registers and grabs data from specified registers
void Registers::setReadRegisters(int s, int t)
{
	rs = s;
	rt = t;
	rsData = registerArray[rs];
	rtData = registerArray[rt];
}

void Registers::setWriteRegister(int d)
{
	rd = d;
}

void Registers::setRegWrite(bool recordData)
{
	RegWrite = recordData;
}

void Registers::setWriteData(int data)
{
	writeData = data;
}

int Registers::getRsData()
{
	return rsData;
}

int Registers::getRtData()
{
	return rtData;
}

void Registers::writeDataIntoReg()
{
	if (RegWrite)
		registerArray[rd] = writeData;
}

void Registers::printAllRegisters()
{
	for (int i = 0; i < 32; i++)
	{
		cout << i << ": " << registerArray[i] << endl;
	}
}

void Registers::printThisRegister(int i)
{
	if (i >= 0 && i < 32)
	{
		cout << i << ": " << registerArray[i];
	}
	else
	{
		cout << "Invalid register" << endl;
	}
}