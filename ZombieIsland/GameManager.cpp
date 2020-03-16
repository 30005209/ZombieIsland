#include "GameManager.h"

typedef vector<Entity>::iterator Position;

GameManager::GameManager()
{
	setGridSize();
	setEntityNums();
	setControlScheme();

	setTurn(1);

	randomiseBoard();
}

GameManager::~GameManager()
{
}

void GameManager::setGridSize(int numRow, int numCol)
{
	this->rows = numRow;
	this->cols = numCol;
}

void GameManager::setEntityNums(int numMon, int numHol, int numCha)
{
	this->mon = numMon;
	this->hol = numHol;
	this->cha = numCha;
}

void GameManager::setControlScheme(char newUp, char newDown ,char newLeft, char newRight)
{
	this->up = newUp;
	this->left = newLeft;
	this->down = newDown;
	this->right = newRight;
}

void GameManager::setTurn(int newTurn)
{
	turn = newTurn;
}

void GameManager::setFromDiffilculty(int diff)
{
	this->difficulty = diff;
	this->difficultyMod = diff * 2;
	mon = int((getRow() * getCol()) /  (10 - difficultyMod));
	hol = int((getRow() * getCol()) / (15 - difficultyMod));
	cha = 1;

	for (int i = mon; i > 0; i--)
	{
		addEntity('M');
	}

	for (int i = hol; i > 0; i--)
	{
		addEntity('O');
	}

	for (int i = cha; i > 0; i--)
	{
		addEntity('C');
	}

	for (int i = (getRow() * getCol()) - mon - hol - cha; i > 0; i--)
	{
		addEntity();
	}

	difficultyMod++;
}

int GameManager::getRow(void)
{
	return this->rows;
}

int GameManager::getCol(void)
{
	return this->cols;
}

int GameManager::getTurn(void)
{
	return this->turn;
}

int GameManager::getNumMon(void)
{
	return this->mon;
}

int GameManager::getNumHol(void)
{
	return this->hol;
}

int GameManager::getNumCha(void)
{
	return this->cha;
}

Entity * GameManager::getEntity(Position givenPos)
{
	return givenPos->getSelf();
}

vector<Entity>* GameManager::getBoard()
{
	return &board;
}

int GameManager::getRemMon(void)
{
	int numRemaining = 0;
	
	for (Position i = board.begin();
		i != board.end(); i++)
	{
		{
			if (i->getSymbol() == 'M')
			{
				numRemaining++;
			}
		}
	}
	
	return numRemaining;
}

char GameManager::getUp(void)
{
	return this->up;
}

char GameManager::getDown(void)
{
	return this->down;
}

char GameManager::getLeft(void)
{
	return this->left;
}

char GameManager::getRight(void)
{
	return this->right;
}

Console & GameManager::getCon(void)
{
	return con;
}

bool GameManager::monstersRemain(void)
{
	return (getRemMon() > 0);
}

bool GameManager::playerIsAlive(void)
{
	bool playerFound = false;

	for (Position checkPoint = board.begin(); checkPoint != board.end(); checkPoint++)
	{
		if (checkPoint->getSymbol() == 'C')
		{
			playerFound = true;
		}
	}
	return playerFound;
}

bool GameManager::isPlayerControl(char entry)
{
	return (entry == getUp() || entry == getDown()
		|| entry == getLeft() || entry == getRight());
}

bool GameManager::isGameControl(char key)
{
	return false; //(key == getUp() || key == getDown() || key == getLeft() || key == getRight());
	
}


void GameManager::addEntity(char symbol)
{	
	static int codeCounter = 1;
	Entity newEntity(symbol);
	board.emplace_back(newEntity);   
}

void GameManager::printBoard(void)
{
	con.setCursorPosition({ 0,0 });
	vector<Entity>::iterator iterBoard = board.begin();
	
	cout << " ";

	for (int i = getCol(); i > 0; i--)
	{
		cout << "_";
	}

	
	cout << "\n|";

	for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
	{
		if (i != 0)
		{
			if (!(i % getCol()))
			{
				cout << "|\n|";
			}

		}
		if (iterBoard->getSymbol() == 'M')
		{
			con.setColour(Console::RED);
		}
		else if (iterBoard->getSymbol() == 'C')
		{
			con.setColour(Console::GREEN);
		}
		cout << iterBoard->getSymbol();

		con.setColour(Console::WHITE);
	}

	cout << "|";
}

void GameManager::randomiseBoard(void)
{
	for (int i = Die::roll(); i > 0; i--)
	{
		std::random_shuffle(board.begin(), board.end());
	}
}

void GameManager::performPlayerMoves(char move)
{
	////Convert the movement char into a direction
	int direction;
	
	if (move == getUp())
	{
		direction = 0;
	}
	else if (move == getDown())
	{
		direction = 1;
	}
	else if (move == getLeft())
	{
		direction = 2;
	}
	else if (move == getRight())
	{
		direction = 3;
	}
	
	
	//Find player
	for (Position i = board.begin();
		i != board.end(); i++)
	{
		if (i->getSymbol() == 'C')
		{
			//Perform move in the given direction
			if (!i->getHasChanged())
			{
				moveEntity(i->getSelf(), direction);
				i->setChanged(true);
			}
		}
	}
	
}

void GameManager::performMonsterMoves(void)
{
	//Find player
	for (vector<Entity>::iterator i = board.begin();
		i != board.end(); i++)
	{
		if (i->getSymbol() == 'M')
		{
			//Perform move in the given direction
			if (!i->getHasChanged())
			{
				moveEntity(i->getSelf(), Die::roll(4)-1);
				i->setChanged(true);
			}
		}
	}
   
}


void GameManager::moveEntity(Entity* theEntity, int direction)
{
	Entity * encountered = theEntity;

	//Decide what it is encountering
	switch (direction)
	{
	//Move Up
	case 0:
		//Set position to the position it is at - the total number of columns 
		encountered = (theEntity - this->getCol());
		break;

	//Move Down
	case 1:
		//Set position to the position it is at + the total number of columns
		encountered = (theEntity + this->getCol());
		break;

	//Move Left
	case 2:
		//Set the position to the position before (-1)
		encountered = (theEntity -1);
		break;

	//Move Right
	case 3:
		//Set the potiion to the postion after (+1)
		encountered = (theEntity +1);
		break;
	}
	
	theEntity->encounter(encountered);
}

void GameManager::enableMovement(void)
{
	for (Position i = board.begin();
		i != board.end(); i++)
	{
		if (i->getSymbol() == '#')
		{
			i->setSym(' ');
		}
		i->setChanged(false);
	}
}

void GameManager::printScoreboard(void)
{
	cout << "\n";

	for (int i = getCol()+2; i > 0; i--)
	{
		cout << "=";
	}

	cout << "\n|Mons: " << getRemMon();

	for (int i = getCol() - con.getCursorPosition().X +1;
		i > 0; i--)
	{
		cout << " ";
	}

	cout << "|\n|Turn: " << getTurn();

	for (int i = getCol() - con.getCursorPosition().X + 1;
		i > 0; i--)
	{
		cout << " ";
	}

	cout << "|\n";

	for (int i = getCol()+2; i > 0; i--)
	{
		cout << "=";
	}

}

void GameManager::playTurn(void)
{
	bool change = false;
	//Get key
	char key = _getch();
	
	//Enable movement for everyone
	enableMovement();

	//if its a game control
	if (isGameControl(key))
	{

	}
	//else if its a player control
	else if (isPlayerControl(key))
	{
		performPlayerMoves(key);
		performMonsterMoves();
		change = true;
		key = ' ';
	}

	//Randomise the board
	if (key == 'r')
	{
		randomiseBoard();
		change = true;
	}

	if (change)
	{

		if (!(getTurn() % 20))
		{
			increaseDif();
		}

		setTurn(getTurn() + 1);

		printBoard();
		printScoreboard();
	}
}

void GameManager::addMonster(void)
{
	bool found = false;
	//Find the first empty slot and change to a monster
	for (Position i = board.begin(); i != board.end();
		i++)
	{
		if (!found)
		{
			if (i->getSymbol() == ' ')
			{
				i->setSym('M');
				found = true;
			}
		}
	}
}

void GameManager::increaseDif(void)
{
	for (int i = difficulty + difficultyMod; i > 0;
		i--)
	{
		addMonster();
	}
}
