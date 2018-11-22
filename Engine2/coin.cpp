#include "coin.h"

Coin::Coin(std::pair<int, int> position, std::pair<int, int> size, char state) : Collectibles(position, size, state)
{
	
}

void Coin::Value(std::pair<int, int> size)
{
	if (size[0] * size[1] <= 2)
	{
		std::cout << "Value of 3" << std::endl;
	}

	if (size[0] * size[1] <= 6)
	{
		std::cout << "Value of 7" << std::endl;
	}
	else
	{
		std::cout << "Value of 13" << std::endl;
	}
}