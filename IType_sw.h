#include "AllTypes.h"

class IType_sw : public AllTypes
{
public:
	void run(int op, int inst, Datapath *comp);

private:
	int rs, rt, immediate;
	int ALUOp;
};