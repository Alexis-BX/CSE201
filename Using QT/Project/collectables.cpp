#include "collectables.h"
#include "global.h"
#include "texture.h"
#include <QtDebug>

Small_collectable::Small_collectable(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = coin;
    state = immortal;
    speed = pair{0,0};
    setPixmap(QPixmap(gtexture->get_path_to(small_collectable)));
}

Big_collectable::Big_collectable(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = star;
    state = immortal;
    speed = pair{0,0};
    setPixmap(QPixmap(gtexture->get_path_to(big_collectable)));
}

Power_up_1::Power_up_1(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = mushroom;
    state = decaying;
    life = 100;
    speed = pair{2,0};
<<<<<<< HEAD
    sprite = gtexture->get_qpixmap_of(power_ups, type);
    setPixmap(sprite[0]);
=======
    setPixmap(QPixmap(gtexture->get_path_to(power_up_1)));
>>>>>>> be8dc67cd71c413ceaa2161fffdae1a0e6cada01
}


Power_up_2::Power_up_2(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = eclair;
    state = immortal;
    speed = pair{0,0};
<<<<<<< HEAD
    sprite = gtexture->get_qpixmap_of(power_ups, type);
    setPixmap(sprite[0]);
=======
    setPixmap(QPixmap(gtexture->get_path_to(power_up_2)));
>>>>>>> be8dc67cd71c413ceaa2161fffdae1a0e6cada01
}
