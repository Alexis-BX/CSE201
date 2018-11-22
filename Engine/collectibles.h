#include "dead.h"
#pragma once

class Collectibles: public Dead
{
public:

    Collectibles(pair position, pair size, State state);

	bool Coll_state(enum st);

	bool Pass_by(enum st);
};
