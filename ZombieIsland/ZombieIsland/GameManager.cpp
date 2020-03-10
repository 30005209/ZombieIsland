#include "GameManager.h"

typedef vector<Entity>::iterator Position;

GameManager::GameManager()
{
	setGridSize();
	setEntityNums();
	setControlScheme();

	for (int i = mon; i > 0; i--)
	{
		addEntity(Monster());
	}

	for (int i = hol; i > 0; i--)
	{
		addEntity(Hole());
	}

	for (int i = cha; i > 0; i--)
	{
		addEntity(Character());
	}

	for (int i = (getRow() * getCol()) - mon - hol - cha; i > 0; i--)
	{
		addEntity();
	}

	randomiseBoard();
}

GameManager::GameManager(int row, int col, int mon, int hol, int cha, string controls)
{
	setGridSize(row, col);
	setEntityNums(mon, hol, cha);
	setControlScheme(controls[0], controls[1], controls[2], controls[3]);

	for (int i = mon; i > 0; i--)
	{
		addEntity(Monster());
	}

	for (int i = hol; i > 0; i--)
	{
		addEntity(Hole());
	}

	for (int i = cha; i > 0; i--)
	{
		addEntity(Character());
	}

	for (int i = (getRow() * getCol()) - mon - hol - cha; i > 0; i--)
	{
		addEntity();
	}

	randomiseBoard();	
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
	int numRemaining = 0;

	for (vector<Entity>::iterator i = board.begin(); 
		i != board.end(); i++)
	{
		numRemaining += i->getIsAlive();
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

bool GameManager::isGameOver(void)
{
	return getRemMon();
}

void GameManager::addEntity(Entity newEntity)
{
	static int codeCounter = 1;
	newEntity.setCode(codeCounter++);
	board.emplace_back(newEntity);

}

void GameManager::printBoard(void)
{
	vector<Entity>::iterator iterBoard = board.begin();

	for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
	{
		if (i != 0)
		{
			if (!(i % getCol()))
			{
				cout << endl;
			}
		}
		cout << iterBoard->getSymbol();
		iterBoard->setPos(iterBoard);
	}
}

void GameManager::randomiseBoard(void)
{
	for (int i = Die::roll(); i > 0; i--)
	{
		std::random_shuffle(board.begin(), board.end());
	}

}
