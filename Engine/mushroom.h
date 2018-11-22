#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <string>
#include "collectibles.h"
#include "player.h"

class Mushroom: public Collectibles
{
public:
    Mushroom(pr size, pr position, enum state);
    void superpower(pr size); //if the player take a mushroom it doubles size except if he is already big

};

#endif // MUSHROOM_H
