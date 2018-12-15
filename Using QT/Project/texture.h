#ifndef TEXTURE_H
#define TEXTURE_H
#include "types_states_textures.h"
#include "cstring"
#include "string"
#include "vector"

enum Object_texture
{
    basic_player = 0,
    base_block_1 = 1,
    base_block_2 = 2,
    breakable_block = 3,
    active_block_1 = 4,
    active_block_2 = 5,
    special_block_above = 6,
    special_block_below = 7,
    small_collectable = 8,
    big_collectable = 9,
    power_up_1 = 10,
    power_up_2 = 11,
    enemy_1 = 12,
    player_projectile_1 = 13,
    player_projectile_2 = 14,
    player_projectile_3 = 15,
    enemy_projectile_1 = 16,
    projectile_vanish_effect = 17,
    object_texture_count = 18,

};

enum Textures
{
    main_texture = 0,
    troll_texture_1,
};

/**
 * This class was implemented to facilitate changes of texture
 */



class Texture
{

public:

    Texture();


    //Attributes

    // This will store which texture is currently being used
    Textures current_texture;

    //This is a string with the path to the texture folder
    std::string path_to_textures;

    //This is a vector of stings that holds the names of the folders for each texture
    std::vector<std::string> texture_names;

    /***

    This is a vector of vectore of strings and so object_image_from_texure[texture]
    is a vectore of strings with the names of the png files for each type of object
    that can be accessed by using object_image_from_texure[texture][obj_texture]

    **/
    std::vector<std::vector<std::string>> object_image_from_texure;


    //Define main texture
    void define_main_texture();


    //Define troll texture
    void define_troll_texture_1();

    // Method that return the path to the image of a certain object texture in the current texture
    const char* get_path_to(Object_texture ojb_tex);

};



#endif // TEXTURE_H
