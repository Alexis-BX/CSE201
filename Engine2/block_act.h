#ifndef BLOCK_Act_H
#define BLOCK_Act_H
#include "block.h"

// ACTIVE BLOCKS

class Block_Act : public Block
{
public:
    Block_Act(std::pair<int,int> position, std::pair<int,int> size, char state);
    char state;

};

#endif // BLOCK_Act_H
