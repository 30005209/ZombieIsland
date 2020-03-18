#ifndef _Entity
#define _Entity

#include "Die.h"
#include <vector>
#include <string>

using std::vector;

class Entity
{
private:
	
	typedef vector<Entity>::iterator Position;

	char symbol;									//The symbol being displayed
	bool hasChanged;								//Notes whether the Entity has changed since it was last printed
	int baseMove;									//Denotes the standard number of turns

public:
	Entity();
	Entity(char);
	~Entity();

	//Setters

	void setSym(char);								//Set symbol to a given one
	void setBaseMove(int);							//Sets the baseMove to a given one
	void setChanged(bool);							//States that the Entity has taken its turn/changed
		

	//Getters
	char getSymbol(void);							//Get the symbol of the entity
	int getBaseMove(void);							//Gets the base movement value
	bool getHasChanged(void);						//Get haschanged
	Entity* getSelf(void);							//Gets a pointer to self
	

	//Other Functions
	void encounter(Entity* other);					//Handles encounters with another entity

};


#endif