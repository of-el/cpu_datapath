#include "Adder.h"

Adder::Adder()
{
	a = 0;
	b = 0;
	result = 0;
}

void Adder::Add()
{
	result = a + b;
}

void Adder::setA(int A)
{
	a = A;
}

void Adder::setB(int B)
{
	b = B;
}

int Adder::getResult()
{
	return result;
}