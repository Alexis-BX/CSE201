#ifndef BLOCKS_H
#define BLOCKS_H
#include "block.h"

class Base_block: public Block
{
public:
    Base_block(pair position, QGraphicsItem* parent = nullptr);
};

class Breakable_block_1: public Block
{
public:
    Breakable_block_1(pair position, QGraphicsItem* parent = nullptr);
};

class Breakable_block_2: public Block
{
public:
    Breakable_block_2(pair position, QGraphicsItem* parent = nullptr);
};

class Breakable_block_3: public Block
{
public:
    Breakable_block_3(pair position, QGraphicsItem* parent = nullptr);
};


class Active_block: public Block
{
public:
    Active_block(pair position, QGraphicsItem* parent = nullptr);
};


class Special_block_above: public Block
{
public:
    Special_block_above(pair position, QGraphicsItem* parent = nullptr);
};


class Special_block_below: public Block
{
public:
    Special_block_below(pair position, QGraphicsItem* parent = nullptr);
};

class Activated_block: public Block
{
public:
    Activated_block(pair position, QGraphicsItem* parent = nullptr);
};

class End_block: public Block
{
public:
    End_block(pair position, QGraphicsItem* parent = nullptr);
};

class Tube_block: public Block
{
public:
    Tube_block(pair position, QGraphicsItem* parent = nullptr);
};

#endif // BLOCKS_H
