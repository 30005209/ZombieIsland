#ifndef Monster_H
#define Monster_H
#include "Entity.h"

class Monster :	public Entity
{
public:
	Monster();
	~Monster();


	void taketurn(void);			//Take a given amount of turns if non specifed take one
	void move(int direction = Die::roll(4));	//Move in a given direction if non specifed take a random one

};
#endif