#ifndef Entity_H
#define Entity_H

#include <vector>

using std::vector;


//A virtual class that contains aspects common across all future objects on the board
class Entity
{
private:

	char sym;							//The symbol being displayed
	const vector<Entity> * brd;			//Pointer to the board being played on
	vector<Entity>::iterator pos;		//Positon on the board stored as an iterator


public:
	Entity();
	~Entity();


	void setBrd(const vector<Entity>*);				//Set board to a given one
	void setPos(const vector<Entity>::iterator);	//Set the position to a new iterator in the board
	void setSym(const char);						//Set the symbol to a new given one


	const char getSymbol(void);						//Return the symbol of the entity
	const vector<Entity>* getBoard(void);			//Return a pointer to the board of the entity
	const vector<Entity>::iterator getPos(void);	//Return the position of the entity

};
#endif