#ifndef _Character
#define _Character

#include "Entity.h"
class Character :
	virtual public Entity
{

public:
	Character();
	~Character();

	int encounter(Entity *);
	bool getCanAmbush(void);
	void setCanAmbush(bool);

};
#endif