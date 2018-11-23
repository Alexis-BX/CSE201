#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "dead.h"

class Collectibles: public Dead
{

public:

    Collectibles(pair position, pair size, State state);

};

#endif // COLLECTABLE_H
