#include "GameManager.h"

GameManager::GameManager()
{
	setGridSize();
	setEntityNums();
	setControlScheme();
	setTurn(1);
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

void GameManager::setControlScheme(char newUp, char newDown, char newLeft, char newRight, char newAmb)
{
	this->up = newUp;
	this->left = newLeft;
	this->down = newDown;
	this->right = newRight;
	this->ambush = newAmb;
}

void GameManager::setTurn(int newTurn)
{
	turn = newTurn;
}

void GameManager::setFromDiffilculty(int diff)
{
	this->difficulty = diff;
	this->difficultyMod = diff * 2;
	mon = int((getRowNo() * getColNo()) / (10 - difficultyMod));
	hol = int((getRowNo() * getColNo()) / (15 - difficultyMod));
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

	for (int i = (getRowNo() * getColNo()) - mon - hol - cha; i > 0; i--)
	{
		addEntity();
	}

	difficultyMod++;
}

int GameManager::getRowNo(void)
{
	return this->rows;
}

int GameManager::getColNo(void)
{
	return this->cols;
}

int GameManager::getTurn(void)
{
	return this->turn;
}

int GameManager::getScore(void)
{
	return this->score;
}

int GameManager::getSpeedVar(void)
{
	return this->gameSpeedVar;
}

int GameManager::getSpeedBase(void)
{
	return this->gameSpeedBase;
}

string GameManager::getName(void)
{
	return this->name;
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

	for (vector<Entity*>::iterator i = board.begin();
		i != board.end(); i++)
	{
		{
			if ((*i)->getSymbol() == 'M')
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

char GameManager::getAmbush(void)
{
	return this->ambush;
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

	for (vector<Entity*>::iterator i = board.begin(); i != board.end(); i++)
	{
		if ((*i)->getSymbol() == 'C')
		{
			playerFound = true;
		}
	}
	return playerFound;
}

bool GameManager::isPlayerControl(char entry)
{
	return (entry == getUp() || entry == getDown()
		|| entry == getLeft() || entry == getRight()
		|| entry == getAmbush());
}


//Sleep by a dice roll which is the variance + a base speed
//To stop it being too slow/too long
void GameManager::randomSlow(void)
{
	Sleep(Die::roll(getSpeedVar()) + getSpeedBase());
}

//Randomly slow between each character in a given string
void GameManager::typeWrite(string text)
{
	for (int i = 0; i < int(text.length()); i++)
	{
		randomSlow();
		std::cout << text[i];
	}
}

void GameManager::addEntity(char symbol)
{
	static int codeCounter = 1;
	if (symbol == 'M')
	{
		board.emplace_back(new Monster());
	}
	else if (symbol == 'C')
	{
		board.emplace_back(new Character());
	}
	else if (symbol == 'O')
	{
		board.emplace_back(new Hole());
	}
	else 
	{
		board.emplace_back(new Entity(symbol));
	}
}

void GameManager::printBoard(void)
{
	con.setCursorPosition({ 0,0 });
	vector<Entity*>::iterator iterBoard = board.begin();

	cout << " ";

	for (int i = getColNo(); i > 0; i--)
	{
		cout << "_";
	}


	cout << "\n|";

	for (int i = 0; iterBoard != board.end(); iterBoard++, i++)
	{
		if (i != 0)
		{
			if (!(i % getColNo()))
			{
				cout << "|\n|";
			}

		}
		if ((*iterBoard)->getSymbol() == 'M')
		{
			con.setColour(Console::RED);
		}
		else if ((*iterBoard)->getSymbol() == 'C')
		{
			con.setColour(Console::GREEN);
		}
		cout << (*iterBoard)->getSymbol();

		con.setColour(Console::WHITE);
	}

	cout << "|";
}

void GameManager::randomiseBoard(void)
{
	con.clear();
	typeWrite("Now here's how I heard it went...");
	Sleep(500);

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
	else if (move == getRight())
	{
		direction = 1;
	}
	else if (move == getDown())
	{
		direction = 2;
	}
	else if (move == getLeft())
	{
		direction = 3;
	}
	else if (move == getAmbush())
	{
		if ((*player)->getCanAmbush())
		{
			if (!(isOnRowEdgeL(*player)))
			{
				(*(player - 1))->setSym('#');
			}

			if (!(isOnRowEdgeR(*player)))
			{
				(*(player + 1))->setSym('#');
			}
			if (!(isOnColEdgeT(*player)))
			{
				(*(player - getColNo()))->setSym('#');
			}
			if (!(isOnColEdgeB(*player)))
			{
				(*(player + getColNo()))->setSym('#');
			}
			(direction = -1);
			(*player)->setCanAmbush(false);
		}
		else
		{
			direction = Die::roll(4) - 1;
		}

	}


	//Find player
	for (vector<Entity*>::iterator i = board.begin();
		i != board.end(); i++)
	{
		if ((*i)->getSymbol() == 'C')
		{
			//Perform move in the given direction
			if (!(*i)->getHasChanged())
			{
				moveEntity(i, direction);
				(*i)->setChanged(true);
			}
		}
	}

}

void GameManager::performMonsterMoves(void)
{
	//Find Monster
	for (vector<Entity*>::iterator i = board.begin();
		i != board.end(); i++)
	{
		if ((*i)->getSymbol() == 'M')
		{
			//Perform move in a direction chosen by the entity
			if (!(*i)->getHasChanged())
			{
				decideEnemyMovement((*i)->getSelf());
				moveEntity(i);
				(*i)->setChanged(true);

			}
		}
	}

}


void GameManager::moveEntity(vector<Entity*>::iterator theEntity, int direction)
{
	if (direction != -1)
	{
		//If no value has been given decide based on the desires of the entity
		if (direction == 999)
		{
			direction = (*theEntity)->getPredomDesire();
		}
		
		Entity * encountered = (*theEntity);


		//If the direction would cause the entity to go off the edge the opposite direction is chosen
		if (isOnColEdgeT((*theEntity)) && direction == 0)
		{
			direction = 2;
		}
		else if (isOnColEdgeB((*theEntity)) && direction == 2)
		{
			direction = 0;
		}

		if (isOnRowEdgeL((*theEntity)) && direction == 3)
		{
			direction = 1;
		}
		else if (isOnRowEdgeR((*theEntity)) && direction == 1)
		{
			direction = 3;
		}

		//Decide what it is encountering
		switch (direction)
		{
			//Move Up
		case 0:
			//Set position to the position it is at - the total number of columns 
			encountered = (*(theEntity - this->getColNo()));
			break;

			//Move Right
		case 1:
			//Set position to the position it is at + the total number of columns
			encountered = (*(theEntity + 1));
			break;

			//Move Down
		case 2:
			//Set the position to the position before (-1)
			encountered = (*(theEntity + this->getColNo()));
			break;

			//Move Left
		case 3:
			//Set the potiion to the postion after (+1)
			encountered = (*(theEntity - 1));
			break;
		}


		encounter((*theEntity), encountered);
	}

}

bool GameManager::isOnRowEdgeR(Entity * looking)
{
	//return if the Entity is on the Left Edge
	return (getCol(looking) == getColNo() - 1);
}

bool GameManager::isOnRowEdgeL(Entity * looking)
{
	//return if the Entity is on the Right Edge
	return (getCol(looking) == 0);
}

bool GameManager::isOnColEdgeB(Entity * looking)
{
	//Return if the Entity is on the top row
	return (getRow(looking) == getRowNo() - 1);
}

bool GameManager::isOnColEdgeT(Entity * looking)
{
	//Return if the Entity is on the bottom row
	return (getRow(looking) == 0);
}

int GameManager::getPos(Entity * looking)
{
	int x = 0;

	//Loop through the entity to find where it is in the board
	for (vector<Entity*>::iterator pos = board.begin();
		pos != board.end();	pos++)
	{
		if (looking == (*pos)->getSelf())
		{
			return x;
		}
		x++;
	}

	//if not found return -1 as a sentiel
	return -1;
}

int GameManager::getRow(Entity *looking)
{
	int x = getPos(looking);
	int row = 0;

	//while x > the size of a row remove a row and increment the count
	while ((x - getRowNo()) >= 0)
	{
		x -= getRowNo();
		row++;
	}

	return row;
}

int GameManager::getCol(Entity *looking)
{
	int x = getPos(looking);

	//- the amount of the row until doing so would make the amound -ve
	while ((x - getRowNo()) >= 0)
	{
		x -= getRowNo();
	}

	return x;
}

void GameManager::decideEnemyMovement(Entity *current)
{
	//+ve is left, -ve is right
	//+ve is up, -ve is down
	(current)->setDesires(getCol(current) - getCol((*player)->getSelf()),
		getRow(current) - getRow((*player)->getSelf()));
}

void GameManager::enableMovement(void)
{
	for (vector<Entity*>::iterator i = board.begin();
		i != board.end(); i++)
	{
		if ((*i)->getSymbol() == '#')
		{
			(*i)->setSym(' ');
		}
		(*i)->setChanged(false);
	}
}

void GameManager::printScoreboard(void)
{
	updateInfo();
	cout << "\n";

	for (int i = getColNo() + 2; i > 0; i--)
	{
		cout << "=";
	}

	cout << "\n|Mons:  " << getRemMon();

	for (int i = getColNo() - con.getCursorPosition().X + 1;
		i > 0; i--)
	{
		cout << " ";
	}

	cout << "|\n|Turn:  " << getTurn();

	for (int i = getColNo() - con.getCursorPosition().X + 1;
		i > 0; i--)
	{
		cout << " ";
	}

	cout << "|\n|Kills: " << getScore();

	for (int i = getColNo() - con.getCursorPosition().X + 1;
		i > 0; i--)
	{
		cout << " ";
	}

	cout << "|\n|";

	if ((*player)->getCanAmbush())
	{
		con.setColour(con.GREEN);
		cout << "Ambush";
	}
	else
	{
		con.setColour(con.RED);
		cout << "Charging";
	}

	for (int i = getColNo() - con.getCursorPosition().X + 1;
		i > 0; i--)
	{
		cout << " ";
	}

	con.setColour(con.WHITE);

	cout << "|\n";
	for (int i = getColNo() + 2; i > 0; i--)
	{
		cout << "=";
	}

}

void GameManager::playTurn(void)
{
	bool change = false;
	bool doubleMove = (getTurn() & 2);


	//Get key
	char key = _getch();

	//Enable movement for everyone
	enableMovement();


	//else if its a player control
	if (isPlayerControl(key))
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
	for (vector<Entity*>::iterator i = board.begin(); i != board.end();
		i++)
	{
		if (!found)
		{
			if ((*i)->getSymbol() == ' ')
			{
				(*i)->setSym('M');
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

void GameManager::updateInfo(void)
{
	//Update positions of the player
	for (vector<Entity*>::iterator i = board.begin(); i != board.end(); i++)
	{
		if ((*i)->getSymbol() == 'C')
		{
			player = i;
		}

		if ((*i)->getSymbol() == '0')
		{
			score++;
			(*i)->setSym(' ');
			if (!(score % 5))
			{
				(*player)->setCanAmbush(true);
			}
		}
	}

}

void GameManager::encounter(Entity * theEntity, Entity * encountered)
{
	char theEnt = theEntity->getSymbol();
	char enc = encountered->getSymbol();
	enum { swap, die, kill, fall, dieWP };


	int result = theEntity->encounter(encountered);
	switch (result)
	{
	case swap:
		swapEnts(theEntity, encountered);
		break;

	case die:
		theEntity->setSym('X');
		break;

	case kill:
		encountered->setSym('X');
		break;

	case fall:
		theEntity->setSym(' ');
		break;

	case dieWP:
		score++;
		theEntity->setSym('0');
		break;
	}

	theEntity->setChanged(true);
	encountered->setChanged(true);

}

void GameManager::swapEnts(Entity *source, Entity *other)
{
	//If this is a monster...
	if (source->getSymbol() == 'M')
	{
		//Decide behaviour based on what its encountering
		switch (other->getSymbol())
		{
			//If its a blank space swap them
		case ' ':
			std::swap(*source, *other);
			source->setChanged(true);
			other->setChanged(true);
			break;

			//If its a hole kill self
		case 'O':
			source->setSym(' ');
			source->setChanged(true);
			break;

			//If its a monster do nothing (can be seen as swapping or bouncing off)
		case 'M':
			break;

			//If its the player kill the player
		case 'C':
			other->setSym('X');
			other->setChanged(true);
			break;

		case '#':
			source->setSym(' ');
			other->setSym('0');
			source->setChanged(true);
		}
	}

	//If this is the player...
	else if (source->getSymbol() == 'C')
	{

		//Decide behaviour based on what its encountering
		switch (other->getSymbol())
		{
			//If its a blank space swap them
		case ' ':
			std::swap(*source, *other);
			source->setSym('#');
			source->setChanged(true);
			other->setChanged(true);
			break;

			//If its a hole kill self
		case 'O':
			source->setSym(' ');
			source->setChanged(true);
			break;

			//If its a monster kill self
		case 'M':
			source->setSym('X');
			source->setChanged(true);
			break;
		}
	}
	else
	{

	}

}

void GameManager::setUp(void)
{
	bool gameSet = false;

	while (!gameSet)
	{
		getCon().setWindowSize(600, 450);
		getCon().setWindowTitle("Zombie Island");
		getCon().clear();

		bool custom = false;
		bool chosen = false;

		typeWrite("Welcome to Zombie Island\n");
		typeWrite("Press Enter to begin...");
		cin.get();
		con.clear();

		int tempRow = -1;
		int tempCol = -1;

		while (!chosen)
		{
			bool decided = false;
			int distance = -1;
			while (!decided)
			{

				typeWrite("Lets start with the basics...\nHow far are you traveling?\n");
				typeWrite("1. Only round the block [10 x 10]\n");
				typeWrite("2. Supermarket's not far [15 x 15]\n");
				typeWrite("3. Be back before dark [20 x 20]\n");
				typeWrite("4. Business is my own [10-20 x 10-20]\n");

				cin >> distance;

				while (!cin >> distance || distance >4 || distance <=0)
				{
					typeWrite("C'mon speak up...\n");
					cin.clear();
					cin.ignore(123, '\n');
					cin >> distance;
				}

				if (distance == 1 || distance == 2
					|| distance == 3 || distance == 4)
				{
					decided = true;
				}
			}
			switch (distance)
			{
			case 1:
				tempRow = 10;
				tempCol = 10;
				chosen = true;
				break;

			case 2:
				tempRow = 15;
				tempCol = 15;
				chosen = true;
				break;

			case 3:
				tempRow = 20;
				tempCol = 20;
				chosen = true;
				break;

			case 4:
				custom = true;
				chosen = true;
				break;

			default:
				cin.ignore();
				break;
			}
		}

		//Custom 
		if (custom)
		{
			bool validRow = false;
			while (!validRow)
			{
				typeWrite("How far east are you planning\n");
				
				cin >> tempRow;

				while (!cin >> tempRow || tempRow > 20 || tempRow < 10)
				{
						typeWrite("What was that?\n");
						cin.clear();
						cin.ignore(123, '\n');
						cin >> tempRow;
				}
	
				cin >> tempRow;
				validRow = (tempRow >= 10 && tempRow <= 20);
			}

			bool validCol = false;

			while (!validCol)
			{
				typeWrite("How far south are you going?\n");

				cin >> tempCol;
				while (!cin >> tempCol || tempCol > 20 || tempCol < 10)
				{
					typeWrite("I'm sorry...what did you say?\n");
					cin.clear();
					cin.ignore(123, '\n');
					cin >> tempCol;
				}

				validCol = (tempCol >= 10 && tempCol <= 20);
			}
		}

		bool validDifficulty = false;
		int tempDif = -1;
		while (!validDifficulty)
		{
			getCon().clear();
			typeWrite("There many of them out there?\n");
			typeWrite("1. Not so many\n");
			typeWrite("2. More than usual...\n");
			typeWrite("3. I reckon the whole horde...\n");

			cin >> tempDif;

			while (!cin >> tempDif || tempDif > 3 || tempDif < 1)
			{
				typeWrite("How many...?\n");
				cin.clear();
				cin.ignore(123, '\n');
				cin >> tempDif;
			}

			validDifficulty = (tempDif == 1 || tempDif == 2 || tempDif == 3);
		}

		con.clear();
		bool validName = false;
		name = "-1";
		while (!validName)
		{
			if (name != "-1")
			{
				typeWrite("Now don't give me ya whole name\njust a nickname'll do\n");
				cin.ignore();
				cin.clear();
			}
			typeWrite("Before you go...what dyou go by?\nJust so I know what to tell passers-by\n");
			cin >> name;

			validName = name.size() <= 10;
			getCon().clear();
		}

		typeWrite("[w] for forward, [s] for back,\n[a] for left and [d] for right\n");
		typeWrite("Standard stuff but watch out for thoses holes\n[O] they'll swallow you up\n");
		Sleep(500);
		getCon().clear();
		typeWrite("and if one of those zombies [M] dagets a wiff\n-they'll chase you till they get you!\n");
		Sleep(500);
		getCon().clear();
		typeWrite("One last thing remember you can set a trap with [q]\n");
		Sleep(1000);
		getCon().clear();
		typeWrite("It'll make the floor weak [#] all round you \n- perfect for making them fall\n");
		Sleep(800);
		getCon().clear();
		typeWrite("Can't do it too often mind,\nbut remeber the floor's weak behind you\nso they'll fall through that too!");
		Sleep(500);
		typeWrite("\nGet enough of them falling through your [#]'s\nand your ambush will be green and ready to go\n");
		Sleep(500);
		getCon().clear();
		setGridSize(tempRow, tempCol);
		setFromDiffilculty(tempDif);
		gameSet = true;
		randomiseBoard();

		getCon().clear();
		updateInfo();
	}
	printBoard();
	printScoreboard();
}
