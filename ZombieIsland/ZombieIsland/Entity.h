#ifndef Entity_H
#define Entity_H

#include <vector>
#include <iostream>
#include "Die.h"

using std::cout;
using std::endl;
using std::vector;


//Contains all base functions for objects on the board
class Entity
{
private:

	typedef vector<Entity>::iterator Position;
	
	char symbol;									//The symbol being displayed
	vector<Entity> * ptrBoard;						//Pointer to the board being played on
	Position pos;									//Positon on the board stored as an iterator
	int code;										//The code to distinguish this entity from all others
	bool hasChanged;								//Notes whether the Entity has changed since it was last printed
	bool isAlive;									//Notes whether the Entity is alive
	int baseMove;								//Denotes the standard number of turns

public:
	Entity();
	~Entity();

	//Setters

	void setBrd(vector<Entity>*);				//Set board to a given one
	void setPos(Position);						//Set position to a given one
	void setSym(char);							//Set symbol to a given one
	void setCode(int);							//Set new code to a given one
	void setIsAlive(bool);						//Sets isAlive to a set value
	void setBaseMove(int);						//Sets the baseMove to a given one


	//Getters
	char getSymbol(void);						//Get the symbol of the entity
	int getBaseMove(void);						//Gets the base movement value
	int getCode(void);							//Get the code of the entity
	bool getHasChanged(void);					//Get haschanged
	vector<Entity>* getBoard(void);				//Get the pointer to the board
	Position getPos(void);						//Get the current position
	bool getIsAlive(void);						//Get isAlive


	//Other Functions
	virtual void taketurn(void);				//Take a given amount of turns if non specifed take one
	virtual void move(int);						//Move in a given direction if non specifed take a random one

};


#endif