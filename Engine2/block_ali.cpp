#include "block_ali.h"

Block_Ali::Block_Ali(std::pair<int,int> position, std::pair<int,int> size, int health) : Block(position, size)
{
    this->health = health;

}
