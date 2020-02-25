#ifndef Card_h
#define Card_h
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Card
{
private:
	std::string description;
	int value$$$;
	bool Jail;
	int location;

public :

	// Constructor
	Card(std::string in_description, int in_value, int in_loc);

	// Accesors
	int getValue() { return value$$$; }
	bool getJail() { return Jail; }
	int getLoc() { return location; }

	// Read Card
	// Void- no input
	// Couts the description
	void readCard();


};
#endif
