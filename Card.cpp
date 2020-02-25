#include "Card.h"

// Constructor
// Takes in and sets the description and the money value
Card::Card(std::string in_description, int in_value, int in_loc)
{
	description = in_description;
	value$$$ = in_value;
	location = in_loc;
}

// Read Card
// Void- no input
// Couts the description
void Card::readCard()
{
	cout << description << endl;
}
