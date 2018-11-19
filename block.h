#ifndef BLOCK_H
#define BLOCK_H
#include <utility>
#include "dead.h"

class Block: public Dead
{
public:
    Block(std::pair<int,int> position, std::pair<int,int> size);

};

#endif // BLOCK_H
