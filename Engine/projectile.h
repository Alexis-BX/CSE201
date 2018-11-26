#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "dead.h"


// ALL DIFFERENT TYPES OF PROJECTILES WILL JUST BE DIFFERENT DUE TO THEIR STATE, THERE
// IS NO NEED TO CREATE SUB CLASSES OF PROJECTILES

enum Projectile_state
{
    alive,
    vanish,
    dead
};

enum Projectile_type
{
    baguette, //player projectile
    smoke,
    wine
};

class Projectile: public Dead
{

public:

    pair speed;

    int life;

    Projectile_state state;

    Projectile_type type;

    Projectile(pair position, pair speed, Projectile_state state = Projectile_state{alive}, Projectile_type type = Projectile_type{baguette});

    void next_frame();

    void die(Projectile_state state);

    void explode();

    //bool die_progressively(int life, pair position, pair size, pair direction);

    //bool explode(pair size);


};

#endif // PROJECTILE_H
