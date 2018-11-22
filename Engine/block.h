#ifndef BLOCK_H
#define BLOCK_H
#include "dead.h"

class Block: public Dead
{
public:
    Block(pair position, pair size, State state);

};

#endif // BLOCK_H
