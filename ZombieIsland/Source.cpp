#include "GameManager.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


//THINGS TO ADD
//Create a log file that records the name of anybody who uses the game and the result of each game they play
//	(make sure this list is appended and stores all of the name of the people that have played the game) 
//The monsters are to try and capture the character by landing on the same location as the main character.
//	The monsters will need some simple strategy to move towards the character and not simply move in a random direction.

int main()
{
	GameManager GM;

	bool gameSet = false;

	while (!gameSet)
	{
		GM.getCon().clear();
		
		bool validRow = false;
		int tempRow = 9;

		while (!validRow)
		{
			GM.getCon().clear();
			cout << "How many rows do you want?: ";
			cin >> tempRow;

			validRow = (tempRow >= 10 && tempRow <= 20);
			cin.ignore();
		}

		bool validCol = false;
		int tempCol = 9;

		while (!validCol)
		{
			GM.getCon().clear();
			cout << "How many columns do you want?: ";
			cin >> tempCol;

			validCol = (tempCol >= 10 && tempCol <= 40);

			cin.ignore();
		}


		bool validDifficulty = false;
		int tempDif;
		while (!validDifficulty)
		{
			GM.getCon().clear();
			cout << "How hard dyou want the game to be ?\n"
				<< "1. Easy\n"
				<< "2. Medium\n"
				<< "3. Hard\n";
			
			cin >> tempDif;

			validDifficulty = (tempDif == 1 || tempDif == 2 || tempDif == 3);

			cin.ignore();
		}

		GM.setGridSize(tempRow, tempCol);
		GM.setFromDiffilculty(tempDif);
		gameSet = true;
		GM.randomiseBoard();

		GM.getCon().clear();
	}

	GM.printBoard();
	GM.printScoreboard();

	//While there are monsters remaining and the player is alive - play
	while (GM.monstersRemain() && GM.playerIsAlive())
	{
		GM.playTurn();
	}

	if (GM.monstersRemain())
	{
		cout << "\nya died";
	}
	else
	{
		cout << "\nfair play";
	}

	cin.get();

	return 0;
}