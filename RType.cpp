#include "RType.h"

void RType::run(int op, int inst, Datapath *comp)
{
	rs = (inst & 0x03E00000);
	rs >>= 21;
	rt = (inst & 0x1F0000);
	rt >>= 16;
	rd = (inst & 0xF800);
	rd >>= 11;
	shamt = (inst & 0x7C0);
	shamt >>= 6;
	funct = (inst & 0x3F);
	ALUOp = (funct & 0x00000007);	//right most 3 bits

	comp->registers.setRegWrite(true);
	comp->registers.setWriteRegister(rd);
	comp->registers.setReadRegisters(rs, rt);

	comp->alu_control.setALUOp(ALUOp);
	comp->alu.setOperation(comp->alu_control.getOperationType());

	comp->alu.setA(comp->registers.getRsData());
	comp->alu.setB(comp->registers.getRtData());
	comp->alu.calculate();
	comp->registers.setWriteData(comp->alu.getResult());

	comp->registers.writeDataIntoReg();

	comp->incrementPC();
}