#ifndef BLOCK_P_H
#define BLOCK_P_H
#include "block.h"

// PERMANENT BLOCKS

class Block_P: public Block
{
public:
    Block_P(std::pair<int,int> position, std::pair<int,int> size);

};

#endif // BLOCK_P_H
