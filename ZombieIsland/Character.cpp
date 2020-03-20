#include "Character.h"

Character::Character()
{
	//Set the symbol
	setSym('C');
}


Character::~Character()
{
}


int Character::encounter(Entity * other)
{

	//Enum used for legibility
	enum { swap = 0, die = 1, kill = 2, fall = 3, dieWP = 4 };

	int result = 0;
	//If encountering a blank space just swap
	if (other->getSymbol() == ' ')
	{
		result = swap;
	}
	//If encounter a monster die
	else if (other->getSymbol() == 'M')
	{
		result = die;
	}
	//If encountering a hole fall
	else if (other->getSymbol() == 'O')
	{
		result = fall;
	}
	//If encountering a weak floor - swap
	else if (other->getSymbol() == '#')
	{
		result = swap;
	}

	//Return result to be used for movement by GameManager
	return result;
}

//Getter
bool Character::getCanAmbush(void)
{
	return canAmbush;
}

//Setter
void Character::setCanAmbush(bool newVal)
{
	this->canAmbush = newVal;
}
