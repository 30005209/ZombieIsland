#pragma once
#include "Entity.h"
class Monster :
	virtual public Entity
{
private:
	   int moveDesires[2];								//Denotes where the monsters would like to move

public:
	Monster();
	~Monster();


	//Setters
	void setDesires(int, int);						//Sets where monsters would like to move

	//Getters
	int getXDesire(void);							//Get where the monster would like to move x
	int getYDesire(void);							//Get where the monster would like to move y
	int getPredomDesire(void);

	//Other Functions
	int encounter(Entity* other);					//Handles encounters with another entity
};
