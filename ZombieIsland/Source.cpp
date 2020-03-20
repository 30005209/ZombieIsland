#include "GameManager.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	std::ifstream inFile;
	std::ofstream outFile;
	GameManager GM;

	GM.setUp();

	//While there are monsters remaining and the player is alive - play
	while (GM.monstersRemain() && GM.playerIsAlive())
	{
		GM.updateInfo();
		GM.playTurn();
	}

	if (GM.monstersRemain())
	{
		GM.typeWrite("\nended just like that...");
		Sleep(500);
		outFile.open("Highscore.txt", std::ios::in |std::ios::binary);
		outFile << "HIGHSCORES\n";
		outFile.seekp(0, std::ios::end);
		outFile << GM.getName() << ": " << GM.getScore() << "\n";
		outFile.close();
	}
	else
	{
		GM.typeWrite("\nAnd they're still kicking!");
		Sleep(500);
		outFile.open("Highscore.txt");
		outFile._Seekend;
		outFile << "Score: " << GM.getScore() * 2 << "\n";
		outFile.close();
	}

	cin.ignore();
	cin.get();

	return 0;
}