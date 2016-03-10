#include "AllTypes.h"

class RType : public AllTypes
{
public:
	void run(int op, int inst, Datapath *comp);
private:
	int rs, rt, rd;
	int funct, shamt;
	int ALUOp;
};