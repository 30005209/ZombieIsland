#include "Character.h"

Character::Character()
{
	setSym('C');
}


Character::~Character()
{
}


int Character::encounter(Entity * other)
{
	//0 == swap
	//1 == die
	//2 == kill
	//3 == fall
	//4 == die (with points)

	enum { swap = 0, die = 1, kill = 2, fall = 3, dieWP = 4 };

	int result = 0;
	if (other->getSymbol() == ' ')
	{
		result = swap;
	}
	else if (other->getSymbol() == 'M')
	{
		result = die;
	}
	else if (other->getSymbol() == 'O')
	{
		result = fall;
	}
	else if (other->getSymbol() == '#')
	{
		result = swap;
	}

	return result;
}

bool Character::getCanAmbush(void)
{
	return canAmbush;
}

void Character::setCanAmbush(bool newVal)
{
	this->canAmbush = newVal;
}
