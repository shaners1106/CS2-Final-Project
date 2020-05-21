#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <string>
#include "cellClass.h"
#include <ctime>
#include <cstdlib>

class player
{
private:

	unsigned char token;
	int money;
	int position;
	vector<Property*> propertiesOwned;
	bool play;
	bool jailCard;

public:

	// Constructor
	player(char in_token);

	// Accesor
	int getPosition() { return position; }
	int getMoney() { return money; }
	char getToken() { return token; }
	std::string getPropertyName(int index) { return propertiesOwned.at(index)->getDescription(); }
	int getPropertySize() { return propertiesOwned.size(); }

	// Add money
	// Input - adds an int to the money pool of the player
	// Void: no output
	void addMoney(int in_money) { money += in_money; }

	// Pay money
	// Input - substract an int to the money pool of the player
	// Void: no output
	void payMoney(int money) { this->money -= money; }

	// Check jail card
	// Input: none
	// Checks if the player has an available jail card
	// Output: none - void
	void checkJailCard();

	// Pick jail card
	// Input: none
	// If the player draws a jail cards sets jailcard to true
	// Output: none - void
	void pickJailCard();

	// Roll dice
	// Input: none
	// Generates a number between 1-6
	// Output: returns the number as an int
	int rollDice();

	// Pass go
	// Input: none
	// Pays the player 200 for go
	// Output: none - void
	void passGo();

	// Add property
	// Input: property class
	// Adds a property to the players property vector
	void addProperty(Property* buy);

	// Purchase
	// Input: property class
	// Makes the player pay to the bank for the property
	// Output: none - void
	void purchase(Property* in_property);

	// To be used later void purchase();
	// int payPlayer;

	// Change position
	// Input: takes an int
	// Updates the player location
	// Output: none - void
	void changePosition(int change) { position += change; }
	void setPosition(int position) { this->position = position; }
};

#endif
