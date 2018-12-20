#include "texture.h"
#include <QDebug>


Texture::Texture()
{
    path_to_textures = ":/Images/Textures/";

    current_texture = main_texture;

    define_main_texture();

    define_troll_texture_1();
}

void Texture::define_main_texture()
{
    while(texture_names.size() <= main_texture)
    {
        texture_names.push_back("");
    }

    texture_names[main_texture] = "Main_texture/";

    std::vector<std::string> texture_temp;

    while( texture_temp.size() < object_texture_count)
    {
        texture_temp.push_back("");
    }

    texture_temp[basic_player] = "SpriteSheet13.12.png";

    texture_temp[base_block_1] = "ground1.png";

    texture_temp[base_block_2] = "ground3.png";

    texture_temp[breakable_block] = "break0.png";

    texture_temp[active_block_1] = "question1.png";

    texture_temp[active_block_2] = "question0.png";

    texture_temp[special_block_above] = "grass.png";

    texture_temp[special_block_below] = "dirt.png";

    texture_temp[small_collectable] = "cheese.png";

    texture_temp[big_collectable] = "star.png";

    texture_temp[power_up_1] = "mushroom.png";

    texture_temp[power_up_2] = "eclair.png";

    texture_temp[enemy_1] = "enemy.png";

    texture_temp[player_projectile_1] = "baguette.png";

    texture_temp[player_projectile_2] = "wine.png";

    texture_temp[player_projectile_3] = "face.png";

    texture_temp[enemy_projectile_1] = "smoke.png";

    texture_temp[projectile_vanish_effect] = "explosion.png";

    std::vector<std::string> x;

    while( object_image_from_texure.size() <= main_texture)
    {
        object_image_from_texure.push_back(x);
    }

    object_image_from_texure[main_texture] = texture_temp;

}

void Texture::define_troll_texture_1()
{
    while(texture_names.size() <= troll_texture_1)
    {
        texture_names.push_back("");
    }

    texture_names[troll_texture_1] = "Troll_texture_1/";

    std::vector<std::string> texture_temp;

    while( texture_temp.size() < object_texture_count)
    {
        texture_temp.push_back("");
    }

    texture_temp[basic_player] = "face.png";

    texture_temp[base_block_1] = "face.png";

    texture_temp[base_block_2] = "face.png";

    texture_temp[breakable_block] = "face.png";

    texture_temp[active_block_1] = "face.png";

    texture_temp[active_block_2] = "face.png";

    texture_temp[special_block_above] = "face.png";

    texture_temp[special_block_below] = "face.png";

    texture_temp[small_collectable] = "face.png";

    texture_temp[big_collectable] = "face.png";

    texture_temp[power_up_1] = "face.png";

    texture_temp[power_up_2] = "face.png";

    texture_temp[enemy_1] = "face.png";

    texture_temp[player_projectile_1] = "face.png";

    texture_temp[player_projectile_2] = "face.png";

    texture_temp[player_projectile_3] = "face.png";

    texture_temp[enemy_projectile_1] = "face.png";

    texture_temp[projectile_vanish_effect] = "face.png";

    std::vector<std::string> x;

    while( object_image_from_texure.size() <= troll_texture_1)
    {
        object_image_from_texure.push_back(x);
    }

    object_image_from_texure[troll_texture_1] = texture_temp;
}

const char* Texture::get_path_to(Object_texture ojb_tex)
{
    return (path_to_textures+texture_names[current_texture]+object_image_from_texure[current_texture][ojb_tex]).c_str();
}
