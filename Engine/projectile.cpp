#include "projectile.h"

Projectile::Projectile(pair position, pair speed, Projectile_state state, Projectile_type type) :
     Dead(position, size)
{
    this -> speed = speed;
    this -> state = state;
    this -> type = type;
    if (type == baguette){
        life = 100;
        size.x = 40;
        size.y = 10;
    }
    if (type == smoke){
        life = 200;
        size.x = 18;
        size.y = 18;
    }
    if (type == wine){
        life = 50;
        size.x = 20;
        size.y = 10;
    }
}

void Projectile::next_frame()
{
//Goal of this method is to update the position of the projectile
    // for now linear direction no parabola
    if (type == smoke || type == baguette){
        position.x += speed.x;
        position.y += speed.y;
    }

    //if type == wine: mario throw bottle of wine down in diagonal
    else {
        position.x += 2;
        position.y -= 1;
    }

    life -= 1;
    if (life == 0){
        state = Projectile_state{dead};
    }
}

void Projectile::hit(Projectile_state state)
{
    state = dead;

}

void Projectile::explode()
{
    //do when you have collision
}





/**
bool Projectile::explode(pair size)
{
//We use this method to make a projectile explode, it doubles size and then dissapears using the destroctor
// must decide when we use explode either at the end of life of projectile or when touches smt TO DO

    size.x *= 2;
    size.y *= 2;``

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











