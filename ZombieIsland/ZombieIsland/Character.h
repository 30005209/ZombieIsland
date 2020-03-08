#ifndef Character_H
#define Charater_H

#include "Moveable.h"

class Character :	public Moveable
{
public:
	Character();
	~Character();


	
	void move(int);					//Controls movement for character
	void encounter(vector<Entity>::iterator) final;	//Handles what occurs when it collides with another entity

};
#endif