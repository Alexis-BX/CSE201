#pragma once
#include "collectibles.h"

class Coin : public Collectibles
{
public:
	Coin(pr position, pr size, enum state);

	void Value(pr size);
};