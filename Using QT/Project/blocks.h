#ifndef BLOCKS_H
#define BLOCKS_H
#include "block.h"

class Base_block: public Block
{
public:
    Base_block(pair position);
};


class Breakable_block: public Block
{
public:
    Breakable_block(pair position);
};


class Active_block: public Block
{
public:
    Active_block(pair position);
};


class Special_block_above: public Block
{
public:
    Special_block_above(pair position);
};


class Special_block_below: public Block
{
public:
    Special_block_below(pair position);
};

#endif // BLOCKS_H
