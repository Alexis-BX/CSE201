#include "collectables.h"
#include "global.h"
#include "texture.h"
#include <QtDebug>

Collectable_1::Collectable_1(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = coin;
    state = immortal;
    speed = pair{0,0};
    setPixmap(QPixmap(gtexture->get_path_to(small_collectable)));
}

Collectable_2::Collectable_2(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = star;
    state = immortal;
    speed = pair{0,0};
    setPixmap(QPixmap(gtexture->get_path_to((big_collectable))));
}

Collectable_3::Collectable_3(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = mushroom;
    state = decaying;
    life = 100;
    speed = pair{2,0};
    setPixmap(QPixmap(gtexture->get_path_to(power_up_1)));
}


Collectable_4::Collectable_4(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = eclair;
    state = immortal;
    speed = pair{0,0};
    setPixmap(QPixmap(gtexture->get_path_to(power_up_2)));
}
