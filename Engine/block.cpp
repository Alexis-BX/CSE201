#include "block.h"

Block::Block(pair position, pair size, Block_type type, Block_state state, Block_texture texture) :
     Dead(position, size)
{

    this->position = position;
    this->size = size;
    this->state = state;
    this->type = type;
    this->texture = texture;
}

void Block::hit_block() //Damage the block, from initial to damaged, from damaged to dead
{
    if (state == initial){
        state = damaged;
    }
    if (state == damaged){
        state = dead;
    }
};

void Block::destroy_block() //Destroy directly the block
{
    state = dead;
};
