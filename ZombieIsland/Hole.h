#ifndef _HoleC
#define _HoleC

#include "Entity.h"
class Hole :
	virtual public Entity
{
public:
	Hole();
	~Hole();

	int encounter(Entity *);
};

#endif