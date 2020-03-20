#include "Entity.h"

typedef vector<Entity>::iterator Position;

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
	if (abs(getXDesire()) <= 2 && abs(getYDesire()) <= 2)
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
	//Return a random value if check fails
	return Die::roll(4)-1;
}

bool Entity::getCanAmbush(void)
{
	return this->canAmbush;
}

void Entity::encounter(Entity* other)
{
	//If this is a monster...
	if (this->getSymbol() == 'M')
	{
		//Decide behaviour based on what its encountering
		switch (other->getSymbol())
		{
		//If its a blank space swap them
		case ' ':
			std::swap(*this, *other);
			this->setChanged(true);
			other->setChanged(true);
			break;

		//If its a hole kill self
		case 'O':
			this->setSym(' ');
			this->setChanged(true);
			break;

		//If its a monster do nothing (can be seen as swapping or bouncing off)
		case 'M':
			break;

		//If its the player kill the player
		case 'C':
			other->setSym('X');
			other->setChanged(true);
			break;

		case '#':
			this->setSym(' ');
			other->setSym('0');
			this->setChanged(true);
		}
	}

	//If this is the player...
	else if (this->getSymbol() == 'C')
	{
		//Decide behaviour based on what its encountering
		switch (other->getSymbol())
		{
			//If its a blank space swap them
		case ' ':
			std::swap(*this, *other);
			this->setSym('#');
			this->setChanged(true);
			other->setChanged(true);
			break;

			//If its a hole kill self
		case 'O':
			this->setSym(' ');
			this->setChanged(true);
			break;

			//If its a monster kill self
		case 'M':
			this->setSym('X');
			this->setChanged(true);
			break;
		}
	}
	else
	{

	}
}

