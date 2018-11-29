#ifndef COLLECTABLE_H
#define COLLECTABLE_H 

#include "dead.h"

enum Collectable_state { used, unused };                       // the collectable can either be used by the player or not

enum Collectable_type { star, mushroom, eclair };              // shows all kinds of collectables that can appear

class Collectable: public Dead
{

public:

    Collectable(pair position, pair size, Collectable_state state, Collectable_type type);  // constructor that initializes all aspects of collectable 

	Collectable_state state;           // shows if the collectable is used or unused

	Collectable_type type;             // shows the kind of collectable the player meets

};

#endif // COLLECTABLE_H
