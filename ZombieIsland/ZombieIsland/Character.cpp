#include "Character.h"

Character::Character()
{
	setSym('C');
}

Character::~Character()
{
}

void Character::move(int input)
{
	setSym(input);

	hasChanged = true;
}

void Character::encounter(Entity other)
{
	switch (other.getSymbol())
	{
	case ' ':
		cout << "its an entity";
		break;


	case 'M':
		cout << "its a monster";
		break;

	case 'O':
		cout << "its a hole";
		break;
	}

}
