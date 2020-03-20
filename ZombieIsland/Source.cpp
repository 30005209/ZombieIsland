#include "GameManager.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;


//THINGS TO ADD
//Sort highscores
//Add if highscore.txt not there -> create one
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

		bool custom = false;
		bool chosen = false;

		cout << "Welcome to Zombie Island" << endl;
		cout << "Press a key to begin..." << endl;
		cin.get();

		int tempRow = 9;
		int tempCol = 9;

		while (!chosen)
		{
			GM.getCon().clear();

			cout << "What size map would you like?" << endl;
			cout << "1. Small [10x10]" << endl;
			cout << "2. Medium [15x15]" << endl;
			cout << "3. Large [20x20]" << endl;
			cout << "4. Custom [10-30 x 10-30]" << endl;

			int x = 0;
			cin >> x;
			
			switch (x)
			{
			case 1:
				tempRow = 10;
				tempCol = 10;
				chosen = true;
				break;

			case 2:
				tempRow = 15;
				tempCol = 15;
				chosen = true;
				break;

			case 3:
				tempRow = 20;
				tempCol = 20;
				chosen = true;
				break;

			case 4:
				custom = true;
				chosen = true;
				break;

			default:			
				cin.ignore();
				break;
			}
		}

		//Custom 
		if (custom)
		{
			bool validRow = false;
			while (!validRow)
			{
				GM.getCon().clear();
				cout << "How many rows do you want?: ";
				cin >> tempRow;

				validRow = (tempRow >= 10 && tempRow <= 30);
				cin.ignore();
			}

			bool validCol = false;

			while (!validCol)
			{
				GM.getCon().clear();
				cout << "How many columns do you want?: ";
				cin >> tempCol;

				validCol = (tempCol >= 10 && tempCol <= 30);

				cin.ignore();
			}
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
		GM.updateInfo();
	}

	GM.printBoard();
	GM.printScoreboard();

	//While there are monsters remaining and the player is alive - play
	while (GM.monstersRemain() && GM.playerIsAlive())
	{
		GM.updateInfo();
		GM.playTurn();
	}

	if (GM.monstersRemain())
	{
		cout << "\nya died";
		outFile.open("Highscore.txt", std::ios::in |std::ios::binary);
		outFile << "HIGHSCORES\n";
		outFile.seekp(0, std::ios::end);
		outFile << name << ": " << GM.getScore() << "\n";
		outFile.close();
	}
	else
	{
		cout << "\nfair play"; 
		outFile.open("Highscore.txt");
		outFile._Seekend;
		outFile << "Score: " << GM.getScore() * 2 << "\n";
		outFile.close();
	}

	cin.ignore();
	cin.get();

	return 0;
}