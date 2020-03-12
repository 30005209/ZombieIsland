#pragma once
#include "Entity.h"
class Hole :	public Entity
{
public:
	Hole();
	~Hole();

	void taketurn(void);
	void move(int);
};

