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

void Entity::setDesires(int x, int y)
{
	this->moveDesires[0] = x;
	this->moveDesires[1] = y;
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

int Entity::getXDesire(void)
{
	return moveDesires[0];
}

int Entity::getYDesire(void)
{
	return moveDesires[1];
}

int Entity::getPredomDesire(void)
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

