#ifndef Monster_H
#define Monster_H
#include "Moveable.h"

class Monster :	public Moveable
{
public:
	Monster();
	~Monster();

	void move(void);	//Random Movement
	void move(int);		//Move in a prescribed way

	void encounter(Entity);	//Handles what occurs when it collides with another entity

};

#endif