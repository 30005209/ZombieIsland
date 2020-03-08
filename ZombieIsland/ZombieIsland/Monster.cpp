#include "Monster.h"

Monster::Monster()
{
	setSym('M');
}

Monster::~Monster()
{
}

void Monster::move(void)
{
}

void Monster::move(int)
{
}

void Monster::encounter(vector<Entity>::iterator other)
{
	switch (other->getSymbol())
	{
	case ' ':
		cout << "its an entity";
		break;


	case 'C':
		cout << "its a character";
		break;

	case 'O':
		cout << "its a hole";
		break;
	}
}
