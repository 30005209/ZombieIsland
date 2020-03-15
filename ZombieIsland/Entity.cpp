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

void Entity::setBrd(vector<Entity>* newBoard)
{
	this->ptrBoard = newBoard;
}

void Entity::setPos(Position newPos)
{
	this->pos = newPos;
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

vector<Entity>* Entity::getBoard(void)
{
	return this->ptrBoard;
}

Position Entity::getPos(void)
{
	return this->pos;
}

void Entity::taketurn(void)
{
}

void Entity::move(int)
{
}

void Entity::encounter(Entity other)
{
}

