#include "IType.h"

void IType::run(int op, int inst, Datapath *comp)
{
	rs = (inst & 0x03E00000);
	rs >>= 21;
	rt = (inst & 0x1F0000);
	rt >>= 16;
	immediate = (inst & 0x0000FFFF);
	ALUOp = (op & 0x00000007);	//right most 3 bits

	comp->registers.setRegWrite(true);
	comp->registers.setWriteRegister(rt);
	comp->registers.setReadRegisters(rs, rt);

	comp->alu_control.setALUOp(ALUOp);
	comp->alu.setOperation(comp->alu_control.getOperationType());

	comp->alu.setA(comp->registers.getRsData());
	comp->alu.setB(immediate);
	comp->alu.calculate();
	comp->registers.setWriteData(comp->alu.getResult());

	comp->registers.writeDataIntoReg();

	comp->incrementPC();
}
