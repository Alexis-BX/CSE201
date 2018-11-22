#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"

class Character : public Object
{
public:
    pair speed;

    Character(pair position, pair size, State state, int speed, pair direction);
};

#endif // CHARACTER_H
