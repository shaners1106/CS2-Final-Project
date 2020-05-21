#ifndef Board_h
#define Board_h

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Cells.h"
#include "cellClass.h"
#include "Card.h"
#include "Player.h"
#include <algorithm>

using namespace std;

class Board
{
private:
	
	vector <Property*> locations;
	vector<Card> cardPile;
	vector<Cells> cellArray;
	vector<player> roster;

public:

	Board();

	// Add player
	// Input: char token
	// Makes a new player, with the token of their choosing
	// Output: none - void
	void addPlayer(char token);

	// Accesors
	int getNumPlayers() { return roster.size(); }
	std::string getName(int i) { return cellArray.at(i).getDesc(); }
	char getToken(int player) { return roster.at(player).getToken(); }
	int getPlayerPosition(int player) { return roster.at(player).getPosition(); }
	bool owned(int loc) { return locations.at(loc)->getAvailable(); }
	int getCellPlayer(int loc) { return locations.at(loc)->getOwner(); }
	int getRent(int loc) { return locations.at(loc)->rentProperty(); }
	string stringProperties(int player);

	//Muators
	void setPositionPlayer(int player, int _change) { roster.at(player).setPosition(_change); }


	// Pay player
	// Input: int from player, int to player, int amount of transaction
	// Allows one player to pay another one
	// Returns a bool if the transaction was succesful
	bool payPlayer(int from, int to, int amount);

	// Add cell
	// In takes a cell class
	// Pushes a cell object into the board cell vector
	//  Void - output none
	void addCell(Cells input);

	// Load cards
	// Input - none
	// Loads the cards and shuffles them
	//  Void - output none
	void loadCards();

	// Buy property
	// Input: int player buying, int location of the palyer
	// Allows the player to but the property at his location
	// Void - output none
	void buyProperty(int player, int location); // To do

	// Draw card
	// Input: in player
	// The players picks a card and takes effect
	// Void - output none
	void drawCard(int player);

	// Get money
	// Input: int player
	// Returns the money of the player
	// Output: returns the money of the player
	int getMoney(int player);

	// Properties owned
	// Input: player
	// Displays the properties owned by the player
	// Void - output none
	void propertiesOwned(int player);

	// Roll dice player
	// Input: player
	// Rolls the dice for the player and moves
	// Void - output none
	void rollDicePlayer(int player);

	// Load cells
	// Input: player
	// Pushes the predetermined cells of the board into the cells vector
	// Void - output none
	void loadCells();

	// Load properties
	// Input: none
	// Pushes the predetermine clases of properties into the locations vector
	// Void - output none
	void loadProperties();

	// Check rent
	// Input: player
	// Checks if the current cell is owned and procedes to charge the player
	// Void - output none
	void checkRent(int player);

	/* for Beta release, coming soon ...
	void trade();
	*/

	// Display
	// Input: player
	// Displays the stats of the player
	// Void - output none
	void display( int player);

	
};

#endif

