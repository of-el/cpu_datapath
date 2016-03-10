#include "DataMemory.h"

using namespace std;

DataMemory::DataMemory()
{
	MemRead = false;
	MemWrite = false;
	address = 0;
	readData = 0;
	writeData = 0;

	//filling the mem array with nums.
	for (int i = 0; i < 32; i++)
	{
		memory[i] = i;
	}

}

void DataMemory::setMemRead(bool isRead)
{
	MemRead = isRead;
}

void DataMemory::setMemWrite(bool isWrite)
{
	MemWrite = isWrite;
}

void DataMemory::setAddress(int adr)
{
	address = adr;
}

void DataMemory::setWriteData(int data)
{
	writeData = data;
}

int DataMemory::getReadData()
{
	return readData;
}

//reads memory if instructed to read
void DataMemory::readMemory()
{
	if (MemRead)
	{
		readData = memory[address];
	}
}

//writes value into memory if instructed to
void DataMemory::writeToMemory()
{
	if (MemWrite)
	{
		memory[address] = writeData;
	}
}

void DataMemory::printAllInMemory()
{
	for (int i = 0; i < 32; i++)
	{
		cout << i << ": " << memory[i] << endl;
	}
}

void DataMemory::printThisMemory(int i)
{
	if (i >= 0 && i < 32)
	{
		cout << i << ": " << memory[i];
	}
	else
	{
		cout << "Invalid memory address." << endl;
	}
}