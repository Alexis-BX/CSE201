#ifndef PROJECTILES_H
#define PROJECTILES_H
#include "projectile.h"

class Player_projectile_1 : public Projectile
{
public:
    Player_projectile_1(pair position, bool direction, int character_size_x, double speed_multiplier = 1);
};

class Player_projectile_2 : public Projectile
{
public:
    Player_projectile_2(pair position, bool direction, int character_size_x, double speed_multiplier = 1);
};

class Player_projectile_3 : public Projectile
{
public:
    Player_projectile_3(pair position, bool direction, int character_size_x, double speed_multiplier = 1);
};

class Enemy_projectile_1 : public Projectile
{
public:
    Enemy_projectile_1(pair position, bool direction, int character_size_x, double speed_multiplier = 1);
};



#endif // PROJECTILES_H
