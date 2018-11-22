#include "dead.h"
#pragma once

class Collectibles: public Dead
{
public:

	enum state;

	Collectibles(pr position, pr size, enum st);

	bool Coll_state(enum st);

	bool Pass_by(enum st);
};