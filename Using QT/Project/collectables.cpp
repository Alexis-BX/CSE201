#include "listheaders.h"

Small_collectable::Small_collectable(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = cheese;
    state = immortal;
    speed = pair{0,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}

/*Big_collectable::Big_collectable(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = star;
    state = immortal;
    speed = pair{0,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}*/

Power_up_1::Power_up_1(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = eclair;
    state = decaying;
    life = 100;
    speed = pair{2,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);

    set_movement();
}

Power_up_2::Power_up_2(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = croissant;
    state = immortal;
    speed = pair{2,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}

Power_up_3::Power_up_3(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = chocolatine;
    state = immortal;
    speed = pair{2,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}

Power_up_4::Power_up_4(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = mini_eiffel;
    state = immortal;
    speed = pair{2,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}
Power_up_5::Power_up_5(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = glass_wine;
    state = immortal;
    speed = pair{2,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}
Power_up_6::Power_up_6(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = mushroom;
    state = immortal;
    speed = pair{0,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);

    set_movement();
}

Power_up_7::Power_up_7(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = coin;
    state = immortal;
    speed = pair{0,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);
}


Power_up_8::Power_up_8(pair position, int creator_object_size_y):
    Collectable(position, creator_object_size_y)
{
    type = star;
    state = immortal;
    speed = pair{3,0};
    setPixmap(gtexture->get_qpixmap_of(power_ups,type)[0]);

    //set_movement();
}
