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
			this->setSym(' ');
			other->setSym('M');
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
			this->setSym(' ');
			other->setSym('C');
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

