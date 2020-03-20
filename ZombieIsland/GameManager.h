#ifndef _GameManager
#define _GameManager

#include <conio.h>
#include <iostream>
#include "console.h"
#include "Entity.h"
#include "Monster.h"
#include "Character.h"
#include "Hole.h"
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

	Console con;			//The Console class

	vector<Entity*> board;	//The Board being played on

	vector<Entity*>::iterator player;

	int rows;				//No. rows on the board at game start
	int cols;				//No. columns on the board at game start
							
	int mon;				//Number of Monster/game start No.
	int hol;				//Number of Holes/game start No.
	int cha;				//Number of Characters/game start No.
							
	char up;				//Keybind for up
	char down;				//Keybind for down
	char left;				//Keybind for left
	char right;				//Keybind for right
	char ambush;			//Keybind for ambush

	//Base typing speed
	int gameSpeedBase = 90;

	//How much the typing speed can vary by
	int gameSpeedVar = 30;


	int turn;
	int score;
	int difficulty;
	int difficultyMod;
	string name;

public:
	GameManager();
	~GameManager();

	//Setters
	void setGridSize(int numRow = 20, int numCol = 40);										//Set the size of the rows and columns on the board
	void setEntityNums(int numMon = 50, int numHole = 30, int numCha = 1);					//Set the number of monster, holes and characters
	void setControlScheme(char newUp = 'w', char newDown = 's',								//Set the control scheme for the player
						char newLeft = 'a', char newRight = 'd',
						char newAmb = 'q');

	void setTurn(int);
	void setFromDiffilculty(int);


	//Randomly slow down text
	void randomSlow(void);

	//Write a given string in the "typwriter" fashion
	void typeWrite(string);

	//Getters

	int getRowNo(void);										//Get the row size
	int getColNo(void);										//Get the column size
	int getTurn(void);										//Gets the number of turns
	int getScore(void);										//Gets the score
	int getSpeedVar(void);
	int getSpeedBase(void);
	string getName(void);

	int getNumMon(void);									//Get the number of monsters
	int getNumHol(void);									//Get the number of Holes
	int getNumCha(void);									//Get the number of Player characters


	int getRemMon(void);									//Gets how many remaining monsters there are

	char getUp(void);										//Get the currently mapped control for up
	char getDown(void);										//Get the currently mapped control for down
	char getLeft(void);										//Get the currently mapped control for left
	char getRight(void);									//Get the currently mapped control for right
	char getAmbush(void);									//Get the currently mapped control for ambush


	Console & getCon(void);									//Gets the console


	//Other functions

	bool monstersRemain(void);								//Is the game over
	bool playerIsAlive(void);								//Checks if a player is on the board
	bool isPlayerControl(char);								//Check if its a control for the player


	void addEntity(char symbol = ' ');						//Adds a new entity with the given symbol - default of " " for space
	
	void printBoard(void);									//Print the entire board to console
	void randomiseBoard(void);								//Randomise the board a d6 number of times


	void performPlayerMoves(char);							//Performs all the moves for Players
	void performMonsterMoves(void);							//Performs all the moves for Monsters

	void moveEntity(vector<Entity*>::iterator,int = 999);	//Performs a movement action for the given entity in the given direction

	bool isOnRowEdgeL(Entity*);								//Returns whether the entity is on the left edge  
	bool isOnRowEdgeR(Entity*);								//Returns whether the entity is on the right edge  
	bool isOnColEdgeT(Entity*);								//Returns whether the entity is on the left edge
	bool isOnColEdgeB(Entity*);								//Returns whether the entity is on the right edge


	int getPos(Entity*);									//Finds the current position of the given entity
	int getRow(Entity*);									//Finds the current row of the given entity
	int getCol(Entity*);									//Finds the current col of the given entity

	void decideEnemyMovement(Entity*);						//If within 

	void enableMovement(void);

	void printScoreboard(void);

	void playTurn(void);
	
	void addMonster(void);

	void increaseDif(void);

	void updateInfo(void);										//Updates the info held by Game Manager

	void encounter(Entity*, Entity*);

	void swapEnts(Entity*, Entity*);
	
	void setUp(void);
};

#endif
