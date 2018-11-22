#include "character.h"

Character::Character(pair position, pair size, State state, int speed, pair
      direction): 
      Object (position, size, state)
{
   this->speed = speed;  
   this->direction = direction; 
}
