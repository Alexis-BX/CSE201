#ifndef BLOCK_ALI_H
#define BLOCK_ALI_H
#include "block.h"

class Block_Ali : public Block
{
public:
    Block_Ali(std::pair<int,int> position, std::pair<int,int> size, int health);
    int health;
};

#endif // BLOCK_ALI_H
