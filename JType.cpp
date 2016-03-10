#include "JType.h"

void JType::run(int op, int inst, Datapath *comp)
{
	address = (inst & 0x3FFFFFF);

	// Update PC to address field
	comp->setPC(address);
}
