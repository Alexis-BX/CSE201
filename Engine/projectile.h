#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "dead.h"


// ALL DIFFERENT TYPES OF PROJECTILES WILL JUST BE DIFFERENT DUE TO THEIR STATE, THERE
// IS NO NEED TO CREATE SUB CLASSES OF PROJECTILES

class Projectile: public Dead
{

public:

    pair speed;

    int life;

    Projectile(pair position, pair size, State state, pair speed, int life);

    void next_frame();

    //bool die_progressively(int life, pair position, pair size, pair direction);

    //bool explode(pair size);


};

#endif // PROJECTILE_H
