#include "Entity.h"

Entity::Entity()
{
	setSym('#');
}


Entity::~Entity()
{
}

void Entity::setBrd(const vector<Entity>* pBrd)
{
	this->brd = pBrd;
}

void Entity::setPos(const vector<Entity>::iterator newPos)
{
	this->pos = newPos;
}

void Entity::setSym(const char newSym)
{
	this->sym = newSym;
}

const char Entity::getSymbol(void)
{
	return sym;
}

const vector<Entity>* Entity::getBoard(void)
{
	return brd;
}

const vector<Entity>::iterator Entity::getPos(void)
{
	return pos;
}

void Entity::move(void)
{
}

void Entity::move(int)
{
}

void Entity::move(Entity *)
{
}


const bool Entity::isBelow(Entity *)
{
	return false;
}

const bool Entity::isLeftOf(Entity *)
{
	return false;
}

const bool Entity::isOnCol(Entity *)
{
	return false;
}

const bool Entity::isOnRow(Entity *)
{
	return false;
}

bool Entity::getHasChanged(void)
{
	return hasChanged;
}
