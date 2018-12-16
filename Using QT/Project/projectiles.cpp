#include "projectiles.h"

Player_projectile_1::Player_projectile_1(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x, baguette)
{

}

Player_projectile_2::Player_projectile_2(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x, wine)
{

}

Player_projectile_3::Player_projectile_3(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x, pot)
{

}

Enemy_projectile_1::Enemy_projectile_1(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x, smoke)
{

}
