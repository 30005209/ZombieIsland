#ifndef Character_H
#define Character_H

#include "Monster.h"

class Character :	public Monster
{

	char up;							//Mapped control for up
	char left;							//Mapped control for left
	char down;							//Mapped control for down
	char right;							//Mapped control for right


public:
	Character();
	~Character();


	char getUp(void);										//Get the currently mapped control for up
	char getDown(void);										//Get the currently mapped control for down
	char getLeft(void);										//Get the currently mapped control for left
	char getRight(void);									//Get the currently mapped control for right

	bool isPlayerControl(char);								//Check if its a game control for the player

	void taketurn(char);						//Take a given amount of turns if non specifed take one
	void move(int);								//Move in a given direction if non specifed take a random one

};
#endif