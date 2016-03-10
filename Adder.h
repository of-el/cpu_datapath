#ifndef _Adder_h
#define _Adder_h

class Adder
{
public:
	Adder();
	void Add();
	void setA(int);
	void setB(int);
	int getResult();

private:
	int a, b, result;
};


#endif