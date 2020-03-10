#include "Monster.h"

Monster::Monster()
{
	setSym('M');
}

Monster::~Monster()
{
}

void Monster::taketurn(int numTurns)
{
	//Move so long as it is the Monsters turn
	while (numTurns)
	{
		move();
		numTurns--;
	}
	
}

void Monster::move(int direction)
{
	switch (direction)
	{
	case 1:	//Up

		break;

	case 2:	//Down

		break;

	case 3:	//Left

		break;

	case 4:	//Right

		break;
	}
}

