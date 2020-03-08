#include "Character.h"

Character::Character()
{
	setSym('C');
}

Character::~Character()
{
}

void Character::move(int input)
{
	hasChanged = true;
}

void Character::encounter(vector<Entity>::iterator other)
{
	setSym(other->getSymbol());
	
}
