#include "collectibles.h"


Collectibles::Collectibles(pr position, pr size, enum st) : Dead(position,size)
{
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
}
