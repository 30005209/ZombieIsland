#include "Character.h"
#include <conio.h>

Character::Character()
{
	setSym('C');
}

Character::~Character()
{
}

void Character::taketurn(char input)
{
	move(int(input));
}

void Character::move(int direction = Die::roll(4))
{
	setSym(direction);
}
