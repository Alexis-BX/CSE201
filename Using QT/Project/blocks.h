#ifndef BLOCKS_H
#define BLOCKS_H
#include "block.h"

class Base_block: public Block
{
public:
    Base_block(pair position, QGraphicsItem* parent = 0);
};


<<<<<<< HEAD
class Breakable_block_1: public Block
{
public:
    Breakable_block_1(pair position, QGraphicsItem* parent = 0);
};

class Breakable_block_2: public Block
{
public:
    Breakable_block_2(pair position, QGraphicsItem* parent = 0);
};

class Breakable_block_3: public Block
{
public:
    Breakable_block_3(pair position, QGraphicsItem* parent = 0);
=======
class Breakable_block: public Block
{
public:
    Breakable_block(pair position, QGraphicsItem* parent = 0);
>>>>>>> 85cdf7b5c2fa4321352667f886d01e7d69b95ab6
};


class Active_block: public Block
{
public:
    Active_block(pair position, QGraphicsItem* parent = 0);
};


class Special_block_above: public Block
{
public:
    Special_block_above(pair position, QGraphicsItem* parent = 0);
};


class Special_block_below: public Block
{
public:
    Special_block_below(pair position, QGraphicsItem* parent = 0);
};

class Activated_block: public Block
{
public:
    Activated_block(pair position, QGraphicsItem* parent = 0);
};

class End_block: public Block
{
public:
    End_block(pair position, QGraphicsItem* parent = 0);
};

#endif // BLOCKS_H
