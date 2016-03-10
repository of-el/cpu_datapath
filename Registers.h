#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
using namespace std;

class Registers
{
public:
	Registers();
	void setReadRegisters(int s, int t);	//sets read registers and grabs their data
	void setWriteRegister(int d);
	void setRegWrite(bool);
	void setWriteData(int);
	int getRsData();
	int getRtData();
	void writeDataIntoReg();	//writes data into register specified by rd
	void printAllRegisters();
	void printThisRegister(int);

private:
	int registerArray[32];		//registers

	//from instruction
	int rs;		//read register 1
	int rt;		//read register 2
	int rsData;	//data in rs register
	int rtData;	//data in rt register
	int rd;		//write register
	int writeData;	//data to be written

	//set by Control
	bool RegWrite;
};





#endif