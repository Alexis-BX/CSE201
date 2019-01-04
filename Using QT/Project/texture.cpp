#include "listheaders.h"

Texture::Texture()
{
    path_to_textures = ":/Images/Textures/";

    path_to_backgrounds = ":/Images/Backgrounds/";

    current_texture = main_texture;

    current_background = main_background;

    define_main_texture();

    define_main_background();
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

    texture_temp[basic_player] = "character22.12";

    texture_temp[blocks] = "blocks";

    texture_temp[small_collectable] = "small_cheese";

    texture_temp[big_collectable] = "big_cheese";

    texture_temp[power_ups] = "power_ups";

    texture_temp[enemy_1] = "thief_walking_casual";

    texture_temp[projectiles] = "projectiles";

    texture_temp[projectile_vanish_effect] = "explosion";

    std::vector<std::string> x;

    while( object_image_from_texure.size() <= main_texture)
    {
        object_image_from_texure.push_back(x);
    }

    object_image_from_texure[main_texture] = texture_temp;

}

void Texture::define_main_background()
{
    while(background_names.size() <= main_background)
    {
        background_names.push_back("");
    }

    background_names[main_background] = "Main_background/";

    std::vector<std::string> background_temp;

    while( background_temp.size() < background_texture_count)
    {
        background_temp.push_back("");
    }

    background_temp[background_far] = "bg";

    background_temp[background_middle] = "eiffel";

    std::vector<std::string> x;

    while( background_image_from_background.size() <= main_background)
    {
        background_image_from_background.push_back(x);
    }

    background_image_from_background[main_background] = background_temp;

    //loading different buildings

    std::vector<std::string> background_close_temp;

    while( background_close_temp.size() < amount_close_backgrounds)
    {
        background_close_temp.push_back("");
    }

    for (int i=0; i<amount_close_backgrounds; i++)
    {
        background_close_temp[i] = "building" + std::to_string(i+1);
    }

    while( background_image_from_background_close.size() <= main_background)
    {
        background_image_from_background_close.push_back(x);
    }

    background_image_from_background_close[main_background] = background_close_temp;

}

const char* Texture::get_path_to(Object_texture ojb_tex)
{
    return (path_to_textures+texture_names[current_texture]+object_image_from_texure[current_texture][ojb_tex]+".png").c_str();
}

const char* Texture::get_path_to(Background_texture bg_tex)
{
    if (bg_tex == background_close)
    {
        int pos = (std::time(nullptr))%background_image_from_background_close[current_background].size();
        return (path_to_backgrounds+background_names[current_background]+background_image_from_background_close[current_background][pos]+".png").c_str();
    }
    return (path_to_backgrounds+background_names[current_background]+background_image_from_background[current_background][bg_tex]+".png").c_str();
}

std::vector<QPixmap> Texture::get_qpixmap_of(Object_texture sheet, int start, int length, int size)
{
    QPixmap img(get_path_to(sheet));

    int w = img.width()/size;

    int i{start%w},j{start/w};

    std::vector<QPixmap> res(length);

    for (int k=0; k<length; k++)
    {
        res[k] = img.copy(((i+k)%w)*size, (j+(i+k)/w)*size, size, size);
    }

    return res;
}
