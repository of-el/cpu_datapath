#include "IType_lw.h"

void IType_lw::run(int op, int inst, Datapath *comp)
{
	rs = (inst & 0x03E00000);
	rs >>= 21;
	rt = (inst & 0x1F0000);
	rt >>= 16;
	immediate = (inst & 0x0000FFFF);
	ALUOp = 0;	//for addition

	comp->data_mem.setMemRead(true);
	comp->registers.setRegWrite(true);
	comp->registers.setWriteRegister(rt);
	comp->registers.setReadRegisters(rs, rt);

	comp->alu_control.setALUOp(ALUOp);
	comp->alu.setOperation(comp->alu_control.getOperationType());

	comp->alu.setA(comp->registers.getRsData());
	comp->alu.setB(immediate);
	comp->alu.calculate();

	comp->data_mem.setAddress(comp->alu.getResult());
	comp->data_mem.setWriteData(comp->registers.getRsData());
	comp->data_mem.readMemory();

	comp->registers.setWriteData(comp->data_mem.getReadData());
	comp->registers.writeDataIntoReg();

	comp->incrementPC();

}
