#pragma once
#include "collectibles.h"

class Coin : public Collectibles
{
public:
	Coin(std::pair<int,int> position, std::pair<int,int> size, char state);

	void Value(std::pair<int, int> size);
};