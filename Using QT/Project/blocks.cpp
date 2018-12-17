#include "blocks.h"

Base_block::Base_block(pair position) : Block(position,permanent,brick,initial)
{

}


Breakable_block::Breakable_block(pair position) : Block(position,breakable,crate,initial)
{

}

Active_block::Active_block(pair position) : Block(position,active,question_mark,initial)
{

}

Special_block_above::Special_block_above(pair position) : Block(position,permanent,grass,initial)
{

}

Special_block_below::Special_block_below(pair position) : Block(position,permanent,dirt,initial)
{

}
