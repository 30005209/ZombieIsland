#ifndef Character_H
#define Charater_H

#include "Moveable.h"

class Character :	public Moveable
{
public:
	Character();
	~Character();


	
	void move(void) final;	//Controls movement for character

	void encounter(Entity) final;	//Handles what occurs when it collides with another entity

};
#endif