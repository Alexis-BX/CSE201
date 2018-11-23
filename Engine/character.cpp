#include "character.h"

Character::Character(pair position, pair size, State state, pair speed):
      Object (position, size, state)
{
    this->speed = speed;
}

Character::Character(pair position, pair size, State state):
    Object (position, size, state)
{
    pair speed;
    speed.x = 0;
    speed.y = 0;
    this->speed = speed;
}
