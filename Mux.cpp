#include "Mux.h"

Mux::Mux()
{
	a = b = result = 0;
	chooseB = false;
}


void Mux::setChoiceB(bool isB)
{
	chooseB = isB;
}

void Mux::setA(int A)
{
	a = A;
}

void Mux::setB(int B)
{
	b = B;
}


int Mux::getResult()
{
	if (chooseB)
		result = b;
	else
		result = a;

	return result;
}