#ifndef TEXTURE_H
#define TEXTURE_H

#include "global.h"

enum Object_texture
{
    basic_player,
    blocks,
    small_collectable,
    big_collectable,
    power_ups,
    enemy_1,
    projectiles,
    projectile_vanish_effect,
    object_texture_count

};

enum Backgrounds{
    Tsky,
    Tmonument,
    Tbuildings
};

enum Textures
{
    main_texture, troll_texture_1,
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

    //This is a vector of stings that holds the names of the folders for each texture
    std::vector<std::string> names_background;

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

    //Define the backgrounds
    void define_background();

    // Method that return the path to the image of a certain object texture in the current texture
    const char* get_path_to(Object_texture ojb_tex);

    // Method that return the path to a background
    const char* get_path_to(Backgrounds bg);

    //Method that returns the QPixmap array of a sprite animation
    std::vector<QPixmap> get_qpixmap_of(Object_texture sheet, int start=0, int length=1, int size=18);
};



#endif // TEXTURE_H
