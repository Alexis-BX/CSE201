#include "coin.h"

Coin::Coin(pr position, pr size, enum state) : Collectibles(position, size, state)
{
	
}

void Coin::Value(pr size)
{
	if (pr.x * pr.y <= 2)
	{
		std::cout << "Value of 3" << std::endl;
	}

	if (pr.x * pr.y <= 6)
	{
		std::cout << "Value of 7" << std::endl;
	}
	else
	{
		std::cout << "Value of 13" << std::endl;
	}
}