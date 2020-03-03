#include <iostream>
#include <string>
#include "Character.h"
#include "Monster.h"
#include "Hole.h"
#include "Tile.h"
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	Entity ent;
	Monster mons;
	Character cha;
	Hole ho;

	vector<Tile> board;
	//vector<Tile>::iterator iterBoard = board.begin();

	const int ROW = 10;
	const int COL = 10;

	const int NOMON = 15;
	const int NOHOL = 8;
	const int NOCHA = 1;	
	
	board.resize(ROW * COL);

	vector<Tile>::iterator iterBoard = board.begin();
	for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
	{
		if (i < NOMON + NOHOL + NOCHA)
		{
			iterBoard->setOwner(&cha);
		}

		if (i < NOMON + NOHOL)
		{
			iterBoard->setOwner(&ho);
		}

		if (i < NOMON)
		{
			iterBoard->setOwner(&mons);
		}
	}

	std::random_shuffle(board.begin(), board.end());



	iterBoard = board.begin();
	for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
	{
		if (i != 0)
		{
			if (!(i % COL))
			{
				cout << endl;
			}
		}
		cout << iterBoard->readOwner();
	}


	cin.ignore();
	cin.get();

	return 0;
}