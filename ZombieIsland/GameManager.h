#ifndef _GameManager
#define _GameManager

#include <conio.h>
#include <iostream>
#include "console.h"
#include "Entity.h"
#include "Die.h"
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class GameManager
{
private:
	
	//To help legibility Position will be used when refering to the board
	typedef vector<Entity>::iterator Position;

	Console con;	//The Console class

	vector<Entity> board;	//The Board being played on

	int rows;				//No. rows on the board at game start
	int cols;				//No. columns on the board at game start
							
	int mon;				//Number of Monster/game start No.
	int hol;				//Number of Holes/game start No.
	int cha;				//Number of Characters/game start No.
							
	char up;				//Keybind for up
	char down;				//Keybind for down
	char left;				//Keybind for left
	char right;				//Keybind for right


public:
	GameManager();
	~GameManager();

	//Setters
	void setGridSize(int numRow = 10, int numCol = 10);										//Set the size of the rows and columns on the board
	void setEntityNums(int numMon = 10, int numHole = 10, int numCha = 1);					//Set the number of monster, holes and characters
	void setControlScheme(char newUp = 'w', char newDown = 's',								//Set the control scheme for the player
						char newLeft = 'a', char newRight = 'd');


	int getRow(void);										//Get the row size
	int getCol(void);										//Get the column size

	int getNumMon(void);									//Get the number of monsters
	int getNumHol(void);									//Get the number of Holes
	int getNumCha(void);									//Get the number of Player characters

	int getRemMon(void);									//Gets how many remaining monsters there are

	char getUp(void);										//Get the currently mapped control for up
	char getDown(void);										//Get the currently mapped control for down
	char getLeft(void);										//Get the currently mapped control for left
	char getRight(void);									//Get the currently mapped control for right

	Console & getCon(void);									//Gets the console


	//Other functions

	bool isGameOver(void);									//Is the game over
	bool isPlayerControl(char);								//Check if its a control for the player
	bool isGameControl(char);								//Check if its a game control


	void addEntity(char symbol = ' ');						//Adds a new entity with the given symbol - default of " " for space
	
	void printBoard(void);									//Print the entire board to console
	void randomiseBoard(void);								//Randomise the board a d6 number of times

	void performPlayerMoves(char);							//Performs all the moves for Players
	void performMonsterMoves(void);							//Performs all the moves for Monsters

};

#endif