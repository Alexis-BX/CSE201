#include "collectibles.h"


Collectibles::Collectibles(pr position, pr size, char st) : Dead(position,size)
{
	state = st;
}

void Collectibles::Coll_state(char st)
{
	state = st;
	if (state == "Unused")
	{
		state = "Used";
	}
}

bool Collectibles::Pass_by(char st)
{
	if (Collectibles::Coll_state(char st) == "Used")
	{
		return true;
	}
	else
	{
		return false;
	}
}
