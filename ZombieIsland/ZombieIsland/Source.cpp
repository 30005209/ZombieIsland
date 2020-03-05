#include <iostream>
#include <string>
#include "Character.h"
#include "Monster.h"
#include "Hole.h"
#include "Tile.h"
#include <algorithm>
#include "Die.h"
#include <conio.h>
#include "console.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	Entity ent;
	Monster mons;
	Character cha;
	Hole ho;

	Console con;

	vector<Tile> board;
	//vector<Tile>::iterator iterBoard = board.begin();

	const int ROW = 10;
	const int COL = 10;

	const int NOMON = 15;
	const int NOHOL = 8;
	const int NOCHA = 1;	

	char up = 'w';
	char down = 's';
	char left = 'a';
	char right = 'd';


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

	for (int i = Die::roll(); i >0; i--)
	{
		std::random_shuffle(board.begin(), board.end());
	}
	
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
		

	while (TRUE)
	{
		bool change = false;
		char key = _getch();

		if (key == up || key == down || key == left || key == right)
		{
			//Movement
			cha.move(key);
			change = true;
		}

		if (key == 13)
		{
			iterBoard = board.begin();
			for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
			{
				if (iterBoard->grabOwner()->getSymbol() == 'M')
				{
					iterBoard->grabOwner()->move(1);
				}
			
				if(iterBoard->grabOwner()->getSymbol() == 'm')
				{
					iterBoard->grabOwner()->move(2);
				}
			}
		}

		if (change)
		{
			iterBoard = board.begin();
			for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
			{ 
				if (iterBoard->grabOwner()->getHasChanged())
				{

					//Set the postion equal to total number of spaces
					int x = i;

					//Make sure it doesnt attempt to create a -ve x value
					while (x >= 0 + ROW)
					{
						//remove Row number of spaces until it is on base row
						//result will be the x coordinate
						x = x - ROW;
					}

					if (ROW != 0)
					{
						con.setCursorPosition({ SHORT(i / ROW), SHORT(x)});
					}
					else
					{
						con.setCursorPosition({SHORT(0), SHORT(x) });
					}
					cout << iterBoard->readOwner();
				}
			}
		}

	}

	cin.ignore();
	cin.get();

	return 0;
}

