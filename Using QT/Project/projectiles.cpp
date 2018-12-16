#include "projectiles.h"
#include "global.h"
#include "texture.h"

Player_projectile_1::Player_projectile_1(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x)
{
    type = baguette;

    life = 1000;

    size = pair{18,5};

    speed = pair{velocity * ((direction) ? 1 : -1), 0};

    setPixmap(QPixmap(gtexture->get_path_to(player_projectile_1)));
}

Player_projectile_2::Player_projectile_2(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x)
{
    type = wine;

    life = 400;

    size = pair {18,18};

    speed = pair{velocity * ((direction) ? 1 : -1), 0};

    setPixmap(QPixmap(gtexture->get_path_to(enemy_projectile_1)));
}

Player_projectile_3::Player_projectile_3(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x)
{
    type = pot;

    life = 50000;

    size = pair{18,18};

    speed = pair{velocity * ((direction) ? 1 : -1), velocity};

    setPixmap(QPixmap(gtexture->get_path_to(player_projectile_2)));
}

Enemy_projectile_1::Enemy_projectile_1(pair position, bool direction, int character_size_x):
    Projectile(position, direction, character_size_x)
{
    type = smoke;

    life = 200000;

    size = pair{18,18};

    speed = pair{velocity * ((direction) ? 1 : -1), -velocity + 3};

    setPixmap(QPixmap(gtexture->get_path_to(player_projectile_3)));
}
