#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <string>
#include "dead.h"


// ALL DIFFERENT TYPES OF PROJECTILES WILL JUST BE DIFFERENT DUE TO THEIR STATE, THERE
// IS NO NEED TO CREATE SUB CLASSES OF PROJECTILES
class Projectile: public Dead
{
public:
    int speed;
    pair direction;
    int life;

    Projectile(pair position, pair size, int speed, pair direction, int life);

    void next_pos(pair position, int speed, pair direction);

    bool die_progressively(int life, pair position, pair size, pair direction);

    bool explode(pair size);


};

#endif // PROJECTILE_H
