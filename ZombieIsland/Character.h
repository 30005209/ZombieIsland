#pragma once
#include "Entity.h"
class Character :
	virtual public Entity
{
public:
	Character();
	~Character();

	int encounter(Entity *);

};
