#include "Entity.h"

Entity::Entity()
{
}


Entity::Entity(char symbol)
{
	this->symbol = symbol;
}

Entity::~Entity()
{
}

void Entity::setSym(char newSym)
{
	this->symbol = newSym;
}

void Entity::setBaseMove(int newBaseMove)
{
	this->baseMove = newBaseMove;
}

void Entity::setChanged(bool newBool)
{
	this->hasChanged = newBool;
}

void Entity::setDesires(int, int)
{
	//virtual
}


void Entity::setCanAmbush(bool newVal)
{
	this->canAmbush = newVal;
}

char Entity::getSymbol(void)
{
	return this->symbol;
}

int Entity::getBaseMove(void)
{
	return this->baseMove;
}

bool Entity::getHasChanged(void)
{
	return this->hasChanged;
}

Entity * Entity::getSelf(void)
{
	return this;
}

int Entity::getPredomDesire(void)
{
	return 0;
}



bool Entity::getCanAmbush(void)
{
	return this->canAmbush;
;
}

int Entity::encounter(Entity * other)
{
	//0 == swap
	//1 == die
	//2 == kill
	//3 == fall
	//4 == die (with points)

	enum { swap = 0, die = 1, kill = 2, fall = 3, dieWP = 4 };

	int result = 0;
	
	if (this->getSymbol() == 'O')
	{
		if (this->getSymbol() == ' ')
		{
			result = swap;
		}
		else if (this->getSymbol() == 'M')
		{
			result = swap;
		}
		else if (this->getSymbol() == 'C')
		{
			result = swap;
		}
		else if (this->getSymbol() == '#')
		{
			result = swap;
		}
	}
	return result;
}

