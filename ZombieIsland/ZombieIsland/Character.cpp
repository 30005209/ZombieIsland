#include "Character.h"
#include <conio.h>

Character::Character()
{
	setSym('C');
}

Character::~Character()
{
}

void Character::taketurn(void)
{
}

void Character::move(int direction = Die::roll(4))
{
	setSym(direction);
}
