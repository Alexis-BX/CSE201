#ifndef TYPES_STATES_TEXTURES_H
#define TYPES_STATES_TEXTURES_H

enum Block_type
{
    permanent,
    active,
    breakable
};

enum Block_texture
{
    brick, // graphics texture of the blocks
    grass,
    crate,
    question_mark,
    dirt,
    //face
};

enum Block_state
{
    initial, //initial state of the block
    operative // the block can  be used to pop up coins for instance
    //inoperative, // the block cannot be used anymore but remains there as a permanent block
    //damaged, //the block is damaged (it has half life basically and the graphics change)
    //dead, // the block is dead and vanishes
};




enum Collectable_state  // the collectable can either be used by the player or not
{
    used,
    unused
};

enum Collectable_type // shows all kinds of collectables that can appear
{
    coin,
    star,
    mushroom,
    eclair
};

enum Collectable_texture  // shows if the player meets the same or different collectable
{
    same,
    different
};






enum Projectile_state
{
    alive,
    vanish,
    dead //if his life is over or it hit something
};

enum Projectile_type
{
    baguette, //player's projectile : horizantal attack
    smoke, //enemy's projectile : horizantal attack
    wine, //player's projectile : downward attack to kill the thief roding right to left for example, projectile you get after taking a msuhroom maybe
    pot,
};

#endif // TYPES_STATES_TEXTURES_H
