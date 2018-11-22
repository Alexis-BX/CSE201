#include "collectibles.h"


Collectibles::Collectibles(std::pair<int,int> position, std::pair<int,int> size, char st) : Dead(position,size)
{
    state = st;
}
