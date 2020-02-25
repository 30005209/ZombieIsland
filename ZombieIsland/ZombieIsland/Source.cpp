#include <iostream>
#include <string>
#include "Character.h"
#include "Monster.h"
#include "Hole.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	Entity ent;
	Monster mons;
	Character cha;
	Hole ho;



	cha.encounter(mons);
	std::cout << endl;

	cha.encounter(ent);
	std::cout << endl;

	cha.encounter(ho);
	std::cout << endl;


	mons.encounter(cha);
	std::cout << endl;

	cha.encounter(ent);
	std::cout << endl;

	cha.encounter(ho);
	std::cout << endl;

	cin.ignore();
	cin.get();

	return 0;
}