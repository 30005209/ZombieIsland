#include "GameManager.h"

typedef vector<Entity>::iterator Position;

GameManager::GameManager()
{
	setGridSize();
	setEntityNums();
	setControlScheme();

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
	return this->cols;
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
	
	for (Position i = board.begin();
		i != board.end(); i++)
	{
		//if (i->getIsAlive())
		{
			numRemaining++;
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

bool GameManager::isGameOver(void)
{
	return !getRemMon();
}

bool GameManager::isPlayerControl(char entry)
{
	return (entry == getUp() || entry == getDown()
		|| entry == getLeft() || entry == getRight());
}

bool GameManager::isGameControl(char)
{
	return false;
}


void GameManager::addEntity(char symbol)
{	
	static int codeCounter = 1;
	Entity newEntity(symbol);
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

void GameManager::performPlayerMoves(char move)
{
	////Convert the movement char into a direction
	//int direction;
	//
	//if (move == getUp())
	//{
	//	direction = 1;
	//}
	//else if (move == getLeft())
	//{
	//	direction = 2;
	//}
	//else if (move == getDown())
	//{
	//	direction = 3;
	//}
	//else if (move == getRight())
	//{
	//	direction = 4;
	//}
	//
	//
	////Find player
	//for (vector<Entity>::iterator i = board.begin();
	//	i != board.end(); i++)
	//{
	//	if (i->getSymbol() == 'C')
	//	{
	//		//Character *T =&board[3];
	//
	//		//Convert the move into the direction then move that way
	//
	//		/*Character(i).move(direction);*/
	//
	//
	//	}
	//}
	//
	////Perform their actions
}

void GameManager::performMonsterMoves(void)
{
}
