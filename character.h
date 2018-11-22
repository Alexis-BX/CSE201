#ifndef CHARACTER_H
#define CHARACTER_H

#include <object.h>

class Character : public Object
{
public:
    pr speed;
    void set_speed(pr new_speed);
    pr get_speed();
};

#endif // CHARACTER_H
