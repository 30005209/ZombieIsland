#include "GameManager.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	GameManager GM;

	GM.printBoard();

	while (!GM.isGameOver())
	{

	}



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

