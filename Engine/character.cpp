#include "character.h"

Character::Character(pair position, pair size, pair speed,int hp):
      Object (position, size)
{
    this->speed = speed;
    this->hp =hp;
}

Character::Character(pair position, pair size,int hp):
    Object (position, size)
{
    pair speed;
    speed.x = 0;
    speed.y = 0;
    this->speed = speed;
    this->hp = hp;
}
