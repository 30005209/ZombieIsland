#ifndef Character_H
#define Character_H

#include "Monster.h"

class Character :	public Entity
{

	char up;							//Mapped control for up
	char left;							//Mapped control for left
	char down;							//Mapped control for down
	char right;							//Mapped control for right


public:
	Character();
	~Character();

	void taketurn(void);
	void move(int);		//Move in a given direction if non specifed take a random one

};
#endif