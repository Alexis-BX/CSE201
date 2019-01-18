#ifndef PROJECTILES_H
#define PROJECTILES_H
#include "gprojectile.h"

class Player_projectile_1 : public GProjectile
{
public:
    Player_projectile_1(QPoint position, Direction direction, int character_size_x, double speed_multiplier = 1);
};

class Player_projectile_2 : public GProjectile
{
public:
    Player_projectile_2(QPoint position, Direction direction, int character_size_x, double speed_multiplier = 1);
};

class Player_projectile_3 : public GProjectile
{
public:
    Player_projectile_3(QPoint position, Direction direction, int character_size_x, double speed_multiplier = 1);
};

class Enemy_projectile_1 : public GProjectile
{
public:
    Enemy_projectile_1(QPoint position, Direction direction, int character_size_x, double speed_multiplier = 1);
};



#endif // PROJECTILES_H
