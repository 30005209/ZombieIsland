#pragma once
#include "Entity.h"
class Hole :
	virtual public Entity
{
public:
	Hole();
	~Hole();

	int encounter(Entity *);
};

