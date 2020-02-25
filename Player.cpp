#include "Player.h"

// Constructor
// Takes in a char
player::player(char in_token)
{
	token = in_token;
	money = 2000;
	position = 0;
	play = true;
	vector<Property*> propertiesOwned;
}

// Check jail card
// Input: none
// Checks if the player has an available jail card
// Output: none - void
void player::checkJailCard()
{
	if (jailCard)
		play = true;
}

// Pick jail card
// Input: none
// If the player draws a jail cards sets jailcard to true
// Output: none - void
void player::pickJailCard()
{
	jailCard = true;
}

// Roll dice
// Input: none
// Generates a number between 1-6
// Output: returns the number as an int
int player::rollDice()
{
	srand(time(NULL));
	if (play)
	{
		int x = (rand() % 6) + 1;
		if (getPosition() + x > 23)
		{
			passGo();
			setPosition(getPosition() - 24);
		}
		return x;
	}
	else
		cout << "You are in jail, pay your taxes." << endl;
		return 0;
	
}

// Pass go
// Input: none
// Pays the player 200 for go
// Output: none - void
void player::passGo()
{
	addMoney(200);
}

// Add property
// Input: property class
// Adds a property to the players property vector
void player::addProperty(Property* buy)
{

	propertiesOwned.push_back( buy );
}

// Purchase
// Input: property class
// Makes the player pay to the bank for the property
// Output: none - void
void player::purchase( Property* in_property)
{
	// checks to see if player has enough money
	if (getMoney() - in_property->buyProperty() > 0)
	{
		addProperty(in_property);
		payMoney(in_property->buyProperty());
	}
	else
		cout << "Error 404. Your money wasn't found. ";
}
