#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "dead.h"

enum Collectable_state { used, unused };

enum Collectable_type { star, mushroom, eclair };

class Collectable: public Dead
{

public:

    Collectable(pair position, pair size, Collectable_state state, Collectable_type type);

	Collectable_state state;

	Collectable_type type;

};

#endif // COLLECTABLE_H
