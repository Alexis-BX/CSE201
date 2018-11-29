#include "collectable.h"


Collectable::Collectable(pair position, pair size, Collectable_state state, Collectable_type type):  // constructor: inherits position from the Dead class and gives the type and the state of the collectable 
      Dead(position, size)
{
	this->state = state;

	this->type = type;

}
/**
void Collectibles::Coll_state(enum st)
{
	state = st;
	if (state == "Unused")
	{
		state = "Used";
	}
}

bool Collectibles::Pass_by(enum st)
{
	if (Coll_state(st) == "Used")
	{
		return true;
	}
	else
	{
		return false;
	}
>>>>>>> a9ac4fb338b8d1131064a9c93d7b190498c2e9d3
}
**/
