#include "projectiles.h"
#include "global.h"
#include "texture.h"
#include <QtDebug>

Player_projectile_1::Player_projectile_1(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x, pair{18,5})
{
    type = baguette;

    life = 1000;

    speed = pair{velocity*((direction) ? 1 : -1), 0};

    setPixmap(QPixmap(gtexture->get_path_to(player_projectile_1)));
}

Player_projectile_2::Player_projectile_2(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x, pair{18,18})
{
    type = wine;

    life = 400;

    speed = pair{velocity * ((direction) ? 1 : -1), 0};

    setPixmap(QPixmap(gtexture->get_path_to(enemy_projectile_1)));
}

Player_projectile_3::Player_projectile_3(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x, pair{18,18})
{
    type = pot;

    life = 50000;

    speed = pair{velocity * ((direction) ? 1 : -1), velocity};

    setPixmap(QPixmap(gtexture->get_path_to(player_projectile_2)));
}

Enemy_projectile_1::Enemy_projectile_1(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x, pair{18,18})
{
    type = smoke;

    life = 200000;

    speed = pair{velocity * ((direction) ? 1 : -1), -velocity + 3};

    setPixmap(QPixmap(gtexture->get_path_to(player_projectile_3)));
}
