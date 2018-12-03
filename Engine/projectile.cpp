#include "projectile.h"

Projectile::Projectile(pair position, pair speed, Projectile_state state, Projectile_type type) :
     Dead(position, size)
{   //initialisation
    this -> speed = speed;
    this -> state = state;
    this -> type = type;

    //initializing life and size of projectile depending on it's type
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
    //linear direction for smoke and baguette prjectile
    if (type == smoke || type == baguette){
        position.x += speed.x;
        position.y += speed.y;
    }

    // if type == wine: mario throw bottle of wine down in diagonal
    else {
        position.x += 2;
        position.y -= 1;
    }

    life -= 1; //at each next frame, life of projectile diminishes by 1
    if (life == 0){
        state = Projectile_state{dead}; //if projectile have no more life, projectile change state from alive to dead
    }
}

void Projectile::hit(Projectile_state state) //if porjectile is hit by something it changes state to dead
{
    state = dead;
}

void Projectile::explode() //if we want, the projectile can explode before changing state to vanish or dead
{
    size.x *= 2;
    size.y *= 2;
    if (state == alive){
        state = vanish;
    }
    else {
        state = dead;
    }
}











