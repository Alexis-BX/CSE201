#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"

class Character : public Object
{
public:
    pair speed;

    Character(pair position, pair size, State state, pair speed);

    Character(pair position, pair size, State state);

};

#endif // CHARACTER_H
