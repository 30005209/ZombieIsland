#include "Entity.h"


typedef vector<Entity>::iterator Position;

Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::setBrd(vector<Entity>* newBoard)
{
	this->ptrBoard = newBoard;
}

void Entity::setSym(char newSymbol)
{
	this->symbol = newSymbol;
}

void Entity::setPos(Position newPos)
{
	this->pos = newPos;
}

void Entity::setCode(int newCode)
{
	this->code = newCode;
}

void Entity::setIsAlive(bool nowAlive)
{
	this->isAlive = nowAlive;
}

void Entity::setBaseMove(int newVal = 1)
{
	baseMove = newVal;
}

char Entity::getSymbol(void)
{
	return this->symbol;
}

int Entity::getBaseMove(void)
{
	return baseMove;
}

int Entity::getCode(void)
{
	return this->code;
}

bool Entity::getHasChanged(void)
{
	return this->hasChanged;
}

vector<Entity>* Entity::getBoard(void)
{
	return this->ptrBoard;
}

Position Entity::getPos(void)
{
	return this->pos;
}

bool Entity::getIsAlive(void)
{
	return isAlive;
}

void Entity::taketurn(void)
{
	int numTurns = getBaseMove();

	while (numTurns > 0)
	{
		//INSERT CODE FOR TURN
		
		numTurns--;
	}
}

void Entity::move(int direction = Die::roll(4))
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
