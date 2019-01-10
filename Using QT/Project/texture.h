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

enum Background_texture
{
    background_far,
    background_middle,
    background_close,
    background_texture_count
};


class Texture
{

public:

    Texture();

    //Attributes

    // This will store which texture is currently being used
    QString current_texture2;
    QString current_background2;

    //This is a string with the path to the texture folder
    QString path_to_textures2 = ":/Images/Textures/";
    QString path_to_backgrounds2 = ":/Images/Backgrounds/";

    /***
    This is a vector of vectors of strings and so object_image_from_texure[texture]
    is a vectore of strings with the names of the png files for each type of object
    that can be accessed by using object_image_from_texure[texture][obj_texture]
    **/
    QMap<QString,QList<QString>> object_image_from_texure2;
    QMap<QString,QList<QString>> background_image_from_background2;
    QMap<QString,QList<QString>> background_image_from_background_close2;

    void read_texture_from_file(QString filename);

    void read_background_from_file(QString filename, int amount_close_backgrounds = 2);

    // Method that return the path to the image of a certain object texture in the current texture
    QString get_path_to(Object_texture ojb_tex);

    // Method that return the path to a background
    QString get_path_to(Background_texture bg_tex);

    //Method that returns the QPixmap array of a sprite animation
    std::vector<QPixmap> get_qpixmap_of(Object_texture sheet, int start=0, int length=1, int size=18);
};



#endif // TEXTURE_H
