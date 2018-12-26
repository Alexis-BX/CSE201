#include "collectables.h"
#include "global.h"
#include "texture.h"
#include <QtDebug>

Small_collectable::Small_collectable(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = cheese;
    state = immortal;
    speed = pair{0,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}

Big_collectable::Big_collectable(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = star;
    state = immortal;
    speed = pair{0,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}

Power_up_1::Power_up_1(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = mushroom;
    state = decaying;
    life = 100;
    speed = pair{2,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}


Power_up_2::Power_up_2(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y, pair{18,18})
{
    type = eclair;
    state = immortal;
    speed = pair{0,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}
