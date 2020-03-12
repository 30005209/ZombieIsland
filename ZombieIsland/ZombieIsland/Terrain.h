#include "Entity.h"

#ifndef _Terrain
#define _Terrain

class Terrain : public Entity
{
public:
	Terrain();
	~Terrain();


	void taketurn(void);
	void move(int);
};

#endif