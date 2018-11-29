#ifndef COLLECTABLE_H
#define COLLECTABLE_H 

#include "dead.h"

enum Collectable_state { used, unused };                       // the collectable can either be used by the player or not

enum Collectable_type { star, mushroom, eclair };              // shows all kinds of collectables that can appear

enum Collectable_texture { same , different };                 // shows if the player meets the same or different collectable

class Collectable: public Dead
{

public:

    Collectable(pair position, pair size, Collectable_state state, Collectable_type type, Collectable_texture texture);  // constructor that initializes all aspects of collectable 

	Collectable_state state;           // shows if the collectable is used or unused

	Collectable_type type;             // shows the kind of collectable the player meets

	Collectable_texture texture;       // the player meets the same or different collectable

};

#endif // COLLECTABLE_H
