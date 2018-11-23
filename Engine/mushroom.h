#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "collectable.h"

class Mushroom: public Collectable
{

public:

    int life;

    Mushroom(pair size, pair position, State state);

    void superpower(pair size); //if the player take a mushroom it doubles size except if he is already big
   

};

#endif // MUSHROOM_H
