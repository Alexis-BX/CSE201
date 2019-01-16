#include "listheaders.h"

Player_projectile_1::Player_projectile_1(pair position, bool direction, int character_size_x, double speed_multiplier):
    Projectile(position, direction, character_size_x, baguette)
{
    life = 1000;

    speed = pair{speed_multiplier*velocity*((direction) ? 1 : -1), 0};
}

Player_projectile_2::Player_projectile_2(pair position, bool direction, int character_size_x, double speed_multiplier):
    Projectile(position, direction, character_size_x,wine)
{
    life = 400;

    speed = pair{speed_multiplier*velocity * ((direction) ? 1 : -1), 0};
}

Player_projectile_3::Player_projectile_3(pair position, bool direction, int character_size_x, double speed_multiplier):
    Projectile(position, direction, character_size_x,pot)
{
    life = 50000;

    speed = pair{speed_multiplier*velocity * ((direction) ? 1 : -1), speed_multiplier*velocity};
}

Enemy_projectile_1::Enemy_projectile_1(pair position, bool direction, int character_size_x, double speed_multiplier):
    Projectile(position, direction, character_size_x, smoke)
{
    life = 20000;

    speed = pair{speed_multiplier*velocity * ((direction) ? 1 : -1), 0};
}
