#ifndef BAGUETTE_H
#define BAGUETTE_H

#include "projectile.h"

class Baguette: public Projectile
{
public:
    Baguette(pair position, pair size, State state, int speed, pair direction);

};

#endif // BAGUETTE_H
