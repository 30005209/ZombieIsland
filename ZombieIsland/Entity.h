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
	vector<Entity> * ptrBoard;						//Pointer to the board being played on
	Position pos;									//Positon on the board stored as an iterator
	bool hasChanged;								//Notes whether the Entity has changed since it was last printed
	int baseMove;									//Denotes the standard number of turns

public:
	Entity();
	Entity(char);
	~Entity();

	//Setters

	void setBrd(vector<Entity>*);					//Set board to a given one
	void setPos(Position);							//Set position to a given one
	void setSym(char);								//Set symbol to a given one
	void setBaseMove(int);							//Sets the baseMove to a given one
	void setChanged(bool);							//States that the Entity has taken its turn/changed
		

	//Getters
	char getSymbol(void);							//Get the symbol of the entity
	int getBaseMove(void);							//Gets the base movement value
	bool getHasChanged(void);						//Get haschanged
	vector<Entity>* getBoard(void);					//Get the pointer to the board
	Position getPos(void);							//Get the current position


	//Other Functions
	void taketurn(void);							//Take a given amount of turns if non specifed take one 
	void move(int);									//Move in a given direction if non specifed take a random one
	void encounter(Entity other);					//Handles encounters with another entity

};


#endif