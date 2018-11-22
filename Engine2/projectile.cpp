#include "projectile.h"

Projectile::Projectile(int speed, std::pair<int, int> direction, int life) : Dead(position, size)
{
    this -> speed = speed;
    this -> direction = direction;
    this -> life = life;

}

Projectile::~Projectile()
{
    delete position;
    delete size;
    delete life;
    delete speed;
    delete direction;
}

void Projectile::next_pos(std::pair<int,int> position, int speed, std::pair<int,int> direction)
{
//Goal of this method is to update the position of the projectile
    // for now linear direction no parabola

    int x_pos = position.first;
    int y_pos = position.second;
    int x_dir = direction.first;
    int y_dir = direction.second;
    x_pos = x_pos + speed*x_dir;
    y_pos = y_pos + speed*y_dir;
    position = std::make_pair(x_pos,y_pos);
}

bool Projectile::explode(std::pair<int,int> size)
{
//We use this method to make a projectile explode, it doubles size and then dissapears using the destroctor
// must decide when we use explode either at the end of life of projectile or when touches smt TO DO

    size.first *= 2;
    size.second *= 2;
    size.first *= 2;
    size.second *= 2;
    return false; //the destructor of the game state will make it disappear
}

bool die_progressively(int life, std::pair<int,int> position, std::pair<int,int> size)
{
    for
}












