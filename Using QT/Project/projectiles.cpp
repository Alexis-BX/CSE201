#include "listheaders.h"

Player_projectile_1::Player_projectile_1(QPoint position, Direction direction, int character_size_x, double speed_multiplier):
    GProjectile(baguette, QPoint(speed_multiplier*velocity*((direction == Right) ? 1 : -1), 0),
                QPoint(position.rx() + ((direction == Right) ? character_size_x : 0),position.ry()))
{
    life = 1000;
}

Player_projectile_2::Player_projectile_2(QPoint position, Direction direction, int character_size_x, double speed_multiplier):
    GProjectile(wine, QPoint(speed_multiplier*velocity*((direction == Right) ? 1 : -1), 0),
                QPoint(position.rx() + ((direction == Right) ? character_size_x : 0),position.ry()))
{
    life = 400;
}

Player_projectile_3::Player_projectile_3(QPoint position, Direction direction, int character_size_x, double speed_multiplier):
    GProjectile(pot, QPoint(speed_multiplier*velocity*((direction == Right) ? 1 : -1), 0),
                QPoint(position.rx() + ((direction == Right) ? character_size_x : 0),position.ry()))
{
    life = 50000;
}

Enemy_projectile_1::Enemy_projectile_1(QPoint position, Direction direction, int character_size_x, double speed_multiplier):
    GProjectile(smoke, QPoint(speed_multiplier*velocity*((direction == Right) ? 1 : -1), 0),
                QPoint(position.rx() + ((direction == Right) ? character_size_x : 0),position.ry()))
{
    life = 20000;
}
