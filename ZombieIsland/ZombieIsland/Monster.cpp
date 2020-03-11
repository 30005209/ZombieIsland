#include "Monster.h"

Monster::Monster()
{
	setSym('M');
}

Monster::~Monster()
{
}

void Monster::taketurn(void)
{
	//Move so long as it is the Monsters turn
	int numTurns = getBaseMove();

	while (numTurns > 0)
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
		setPos(getPos() - 1);
		break;

	case 4:	//Right
		setPos(getPos() + 1);
		break;
	}
}

