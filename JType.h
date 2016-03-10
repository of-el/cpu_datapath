#include "AllTypes.h"

class JType : public AllTypes
{
public:
	void run(int op, int inst, Datapath *comp);
private:
	int address;
	int ALUOp;
};