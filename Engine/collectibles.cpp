#include "collectibles.h"


Collectibles::Collectibles(pr position, pr size, enum st) : Dead(position,size)
{
<<<<<<< HEAD
    state = st;
=======
	state = st;
}

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
