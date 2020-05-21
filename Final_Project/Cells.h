#ifndef Cells_h
#define Cells_h

#include <iostream>
#include <vector>
#include <string>

class Cells
{
private:
	std::string descr;	// Name of the cell
	int cellNumber; // Ordered the cells with ascending numbers

public:

	// Constructor
	Cells(int in, std::string in_descr) { cellNumber = in; descr = in_descr; }
	// Mutator
	void setNumber(int num) { cellNumber = num; }
	// Accesor
	std::string getDesc() { return descr; }
};


#endif