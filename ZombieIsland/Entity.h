#ifndef _Entity
#define _Entity

#include "Die.h"
#include <vector>
#include <string>
#include <algorithm>

using std::vector;

class Entity
{
private:
	

	char symbol;									//The symbol being displayed
	bool hasChanged;								//Notes whether the Entity has changed since it was last printed
	int baseMove;									//Denotes the standard number of turns	
	int moveDesires[2];								//Denotes where the monsters would like to move

protected:
	bool canAmbush;

public:
	Entity();
	Entity(char);
	~Entity();

	//Setters
	void setSym(char);								//Set symbol to a given one
	void setBaseMove(int);							//Sets the baseMove to a given one
	void setChanged(bool);							//States that the Entity has taken its turn/changed
	virtual void setDesires(int, int);				//Sets where monsters would like to move
	virtual void setCanAmbush(bool);

	int getYDesire(void);
	int getXDesire(void);

	//Getters
	char getSymbol(void);							//Get the symbol of the entity
	int getBaseMove(void);							//Gets the base movement value
	bool getHasChanged(void);						//Get haschanged
	Entity* getSelf(void);							//Gets a pointer to self
	virtual int getPredomDesire(void);
	virtual bool getCanAmbush(void);

	//Other Functions
	virtual int encounter(Entity* other);			//Handles encounters with another entity
};


#endif