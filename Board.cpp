#include "Board.h"

Board::Board()
{
	loadCards();
	loadCells();
	loadProperties();
}

void Board::addPlayer(char token)
{
	player in_player(token);
	roster.push_back(in_player);
}

string Board::stringProperties(int player)
{
	string temp;
	for (int i = 0; i < roster.at(player).getPropertySize(); i++)
		temp += roster.at(player).getPropertyName(i) + ", ";
	return temp;
}

bool Board::payPlayer(int from, int to, int amount)
{
	
	if (roster.at(from).getMoney() >= amount)
	{
		if (to == -1)
		{
			roster.at(from).payMoney(amount);
			return true;
		}
		roster.at(from).payMoney(amount);
		roster.at(to).addMoney(amount);
		return true;
	}
	cout << "Don't day dream." << "You only have "<< roster.at(from).getMoney() << "." << endl;

	return false;
}

void Board::addCell(Cells input)
{
	cellArray.push_back(input); 
	cellArray.at(cellArray.size() - 1).setNumber(cellArray.size() - 1);
}

void Board::loadCards()
{
	string ndescr[10] = { "Advance to Go-Collect $200" ," Go To Jail" , "Get out of Jail" , "Street Repairs (Pay $50)" ,"Collect $100", "Doctor fees(Pay $50)",
		"Bank Error (Receive $75)",	"Go Back 3 spaces",	"Take trip to nearest Railroad (If you pass Go collect $200, if owned, pay double rent)",
		"Go directly to Kentucky Ave. (If you pass Go, collect $200)"};
	int $$$[10] = {200,0,0,-50,100,-50,75,0,200,200};
	int loc[10] = { 0,0,0,0,0,0,0,1,13,-1 };
	for (int i = 0; i < 10; i++)
	{
		Card newcard(ndescr[i],$$$[i],loc[i]);
		cardPile.push_back(newcard);
	}
	std::random_shuffle(cardPile.begin(), cardPile.end());
}

void Board::buyProperty(int player, int location)
{
	if (locations.at(location)->getAvailable())
	{
		roster.at(player).purchase(locations.at(location));
		locations.at(location)->setAvailable(false);
		locations.at(location)->setOwner(player);
	}
	else
		cout << "Is not available. ";
}

void Board::drawCard(int player)
{

	cardPile.at(cardPile.size() - 1).readCard();
	roster.at(player).addMoney(cardPile.at(cardPile.size()-1).getValue());
	if (cardPile.at(cardPile.size()-1).getValue() == 0)
	{
		if (cardPile.at(cardPile.size() - 1).getJail())
			roster.at(player).pickJailCard();
		else if (cardPile.at(cardPile.size() - 1).getLoc() == 1)
			roster.at(player).changePosition(-3);
		else if (cardPile.at(cardPile.size() - 1).getLoc() == 13)
			roster.at(player).setPosition(13);
		else if (cardPile.at(cardPile.size() - 1).getLoc() == -1)
		{
			int x = rand() % 4;
			roster.at(player).setPosition(6*x + 3);
		}

	}

	cardPile.pop_back();
}

int Board::getMoney(int player)
{
	return roster.at(player).getMoney();
}

void Board::propertiesOwned(int player)
{
	for (int i = 0; i < roster.at(player).getPropertySize(); i++)
		cout << roster.at(player).getPropertyName(i) << ", ";
}

void Board::rollDicePlayer(int player)
{
	int x = roster.at(player).rollDice();
	roster.at(player).changePosition(x);
	cout << "You rolled a " << x << endl;
}

void Board::loadCells()
{
	std::string temp[24] = { "Go", "Mediterrean\n Price to buy this property: $60\n House price: $60", "Income Tax", "Reading Railroad\n Price to buy: $200", "Draw a Card", "Oriental Avenue\n Price to buy this property: $120\n House price: $120", "Just visiting", "Electric Company\n Price to buy: $150", "State's Avenue\n Price to buy this property: $160\n House price: $160", "Pennsylvania Railroad\n Price to buy this property: $200", "St. James' Place\n Price to buy this property: $180\n House price: $180", "Draw a Card", "Just visiting", "Kentucky Avenue\n Price to buy this property: $240\n House price: $240", "Draw a Card", "B & O Railroad\n Price to purchase this property: $200", "Water Works\n Price to buy this property: $150", "Marvin Gardens\n Price to buy this property: $260\n House price: $260", "Go to Jail, Do not pass Go, do not collect $200!", "Pacific Avenue\n Price to buy this property: $320\n House price: $320", "Luxury tax", "Short Line Railroad\n Price to buy this property: $200", "Draw a card", "Boardwalk\n Price to buy this property: $400\n House price: $400" };

	for (int i = 0; i < 24; i++)
	{
		Cells tempC(i, temp[i]);
		cellArray.push_back(tempC);

	}
}

void Board::loadProperties()
{
	std::string tempDescription[24] = { "Go!", "Mediterrean", "Income Tax", "Reading Railroad", "Draw a Card", "Oriental Avenue", "Just Visiting", "Electric Company", "State's Avenue", "Pennsylvania Railroad", "St. Jame's Place", "Draw a Card", "Free Parking", "Kentucky Avenue", "Draw a Card", "B & O Railroad", "Waterworks", "Marvin Gardens", "Go to Jail, Do not pass Go, do not collect $200!", "Pacific Avenue", "Luxury Tax", "Short Line", "Draw a Card", "Boardwalk" };
	int value[24] = { 0,60,0,200,0,120,0,150,140,200,180,0,0,220,0,200,150,260,0,320,0,200,0,400 };
	for (int i = 0; i < 24; i++)
		if (i == 1 || i == 5 || i == 8 || i == 10 || i == 13 || i == 17 || i == 19 || i == 23)
		{
			locations.push_back(new House(value[i], tempDescription[i], true));
		}
		else if (i == 3 || i == 9 || i == 15 || i == 21)
		{
			locations.push_back(new Railroad(value[i], tempDescription[i], true));
		}
		else if (i == 7 || i == 16)
		{
			locations.push_back(new Utilities(value[i], tempDescription[i], true));
		}
		else
		{
			locations.push_back(new Empty(value[i], tempDescription[i], true));
		}
}

void Board::checkRent(int player)
{
	if (locations.at(roster.at(player).getPosition())->getOwner() != player)
	{
		payPlayer(player, locations.at(roster.at(player).getPosition())->getOwner(), locations.at(roster.at(player).getPosition())->getValue());
	}
}

void Board::display(int player)
{
	cout << endl;
	cout << " Bank statement: " << getMoney(player) << endl;
	cout << " Current properties: "; propertiesOwned(player);
	
	std::string tempName = getName(roster.at(player).getPosition());
	cout << endl;
	cout << " Current location: " << tempName << endl;
	cout << endl;
}
