#include "Tile.h"



Tile::Tile()
{
	owner = new Entity();
}

Tile::~Tile()
{
}

void Tile::setOwner(Entity * newOwner)
{
	owner = newOwner;
}

const char Tile::readOwner(void)
{
	return owner->getSymbol();
}

Entity * Tile::grabOwner(void)
{
	return owner;
}
