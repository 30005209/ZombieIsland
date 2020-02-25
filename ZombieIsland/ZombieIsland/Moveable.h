#ifndef Moveable_H
#define Moveable_H


#include "Entity.h"
class Moveable :	public Entity
{
public:

	enum { Up = 0, Right = 1, Down = 2, Left = 3 };		//For usage with the move function
	
	Moveable();
	~Moveable();

	virtual void move(void);	//Random Movement
	virtual void move(int);		//Prescribed Movement

	virtual void encounter(Entity);	//Handles collision with another entity

};

#endif