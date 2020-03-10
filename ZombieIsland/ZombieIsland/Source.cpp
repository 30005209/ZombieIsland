#include <iostream>
#include <string>
#include "Character.h"
#include "Monster.h"
#include "Hole.h"
#include "Tile.h"
#include <algorithm>
#include "Die.h"
#include "GameManager.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{

	////Set the board size
	//board.resize(ROW * COL);

	//vector<Entity>::iterator iter = board.begin();
	//for (int i = 0; iter != board.end(); i++, iter++)
	//{
	//	if (i < NOMON)							//Make a character
	//	{
	//		board.at(i) = Monster();
	//	}
	//	else if (i < NOMON + NOHOL)				//Make a Hole
	//	{
	//		board.at(i) = Hole();
	//	}	
	//	else if (i < NOMON + NOHOL + NOCHA)		//Make a Character
	//	{
	//		board.at(i) = Character();
	//	}	
	//	else									//Make a default Entity
	//	{
	//		board.at(i) = Entity();	
	//	}
	//
	//	board.at(i).setCode(i);
	//}
	//


	////Randomise the board a random amount of times (otherwise it would be the same "random" layout)
	//for (int i = Die::roll(); i >0; i--)
	//{
	//	std::random_shuffle(board.begin(), board.end());
	//}
	//

	////Print the Board
	//vector<Entity>::iterator iterBoard = board.begin();
	//for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
	//{
	//	if (i != 0)
	//	{
	//		if (!(i % COL))
	//		{
	//			cout << endl;
	//		}
	//	}
	//	cout << iterBoard->getSymbol();
	//	iterBoard->setPos(iterBoard);
	//}
	//	

	//while (TRUE)
	//{
	//	bool change = false;
	//	char key = _getch();

	//	//If the player has done movement input
	//	if (key == up || key == down || key == left || key == right)
	//	{
	//		//Move the player
	//		cha.move(key);
	//		change = true;
	//	}

	//	//If they have pressed Enter
	//	if (key == 13)
	//	{
	//		iterBoard = board.begin();
	//		for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
	//		{
	//			if (iterBoard->getSymbol() == 'M')
	//			{
	//				iterBoard->move(1);
	//			}
	//		
	//			if(iterBoard->getSymbol() == 'm')
	//			{
	//				iterBoard->move(2);
	//			}
	//		}
	//	}

	//	//If something has chaged
	//	if (change)
	//	{
	//		iterBoard = board.begin();
	//		for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
	//		{ 
	//			if (iterBoard->getHasChanged())
	//			{

	//				//Set the postion equal to total number of spaces
	//				int x = i;

	//				//Make sure it doesnt attempt to create a -ve x value
	//				while (x >= 0 + ROW)
	//				{
	//					//remove Row number of spaces until it is on base row
	//					//result will be the x coordinate
	//					x = x - ROW;
	//				}

	//				if (ROW != 0)
	//				{
	//					con.setCursorPosition({ SHORT(i / ROW), SHORT(x)});
	//				}
	//				else
	//				{
	//					con.setCursorPosition({SHORT(0), SHORT(x) });
	//				}
	//				cout << iterBoard->getSymbol();
	//			}
	//		}
	//	}

	//}

	cin.ignore();
	cin.get();

	return 0;
}

