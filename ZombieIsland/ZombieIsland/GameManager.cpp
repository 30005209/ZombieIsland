#include "GameManager.h"

typedef vector<Entity>::iterator Position;

GameManager::GameManager()
{
	setGridSize();
	setEntityNums();
	setControlScheme();

	while (sizeof(monsters) != mon)
	{
		addEntity(Monster());
	}

	while (sizeof(holes) != hol)
	{
		addEntity(Hole());
	}

	while (sizeof(characters) != cha)
	{
		addEntity(Character());
	}
}


GameManager::~GameManager()
{
}

void GameManager::setGridSize(int numRow, int numCol)
{
	this->rows = numRow;
	this->columns = numCol;
}

void GameManager::setEntityNums(int numMon, int numHol, int numCha)
{
	this->mon = numMon;
	this->hol = numHol;
	this->cha = numCha;
}

void GameManager::setControlScheme(char newUp, char newLeft, char newDown, char newRight)
{
	this->up = newUp;
	this->left = newLeft;
	this->down = newDown;
	this->right = newRight;

}

int GameManager::getRow(void)
{
	return this->rows;
}

int GameManager::getCol(void)
{
	return this->columns;
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

int GameManager::getRemMon(void)
{
	return sizeof(monsters);
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

bool GameManager::isBoardSet(void)
{
	return this->isSet;
}

bool GameManager::isGameOver(void)
{
	return sizeof(monsters) == 0;
}

void GameManager::addEntity(Entity newEntity, Position newPos)
{
	//If the space is blank addd it to that tile
	if (newPos->getSymbol() == '#')
	{
		newEntity.setPos(newPos);
	}

	//Otherwise add it to the first free space
	else
	{
		Position newPos = board.begin();
		bool lookingForPos = true;
		//Add it to the first unoccupied space on the board
		while (lookingForPos)
		{
			if (newPos->getSymbol() == '#')
			{
				newEntity.setPos(newPos);
				lookingForPos = false;
			}
			else
			{
				newPos++;
			}
		}
	}

	//ADD TO vector
}
