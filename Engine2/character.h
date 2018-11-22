#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"

class Character : public Object
{
public:
    Character();
    int speed = 0;
    void set_speed(int new_speed);
    int get_speed();

};

#endif // CHARACTER_H
