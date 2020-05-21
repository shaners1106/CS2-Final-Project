#include <iostream>
#include <ctime>
using namespace std;
#ifndef cellClass_h
#define cellClass_h
class Property
{
private:
	string description;
	int value;
	bool available = true;
	int owner = -1;
public:

	// Constructor
	Property() { owner = -1; available = true; }
	Property(int in_value, std::string descr, bool av = true);

	// Accessors
	int buyProperty() { return value; }
	string getDescription() { return description; }
	bool getAvailable() { return available; }
	int getValue() { return value; }
	int getOwner() { return owner; }

	// Mutators
	void setAvailable(bool in) { available = in; }
	void setOwner(int in) { owner = in; }
	// void tradeProperty();

	virtual int rentProperty() = 0;


};
#endif


#ifndef HOUSE_H_
#define HOUSE_H_

class House: public Property
{
private: 
	int house = 0;

public:

	// Constructor
	House() : Property() {}
	House(int in_value, std::string descr, bool av = true) : Property(in_value, descr, av) {}

	// Rent property
	// Calculates and returns the value owned for the rent
	int rentProperty() { return getValue() / 10 + getValue()*house / 10; }

};
#endif

#ifndef RAILROAD_H_
#define RAILROAD_H_
class Railroad : public Property
{
private:
	int numRail;

public:

	// Constructor
	Railroad() : Property() {}
	Railroad(int in_value, std::string descr, bool av = true) : Property(in_value, descr, av) {}

	// Rent property
	// Calculates and returns the value owned for the rent
	int rentProperty() { return (getValue() / 10) * 4; }

};
#endif


#ifndef UTILITIES_H_
#define UTILITIES_H_
class Utilities : public Property
{
private:
	int numUtilities = 4;

public:

	// Constructor
	Utilities() : Property() {}
	Utilities(int in_value, std::string descr, bool av = true) : Property(in_value, descr, av) {}

	// Rent property
	// Calculates and returns the value owned for the rent
	int rentProperty() { return 4 * numUtilities * 150 * (rand() % 6); }
};
#endif

#ifndef EMPTY_H_
#define EMPTY_H_

class Empty : public Property
{
public:

	// Constructor
	Empty() : Property() {}
	Empty(int in_value, std::string descr, bool av = true) : Property(in_value, descr, av) {}

	// Rent property
	// Calculates and returns the value owned for the rent
	int rentProperty() { return 0; }

};
#endif