#include "block_act.h"

// ACTIVE BLOCKS
Block_Act::Block_Act(std::pair<int,int> position, std::pair<int,int> size, char state) : Block(position, size)
{
    this->state = state;
}

