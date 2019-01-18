 #ifndef TYPES_STATES_TEXTURES_H
#define TYPES_STATES_TEXTURES_H

enum Block_type
{
    permanent,
    active,
    breakable
};

//graphics textures of the blocks
//their value being their starting position in the sprite sheet
enum Block_texture
{
    brick,
    grass,
    dirt,
    question_mark,
    activated = 5,
    crate = 6,
    crate_2 = 8,
    crate_3 = 11,
    flag_pole=18,
    flag,
    tube = 6,
    tube_up,
    tube_down
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
    decaying, //means it has a life and can die even though it hasn't been eaten
    immortal //the collectable doesn't have a life but dissapear whenever the player use it (eat it), ie whenever there is a collision with the player
};

enum Collectable_type // shows all kinds of collectables that can appear
{
    eclair, //mario get a new projectile
    croissant, //mario get slower
    chocolatine, //mario grows two times bigger
    mini_eiffel, //mario invincible to the projectile
    glass_wine, //mario grows two timers bigger and blinks
    mushroom, //mario goes two times faster
    coin, //to get the points
    star, //mario blinks
    cheese //Mario is invincible to everything (blocks and projectiles)
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
    wine, //player's projectile : downward attack to kill the thief roding right to left for example, projectile you get after taking a msuhroom maybe
    baguette=4, //player's projectile : horizantal attack
    smoke=8, //enemy's projectile : horizantal attack
    pot=12
};

enum Enemy_type
{
    basic,
    cloud,
    smoker

};

enum Enemy_state
{
    passiv,
    aggressiv
};

enum Enemy_texture
{
    normal
};

enum screne_layers
{
    layer_background_far,
    layer_background_middle,
    layer_background_close,
    layer_block,
    layer_collectable,
    layer_projectile,
    layer_enemy,
    layer_button,
    layer_player
};

enum controls
{
    control_player,
    control_help,
    control_menu,
    control_world,
    control_game_over,
    control_win
};

#endif // TYPES_STATES_TEXTURES_H
