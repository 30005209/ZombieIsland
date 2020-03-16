#include "GameManager.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;


//THINGS TO ADD
//Sort highscores
//The monsters are to try and capture the character by landing on the same location as the main character.
//	The monsters will need some simple strategy to move towards the character and not simply move in a random direction.

int main()
{
	std::ifstream inFile;
	std::ofstream outFile;
	GameManager GM;
	string name;

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

		bool validName = false;
		
		while (!validName)
		{
			GM.getCon().clear();
			cout << "What would you like your name to be?[max 10]";
			cin >> name;

			validName = name.size() <= 10;
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
		outFile.open("Highscore.txt", std::ios::in |std::ios::binary);
		outFile << "HIGHSCORES\n";
		outFile.seekp(0, std::ios::end);
		outFile << name << ": " << GM.getTurn() << "\n";
		outFile.close();
	}
	else
	{
		cout << "\nfair play"; 
		cout << "\nya died";
		outFile.open("Highscore.txt");
		outFile._Seekend;
		outFile << "Score: " << GM.getTurn() * 2 << "\n";
		outFile.close();
	}

	cin.ignore();
	cin.get();

	return 0;
}