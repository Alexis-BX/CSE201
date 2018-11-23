#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "dead.h"

class Collectable: public Dead
{

public:

    Collectable(pair position, pair size, State state);

};

#endif // COLLECTABLE_H
