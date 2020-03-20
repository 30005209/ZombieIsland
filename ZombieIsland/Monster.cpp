#include "Monster.h"

Monster::Monster()
{
	setSym('M');
}


Monster::~Monster()
{
}

int Monster::getXDesire(void)
{
	return moveDesires[0];
}

int Monster::getYDesire(void)
{
	return moveDesires[1];
}


int Monster::getPredomDesire(void)
{
	//if within 2 tiles
	if (abs(getXDesire()) <= 2)
	{
		if (abs(getYDesire()) <= 2)
		{

			{
				//If its further away in X than Y
				if (abs(getXDesire()) > abs(getYDesire()))
				{
					//If its further to the right than the goal
					if (getXDesire() < 0)
					{
						//return left
						return 1;
					}
					else
					{
						//return right
						return 3;

					}
				}
				//If its further away in Y than X
				else
				{
					//If its further up than the goal
					if (getYDesire() < 0)
					{
						//Return down
						return 2;
					}
					else
					{
						//Return up
						return 0;
					}
				}
			}
		}
	}
	//Return a random value if check fails
	return Die::roll(4) - 1;
}

int Monster::encounter(Entity * other)
{

	//Enum for legibility
	enum { swap = 0, die = 1, kill = 2, fall = 3, dieWP = 4 };

	int result = 0;


	//If encountering a blank space swap places
	if (other->getSymbol() == ' ')
	{
		result = swap;

	}

	//If encountering the player - kill them
	else if (other->getSymbol() == 'C')
	{
		result = kill;
	}

	//If encounering a hole - fall
	else if (other->getSymbol() == 'O')
	{
		result = fall;
	}

	//If encountering a weak floor die and score points for the player
	else if (other->getSymbol() == '#')
	{
		result = dieWP;
	}

	return result;

}

void Monster::setDesires(int x, int y)
{
	this->moveDesires[0] = x;
	this->moveDesires[1] = y;
}
