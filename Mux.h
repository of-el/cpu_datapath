#ifndef Mux_H
#define Mux_H

class Mux
{
private:
	int a, b, result;
	bool chooseB;
	 
public:
	Mux();
	void setChoiceB(bool);
	void setA(int);
	void setB(int);
	int getResult();
};

#endif Mux_H