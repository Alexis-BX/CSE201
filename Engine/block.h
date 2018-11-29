#ifndef BLOCK_H
#define BLOCK_H

#include "dead.h"

enum Block_type
{
    permanent,
    active,
    alive
};

enum Block_state
{
    dead, // the block is dead and vanishes
    initial, //initial state of the block
    damaged, //the block is damaged (it has half life basically and the graphics change)
    operative, // the block can  be used to pop up coins for instance
    inoperative, // the block cannot be used anymore but remains there as a permanent block
};

enum Block_texture
{
    brick // graphics texture of the blocks
};

class Block: public Dead
{
public:

    Block(pair position, pair size, Block_type type = Block_type{permanent}, Block_state state = Block_state{dead},
          Block_texture texture = Block_texture{brick});

    Block_type type;
    Block_state state;
    Block_texture texture;

    void hit_block();
    void destroy_block();
};

#endif // BLOCK_H
