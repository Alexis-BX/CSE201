#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"

class Character : public Object
{
public:
    pair speed;
    int hp;

    Character(pair position, pair size, pair speed, int hp);

    Character(pair position, pair size, int hp);

};

#endif // CHARACTER_H
