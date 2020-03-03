#ifndef _Tile
#define _Tile
#include <vector>
#include "Entity.h"

class Tile
{
private:

	Entity * owner;		//This is the player that is on the current tile

public:
	Tile();
	~Tile();


	void setOwner(Entity * );		//Set the owner to another pointer of an Entity
	const char readOwner(void);		//Get the symbol of the owner
	Entity * grabOwner(void);		//Get a reference to the owner

};
#endif _Tile