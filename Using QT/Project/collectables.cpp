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
<<<<<<< HEAD
    setPixmap(QPixmap(gtexture->get_path_to(big_collectable)));
=======

    setPixmap(QPixmap(gtexture->get_path_to((big_collectable))));
>>>>>>> f0c8bd9ce3cd2d3fad5530c1438f951f5ec7570d
}

Power_up_1::Power_up_1(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = mushroom;

    state = decaying;

    life = 100;

    speed = pair{2,0};

    setPixmap(QPixmap(gtexture->get_path_to(power_up_1)));
}


Power_up_2::Power_up_2(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = eclair;

    state = immortal;

    speed = pair{0,0};

    setPixmap(QPixmap(gtexture->get_path_to(power_up_2)));
}
