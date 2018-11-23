#include "projectile.h"

Projectile::Projectile(pair position, pair size, State state, pair speed, int life) : Dead(position, size, state)
{
    this -> speed = speed;
    this -> life = life;
}

void Projectile::next_frame()
{
//Goal of this method is to update the position of the projectile
    // for now linear direction no parabola
    position.x += speed.x;
    position.y += speed.y;

}


/**
bool Projectile::explode(pair size)
{
//We use this method to make a projectile explode, it doubles size and then dissapears using the destroctor
// must decide when we use explode either at the end of life of projectile or when touches smt TO DO

    size.x *= 2;
    size.y *= 2;
    size.x *= 2;
    size.y *= 2;
    return false; //the destructor of the game state will make it disappear //FIX THIS: EXPLOSION ANIMATION
}

bool Projectile::die_progressively()
{
    while (life>0) {
        life-=life;
        next_frame();
        size.x -= 1;
        size.y -= 1;
    return false; //game state must make it disappear
    }
}
**/











