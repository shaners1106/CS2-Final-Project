#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include "Board.h"
#include "Card.h"
#include "Player.h"
#include "Cells.h"
#include "cellClass.h"
using namespace std;
int main()
{
	Board mothership;
	ofstream fout;
	fout.open("monopoly.csv");
	if (fout.fail())
	{
		cout << "Can't open file" << endl;
		return 0;
	}

	//mothership.loadCards();
	/*
	// Game initialization
	std::string tempDescription[24] = { "Mediterrean\n Price to buy this property: $60\n House price: $60", "", "Reading Railroad\n Price to buy: $200", "", "Oriental Avenue\n Price to buy this property: $120\n House price: $120", "", "Electric Company\n Price to buy: $150", "State's Avenue\n Price to buy this property: $160\n House price: $160", "Pennsylvania Railroad\n Price to buy this property: $200", "St. Jame's Place\n Price to buy this property: $180\n House price: $180", "", "", "Kentucky Avenue\n Price to buy this property: $240\n House price: $240", "", "B & O Railroad\n Price to purchase this property: $200", "Water Works\n Price to buy this property: $150", "Marvin Gardens\n Price to buy this property: $260\n House price: $260", "", "Pacific Avenue\n Price to buy this property: $320\n House price: $320", "", "Short Line Railroad\n Price to buy this property: $200", "", "Boardwalk\n Price to buy this property: $400\n House price: $400" };
	int value[24] = { 60,0,200,0,120,0,150,140,200,180,0,0,220,0,200,150,260,0,320,0,200,0,400 };
	mothership.loadProperties(tempDescription, value);
	*/

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << endl;
	cout << "Welcome to Inevitable Bankruptcy!" << endl << "The game of perpetual misfortune. " << endl;
	cout << "This is a beta version of the monopoly game and does not contain the full scope of ";
	cout <<	"the original game rules. For a full version, please wait for our final release. " << endl;
	cout << endl;
	char r; // char to roll dice

	int choice = -1;
	while (choice != 0)
	{
		cout << "Please choose what you would like to do: " << endl;
		cout << "Begin new game: 1 " << endl;
		cout << "Read game instructions: 2 " << endl;
		cout << "To exit game: 0 " << endl;
		cin >> choice;

		while ((!(choice == 1 || choice == 2  || choice == 0)))
		{
			cout << "Oops, wrong button. Try again! " << endl;
			cin.clear();
			cin.ignore();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			char token;
	


			cout << "Player 1, please choose your fighter(? Question mark, # Mr. Tic Tac Toe, & Ampersand, or ! Exclamation mark): ";
			cin >> token;
			mothership.addPlayer(token);
			cout << endl;
			cout << "Player one will be the " << mothership.getToken(0) << endl;
			cout << endl;
			cout << "Player 2, please choose your fighter (same choices except what player 1 entered): ";
			cin >> token;
			mothership.addPlayer(token);
			cout << endl;
			cout << "Player two will be the " << mothership.getToken(1) << endl;
			cout << "Let's play!" << endl;
			while (true)
			{
				
				for (int i = 0; i < mothership.getNumPlayers(); i++)
				{
					cout << "---------- " << mothership.getToken(i) << " " << mothership.getToken(i) << " " << mothership.getToken(i) << " ----------" << endl;
					cout << "Enter 'r' to roll the dice. " << "\nEnter 'q' to exit to main menu.\n" ;
					cin >> r;
					mothership.rollDicePlayer(i);
					mothership.display(i);
					int tempLoc = mothership.getPlayerPosition(i);
					if (r == 'r')
					{
						if (!(tempLoc == 0 || tempLoc == 2 || tempLoc == 4 || tempLoc == 6 || tempLoc == 11 || tempLoc == 12 || tempLoc == 14 || tempLoc == 18 || tempLoc == 20 || tempLoc == 22 || !(mothership.owned(tempLoc))))
						{
							cout << "Do you want to buy to this place('y' or 'n')." << endl;
							char buyChoice;
							cin >> buyChoice;
							if (buyChoice == 'y')
							{
								mothership.buyProperty(i, tempLoc);
							}

							// If landed on someones property
						}
					}
					if (mothership.owned(tempLoc))
					{
						mothership.payPlayer(i, mothership.getCellPlayer(mothership.getPlayerPosition(i)), mothership.getRent(mothership.getPlayerPosition(i)));
					}
					if (tempLoc == 4 || tempLoc == 11 || tempLoc == 14 || tempLoc == 22)
					{
						mothership.drawCard(i);
					}
					if (tempLoc == 2 || tempLoc == 20)
					{
						mothership.payPlayer(i, -1, 200);
					}
					cout << "End of turn! " << endl;
					if (mothership.getMoney(i) < 0)
					{
						for (int i = 0; i < 2; i++)
						{
							fout << "Player " << i << " has: " << mothership.getMoney(i) << " bitcoins." << endl;
							fout << "Player " << i << " properties are " << mothership.stringProperties(i) << "." << endl << endl;
						}
						fout.close();
						cout << "" << endl;
						return 0;
					}
					if (r == 'q')
						break;
				}
				if (r == 'q')
					break;
			}
		}
		
		case 2:
		{
			cout << "Instructions: " << endl;
			cout << "1. Pick your player token. " << endl;
			cout << "2. Enter 'r' to roll the dice. " << endl;
			cout << "3. Choose what you would like to do with your turn based off of player menu. " << endl;
			cout << "4. First person to run out of money loses! " << endl;
			cout << "5. Have fun! " << endl;
			continue;
		}
		case 0:
		{
			for (int i = 0; i < 2; i++)
			{
				fout << "Player " << i << " has: " << mothership.getMoney(i) << " bitcoins." << endl;
				fout << "Player " << i << " properties are " << mothership.stringProperties(i) << "." << endl << endl;
			}
			fout.close();
			cout << "Thank you for viewing the game where you will inevitably become bankrupt. Please return soon! " << endl;
			break;
		}
		}
	}
}