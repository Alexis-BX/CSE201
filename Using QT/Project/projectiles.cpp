#include "listheaders.h"

Player_projectile_1::Player_projectile_1(pair position, bool direction, int character_size_x, double speed_multiplier):
    Projectile(position, direction, character_size_x, pair{18,18})
{
    type = baguette;

    life = 1000;

    speed = pair{velocity*((direction) ? 1 : -1), 0};

    setPixmap(gtexture->get_qpixmap_of(projectiles, type)[img_count]);
}

Player_projectile_2::Player_projectile_2(pair position, bool direction, int character_size_x, double speed_multiplier):
    Projectile(position, direction, character_size_x, pair{18,18})
{
    type = wine;

    life = 400;

    speed = pair{velocity * ((direction) ? 1 : -1), 0};

    setPixmap(gtexture->get_qpixmap_of(projectiles, type)[img_count]);
}

Player_projectile_3::Player_projectile_3(pair position, bool direction, int character_size_x, double speed_multiplier):
    Projectile(position, direction, character_size_x, pair{18,18})
{
    type = pot;

    life = 50000;

    speed = pair{velocity * ((direction) ? 1 : -1), velocity};

    setPixmap(gtexture->get_qpixmap_of(projectiles, type)[img_count]);
}

Enemy_projectile_1::Enemy_projectile_1(pair position, bool direction, int character_size_x, double speed_multiplier):
    Projectile(position, direction, character_size_x, pair{18,18})
{
    type = smoke;

    life = 20000;

    speed = pair{velocity * ((direction) ? 1 : -1), 0};

    setPixmap(gtexture->get_qpixmap_of(projectiles, type)[img_count]);
}
